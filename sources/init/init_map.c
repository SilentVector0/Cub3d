
#include "includes/cub3d.h"

void	ft_check_parameters(int argc, char **argv, t_data *data)
{
	int	arg_len;

	if (argc != 2)
		ft_error_msg("You must provide exactly one map file", data);
	arg_len = ft_strlen(argv[1]);
	if (arg_len < 4 || ft_strncmp(argv[1] + arg_len - 4, ".cub", 4))
		ft_error_msg("Map file must have a .cub extension", data);
}

int	ft_is_config_line(char *line)
{
	if (ft_strlen(line) == 0)
		return (1);
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

void	ft_get_path(t_data *data, char *line, char **path)
{
	int		i;
	int		len;

	i = 0;
	while (line[i] == ' ')
		i++;
	len = ft_strlen(line) - i;
	while (len > 0 && line[len + i - 1] == ' ')
		len--;
	if (len == 0)
		ft_error_msg("Missing texture path", data);
	*path = malloc(len + 1);
	if (!*path)
		ft_error_msg("alloc path fail", data);
	ft_memcpy(*path, line + i, len);
	(*path)[len] = '\0';
}

int	ft_get_nb(t_data *data, char **s, char sep)
{
	int	nb;
	int digits;

	while (**s == ' ')
		(*s)++;
	nb = 0;
	digits = 0;
	while (**s >= '0' && **s <= '9')
	{
		nb = nb * 10 + (**s - '0');
		if (nb > 255)
			ft_error_msg("Invalide color (exepted R,G,B in [0, 255])", data);
		(*s)++;
		digits++;
	}
	while (**s == ' ')
		(*s)++;
	if (digits == 0 || **s != sep)
		ft_error_msg("Invalide color (exepted R,G,B in [0, 255])", data);
	if (sep)
		(*s)++;
	return (nb);
}

void	ft_get_color(t_data *data, char *line, int *color)
{
	char	*s;

	s = line;
	*color = ft_get_nb(data, &s, ',') << 16;
	*color |= ft_get_nb(data, &s, ',') << 8;
	*color |= ft_get_nb(data, &s, '\0');
}

void	ft_is_texture_path(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && !data->wall[NO].path)
		ft_get_path(data, line + 3, &data->wall[NO].path);
	else if (!ft_strncmp(line, "SO ", 3) && !data->wall[SO].path)
		ft_get_path(data, line + 3, &data->wall[SO].path);
	else if (!ft_strncmp(line, "WE ", 3) && !data->wall[WE].path)
		ft_get_path(data, line + 3, &data->wall[WE].path);
	else if (!ft_strncmp(line, "EA ", 3) && !data->wall[EA].path)
		ft_get_path(data, line + 3, &data->wall[EA].path);
	else if (!ft_strncmp(line, "F ", 2) && data->floor == -1)
		ft_get_color(data, line + 2, &data->floor);
	else if (!ft_strncmp(line, "C ", 2) && data->ceiling == -1)
		ft_get_color(data, line + 2, &data->ceiling);
	else
		ft_error_msg("Duplicate texture or color", data);
}

void	ft_config_and_search_map(t_data *data, int fd)
{
	while (1)
	{
		data->first_line = get_next_line(fd);
		if (!data->first_line)
			break ;
		if (ft_strlen(data->first_line) > 0 && data->first_line[ft_strlen(data->first_line) - 1] == '\n')
			data->first_line[ft_strlen(data->first_line) - 1] = '\0';
		if (!ft_is_config_line(data->first_line))
			return ;
		if (ft_strlen(data->first_line) > 0)
			ft_is_texture_path(data, data->first_line);
		free(data->first_line);
	}
	ft_error_msg("No map found in file", data);
}


void	ft_grid_size(t_data *data, int fd)
{
	char	*line;

	data->map.columns = ft_strlen(data->first_line);
	data->map.rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if ((int)ft_strlen(line) > data->map.columns)
			data->map.columns = ft_strlen(line);
		data->map.rows++;
		free(line);
	}
}

void	ft_skip_config_lines(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!ft_is_config_line(line))
		{
			free(line);
			break ;
		}
		free(line);
	}
}

void	ft_alloc_grid(t_data *data, int fd)
{
	char	*line;
	int	i;

	i = 1;
	while (i < data->map.rows)
	{
		data->map.grid[i] = malloc(data->map.columns + 1);
		if (!data->map.grid[i])
			ft_error_msg("Memory allocation failed for row", data);
		ft_memset(data->map.grid[i], ' ', data->map.columns);
		data->map.grid[i][data->map.columns] = '\0';
		line = get_next_line(fd);
		if (!line)
			ft_error_msg("Map corruption", data);
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_memcpy(data->map.grid[i], line, ft_strlen(line));
		free(line);
		i++;
	}
	data->map.grid[i] = NULL;
}

void	ft_build_grid(t_data *data, int fd)
{
	int	i;

	data->map.grid = malloc(sizeof(char *) * (data->map.rows + 1));
	if (!data->map.grid)
		ft_error_msg("Memory allocation failed for grid", data);
	i = 0;
	while (i <= data->map.rows)
		data->map.grid[i++] = NULL;
	data->map.alloc = 1;
	data->map.grid[0] = malloc(data->map.columns + 1);
	if (!data->map.grid[0])
		ft_error_msg("Memory allocation failed for row", data);
	ft_memset(data->map.grid[0], ' ', data->map.columns);
	data->map.grid[0][data->map.columns] = '\0';
	ft_memcpy(data->map.grid[0], data->first_line, ft_strlen(data->first_line));
	ft_alloc_grid(data, fd);
}


void	ft_alloc_map(t_data *data, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	data->current_fd = fd;
	ft_config_and_search_map(data, fd);
	ft_grid_size(data, fd);
	close(fd);
	data->current_fd = -1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	data->current_fd = fd;
	ft_skip_config_lines(fd);
	ft_build_grid(data, fd);
	close(fd);
	data->current_fd = -1;
	data->map.ecart_h = 200 / data->map.rows;
	data->map.ecart_w = 200 / data->map.columns;
}
