
#include "includes/cub3d.h"

void	ft_debug_print_map(t_data *data)
{
	int	i;

	printf("--- MAP DEBUG ---\n");
	printf("rows: %d | columns: %d\n", data->map.rows, data->map.columns);
	printf("NO: %s\n", data->wall[NO].path ? data->wall[NO].path : "(null)");
	printf("SO: %s\n", data->wall[SO].path ? data->wall[SO].path : "(null)");
	printf("WE: %s\n", data->wall[WE].path ? data->wall[WE].path : "(null)");
	printf("EA: %s\n", data->wall[EA].path ? data->wall[EA].path : "(null)");
	printf("floor: %s\n", data->floor ? data->floor : "(null)");
	printf("celling: %s\n", data->celling ? data->celling : "(null)");
	printf("--- grid ---\n");
	i = 0;
	while (i < data->map.rows)
	{
		printf("[%2d] \"%s\"\n", i, data->map.grid[i]);
		i++;
	}
	printf("-----------------\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_check_parameters(argc, argv, data);
	ft_init_game(data);
	ft_alloc_map(data, argv[1]);
	ft_debug_print_map(data);
	ft_cleanup(data);
	//data->time = my_time();
	//if (win_creation(data) == 1)
	//	return (1);
	//detect_press(data);
	//mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask,
	// 	ft_close_game, data);
	// mlx_hook(data->mlx_win, Expose, ExposureMask,
	//print_pixel(data, 0xFFFFFF);
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->global.mlx_img, 0, 0);
	// 	ft_render_map, data);
	//mlx_loop(data->mlx_ptr);
}


//texture path real
// verif map
// conector map and render
//raytracing
