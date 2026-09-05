#include "includes/cub3d.h"

static	void	ft_clear_buffer(t_data *data)
{
	memset(data->global.addr, 0, data->global.line_length * data->global.height);
}

int	ft_render_frame(t_data *data)
{
	ft_clear_buffer(data);
	ft_draw_walls(data);
	ft_print_fov(data, COLOR_FOV);
	ft_print_player(data, COLOR_PLAYER);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->global.mlx_img, 0, 0);
	return (0);
}

void	ft_setup_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, ft_handle_hook, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, ft_release_hook, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask,
		ft_close_game, data);
	mlx_hook(data->mlx_win, Expose, ExposureMask, ft_render_frame, data);
	mlx_loop_hook(data->mlx_ptr, ft_verif_state, data);
}