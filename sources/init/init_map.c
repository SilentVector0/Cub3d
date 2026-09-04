
#include "includes/cub3d.h"

void	ft_check_parameters(int argc, char **argv, t_data *data)
{
	int	arg_len;

	data->current_fd = -1;
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
	char	*result;

	i = 0;
	while (line[i] == ' ')
		i++;
	len = ft_strlen(line) - i;
	if (ft_strlen(line) > 0  && line[len + i - 1] == '\n')
		len--;
	*path = malloc(len + 1);
	if (!*path)
		ft_error_msg("alloc path fail", data);
	result = *path;
	while (line[i] && line[i] != '\n')
		*result++ = line[i++];
	*result = '\0';
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
	else if (!ft_strncmp(line, "F ", 2) && !data->floor)
		ft_get_path(data, line + 2, &data->floor);
	else if (!ft_strncmp(line, "C ", 2) && !data->celling)
		ft_get_path(data, line + 2, &data->celling);
	else
	{
		free(line);
		ft_error_msg("Duplicate texture", data);
	}
}

char	*ft_config_and_search_map(t_data *data, int fd)
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
			return (line);
		if (ft_strlen(line) > 0)
			ft_is_texture_path(data, line);
		free(line);
	}
	ft_error_msg("No map found in file", data);
	return (NULL);
}


void	ft_grid_size(t_data *data, int fd, char *first_line)
{
	char	*line;

	data->map.columns = ft_strlen(first_line);
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

void	ft_build_grid(t_data *data, int fd, char *first_line)
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
	ft_memcpy(data->map.grid[0], first_line, ft_strlen(first_line));
	free(first_line);
	ft_alloc_grid(data, fd);
}


void	ft_alloc_map(t_data *data, char *filename)
{
	int		fd;
	char	*first_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	data->current_fd = fd;
	first_line = ft_config_and_search_map(data, fd);
	ft_grid_size(data, fd, first_line);
	close(fd);
	data->current_fd = -1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(first_line);
		ft_error_msg("Map couldn't be opened", data);
	}
	data->current_fd = fd;
	ft_skip_config_lines(fd);
	ft_build_grid(data, fd, first_line);
	close(fd);
	data->map.ecart_h = data->global.height / data->map.rows;
	data->map.ecart_w = data->global.width / data->map.columns;
}
