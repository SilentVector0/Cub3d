
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

void	ft_grid_size(t_data *data, char *filename)
{
	int		fd;
	int		tmp;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!data->map.rows)
				ft_error_msg("Empty map", data);
			break ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		tmp = ft_strlen(line);
		if (data->map.columns < tmp)
			data->map.columns = tmp;
		free(line);
		data->map.rows++;
	}
	close(fd);
}

void	ft_alloc_rows(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < data->map.rows)
	{
		data->map.grid[i] = ft_calloc(data->map.columns + 1, sizeof(char));
		if (!data->map.grid[i])
			ft_error_msg("Memory allocation failed for row", data);
		line = get_next_line(fd);
		if (!line)
			ft_error_msg("Map corruption", data);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_memcpy(data->map.grid[i], line, ft_strlen(line));
		free(line);
	}
	data->map.grid[i] = NULL;
}

void	ft_verif_map(t_data *data, char	*filename)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!i)
				ft_error_msg("Empty map", data);
			break ;
		}
		if (ft_strlen(line) == 1)
		{
			if (line[0] == '\n')
			{
				i++;
				continue ;
			}
		}
		ft_is_texture_path(line);
		i++;
	}
}

void	ft_get_path(t_data *data, char *line, char *path)
{
	int	i;
	int	len;

	i = 0;
	while (path[i] == ' ')
		i++;
	len = ft_strlen(line) - i;
	path = malloc(len + 1);
	if (!path)
		ft_error_msg("Empty map", data);
}

void	ft_is_texture_path(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && !data->wall[NO].path)
		ft_get_path(data, line + 3, data->wall[NO].path);
	else if (!ft_strncmp(line, "SO ", 3) && !data->wall[SO].path)
		ft_get_path(data, line + 3, data->wall[SO].path);
	else if (!ft_strncmp(line, "WE ", 3) && !data->wall[WE].path)
		ft_get_path(data, line + 3, data->wall[WE].path);
	else if (!ft_strncmp(line, "EA ", 3) && !data->wall[EA].path)
		ft_get_path(data, line + 3, data->wall[EA].path);
	else if (!ft_strncmp(line, "F ", 2) && !data->floor)
		ft_get_path(data, line + 2, data->floor);
	else if (!ft_strncmp(line, "C ", 2) && !data->celling)
		ft_get_path(data, line + 2, data->celling);
}

void	ft_init_map(t_data *data, char *filename)
{
	int		fd;

	ft_verif_map();
	ft_grid_size(data, filename);
	data->map.grid = malloc(sizeof(char *) * (data->map.rows + 1));
	if (!data->map.grid)
		ft_error_msg("Memory allocation failed for grid", data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	ft_alloc_rows(data, fd);
	close(fd);
	data->map.alloc = 1;
}
