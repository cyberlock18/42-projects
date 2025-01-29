/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx-utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:13:15 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/29 09:10:22 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65361)
		data->offset_x -= 0.1 / data->zoom;
	else if (keycode == 65363)
		data->offset_x += 0.1 / data->zoom;
	else if (keycode == 65362)
		data->offset_y -= 0.1 / data->zoom;
	else if (keycode == 65364)
		data->offset_y += 0.1 / data->zoom;
	else if (keycode == 43 || keycode == 61)
	{
		data->color_shift = (data->color_shift + 1) % 6;
		resize_hook(data);
		return (0);
	}
	if (keycode >= 65361 && keycode <= 65364)
		resize_hook(data);
	return (0);
}

int	mouse_hooks(int button, int x, int y, t_data *data)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - data->width / 2.0)
		/ (0.25 * data->width * data->zoom) + data->offset_x;
	mouse_im = (y - data->height / 2.0)
		/ (0.25 * data->height * data->zoom) + data->offset_y;
	if (button == 4)
	{
		data->zoom *= 1.2;
		data->offset_x = mouse_re - (x - data->width / 2.0)
			/ (0.25 * data->width * data->zoom);
		data->offset_y = mouse_im - (y - data->height / 2.0)
			/ (0.25 * data->height * data->zoom);
	}
	else if (button == 5)
	{
		data->zoom /= 1.2;
		data->offset_x = mouse_re - (x - data->width / 2.0)
			/ (0.25 * data->width * data->zoom);
		data->offset_y = mouse_im - (y - data->height / 2.0)
			/ (0.25 * data->height * data->zoom);
	}
	resize_hook(data);
	return (0);
}

void	handle_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hooks, data);
	mlx_mouse_hook(data->win, mouse_hooks, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		pixel = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}
