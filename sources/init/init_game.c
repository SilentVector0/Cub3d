#include "includes/cub3d.h"

void	ft_img_init(t_image *img)
{
	img->path = NULL;
	img->mlx_img = NULL;
	img->addr = NULL;
	img->width = 0;
	img->height = 0;
	img->bpp = 0;
	img->line_length = 0;
}

void	ft_init_images(t_data *data)
{
	ft_img_init(&data->global);
	ft_img_init(&data->door);
	ft_img_init(&data->wall[NO]);
	ft_img_init(&data->wall[SO]);
	ft_img_init(&data->wall[WE]);
	ft_img_init(&data->wall[EA]);
	data->global.width = 1080;
	data->global.height = 720;
	data->celling = NULL;
	data->floor = NULL;
}

void	ft_init_player(t_data *data)
{
	data->pl.angle = 0;
}

void	ft_init_map(t_data *data)
{
	data->map.grid = NULL;
	data->map.rows = 0;
	data->map.columns = 0;
	data->map.player = 0;
	data->map.exit = 0;
	data->map.alloc = 0;
}

void	ft_init_game(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->time = 0;
	data->delta = 0;
	data->current_fd = -1;
	ft_init_images(data);
	ft_init_player(data);
	ft_init_map(data);
	data->kp.key[W] = 0;
	data->kp.key[A] = 0;
	data->kp.key[S] = 0;
	data->kp.key[D] = 0;
}
