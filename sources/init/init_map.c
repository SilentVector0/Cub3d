#include "includes/cub3d.h"

void	alloc_map(t_map *map, char *file)
{
	char	*lane;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	lane = get_next_line(fd);
	while (lane != NULL)
	{
		map->rows++;
		free(lane);
		lane = get_next_line(fd);
	}
	close(fd);
	map->grid = malloc(sizeof(char *) * map->rows + 1);
	fd = open(file, O_RDONLY);
	lane = get_next_line(fd);
	while (lane != NULL)
	{
		map->grid[i] = lane;
		lane = get_next_line(fd);
		i++;
	}
	close(fd);
}
