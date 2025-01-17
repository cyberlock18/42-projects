/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:01:21 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/16 20:49:52 by ruortiz-         ###   ########.fr       */
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

void render_julia_line(t_data *data, int y, double c_re, double c_im)
{
    int x;
    double mapped_re;
    double mapped_im;
    int iter;
    int color;

    x = 0;
    while (x < data->width)
    {
        mapped_re = (x - data->width / 2.0)
            / (0.25 * data->width * data->zoom) + data->offset_x;
        mapped_im = (y - data->height / 2.0)
            / (0.25 * data->height * data->zoom) + data->offset_y;
        iter = calculate_julia_iterations(mapped_re, mapped_im, c_re, c_im);
        color = calculate_color(iter, MAX_ITER, data->color_shift);
        put_pixel(data, x, y, color);
        x++;
    }
}

void render_julia_set(t_data *data, double constant_real, double constant_imaginary)
{
    int y;

    y = 0;
    while (y < data->height)
    {
        render_julia_line(data, y, constant_real, constant_imaginary);
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
