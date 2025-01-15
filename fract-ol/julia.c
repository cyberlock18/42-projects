/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:01:21 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 21:23:03 by ruortiz-         ###   ########.fr       */
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
    int pixel_x, pixel_y;
    double mapped_real, mapped_imaginary;
    int color, iterations;

    pixel_y = 0;
    while (pixel_y < 800)
    {
        pixel_x = 0;
        while (pixel_x < 800)
        {
            mapped_real = (pixel_x - 400) / 200.0;
            mapped_imaginary = (pixel_y - 400) / 200.0;
            iterations = calculate_julia_iterations(mapped_real, mapped_imaginary,
                                                    constant_real, constant_imaginary);
            color = (iterations == MAX_ITER) ? 0x000000 : (iterations * 255 / MAX_ITER) << 16;
            put_pixel(data, pixel_x, pixel_y, color);
            pixel_x++;
        }
        pixel_y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
