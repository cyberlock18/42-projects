/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:36:14 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 21:22:04 by ruortiz-         ###   ########.fr       */
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

void mandelbrot(t_data *data)
{
    int     x, y;
    double  c_re, c_im;
    int     color, iter;

    y = 0;
    while (y < 800)
    {
        x = 0;
        while (x < 800)
        {
            c_re = (x - 400) / 200.0;
            c_im = (y - 400) / 200.0;
            iter = mandelbrot_iter(c_re, c_im);
            color = (iter == MAX_ITER) ? 0x000000 : (iter * 255 / MAX_ITER) << 16;
            put_pixel(data, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
