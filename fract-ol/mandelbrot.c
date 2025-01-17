/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:36:14 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/16 20:49:52 by ruortiz-         ###   ########.fr       */
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

void render_mandelbrot_line(t_data *data, int y)
{
    int     x;
    double  c_re;
    double  c_im;
    int     iter;
    int     color;

    x = 0;
    while (x < data->width)
    {
        c_re = (x - data->width / 2.0) / (0.25 * data->width * data->zoom) + data->offset_x;
        c_im = (y - data->height / 2.0) / (0.25 * data->height * data->zoom) + data->offset_y;
        iter = mandelbrot_iter(c_re, c_im);
        color = calculate_color(iter, MAX_ITER, data->color_shift);
        put_pixel(data, x, y, color);
        x++;
    }
}

void mandelbrot(t_data *data)
{
    int y;

    y = 0;
    while (y < data->height)
    {
        render_mandelbrot_line(data, y);
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
