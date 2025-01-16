/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:36:14 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 23:09:29 by ruortiz-         ###   ########.fr       */
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
    int x, y;
    double c_re, c_im;
    int color, iter;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            c_re = (x - data->width / 2.0) / (0.25 * data->width * data->zoom) + data->offset_x;
            c_im = (y - data->height / 2.0) / (0.25 * data->height * data->zoom) + data->offset_y;
            
            iter = mandelbrot_iter(c_re, c_im);
            if (iter == MAX_ITER)
                color = 0x000000;
            else
                color = ((iter * 255 / MAX_ITER) << 16) | 
                        ((iter * 255 / MAX_ITER) << 8) | 
                        (iter * 255 / MAX_ITER);
            
            put_pixel(data, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}