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

void	ft_init_map_rows(t_game *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!data->map.rows)
				ft_error_msg("Empty map", data);
			break ;
		}
		free(line);
		data->map.rows++;
	}
	close(fd);
}

void	ft_init_map(t_game *data, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	ft_init_map_rows(data, filename);
	data->map.grid = malloc(sizeof(char *) * (data->map.rows + 1));
	if (!data->map.grid)
		ft_error_msg("Memory allocation failed for grid", data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Map couldn't be opened", data);
	i = 0;
	while (i < data->map.rows)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		data->map.grid[i++] = line;
	}
	data->map.grid[i] = NULL;
	close(fd);
	data->map_alloc = true;
}