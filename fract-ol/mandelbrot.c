/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:36:14 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/26 19:52:21 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_iter(double c_re, double c_im)
{
    double  z_re = 0;
    double  z_im = 0;
    double  z_re2;
    double  z_im2;
    int     iteration = 0;

    while (iteration < MAX_ITER)
    {
        z_re2 = z_re * z_re;
        z_im2 = z_im * z_im;
        if (z_re2 + z_im2 > 4.0)
            break ;
        z_im = 2 * z_re * z_im + c_im;
        z_re = z_re2 - z_im2 + c_re;
        iteration++;
    }
    return (iteration);
}

static void handle_mandelbrot_colors(t_data *data, int x, int y, int iter)
{
	t_rgb	rgb;
	double	inner_glow;
	double	angle;

	if (iter == MAX_ITER)
	{
		inner_glow = ((x - data->width / 2.0) * (x - data->width / 2.0) +
			(y - data->height / 2.0) * (y - data->height / 2.0))
			/ (data->width * data->width);
		angle = atan2(y - data->height / 2.0, x - data->width / 2.0) +
			data->color_shift * M_PI / 3;
		rgb.r = (int)(127 + 127 * sin(angle * 3 + inner_glow));
		rgb.g = (int)(127 + 127 * sin(angle * 2 + inner_glow * 2));
		rgb.b = (int)(200 + 55 * sin(angle + inner_glow * 3));
		set_rgb_values(&rgb);
		handle_color_shift(data, x, y, rgb);
	}
	else
		handle_exterior_colors(data, x, y, iter);
}

void mandelbrot(t_data *data)
{
    int x, y;
    double c_re, c_im;
    int iter;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            c_re = (x - data->width / 2.0) / (0.25 * data->width * data->zoom) + data->offset_x;
            c_im = (y - data->height / 2.0) / (0.25 * data->height * data->zoom) + data->offset_y;
            
            iter = mandelbrot_iter(c_re, c_im);
            handle_mandelbrot_colors(data, x, y, iter);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}