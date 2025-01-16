/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:01:21 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/16 20:32:50 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_ITER 100

int calculate_julia_iterations(double real_part, double imaginary_part, double constant_real, double constant_imaginary)
{
    double real_squared;
    double imaginary_squared;
    int iteration = 0;

    while (iteration < MAX_ITER)
    {
        real_squared = real_part * real_part;
        imaginary_squared = imaginary_part * imaginary_part;
        if (real_squared + imaginary_squared > 4.0)
            break;
        imaginary_part = 2 * real_part * imaginary_part + constant_imaginary;
        real_part = real_squared - imaginary_squared + constant_real;
        iteration++;
    }
    return iteration;
}

void render_julia_set(t_data *data, double constant_real, double constant_imaginary)
{
    int x, y;
    double mapped_re, mapped_im;
    int color, iter;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            mapped_re = (x - data->width / 2.0) / (0.25 * data->width * data->zoom) + data->offset_x;
            mapped_im = (y - data->height / 2.0) / (0.25 * data->height * data->zoom) + data->offset_y;
            
            iter = calculate_julia_iterations(mapped_re, mapped_im, constant_real, constant_imaginary);
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
