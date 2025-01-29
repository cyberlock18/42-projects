/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:27:08 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/28 20:29:35 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	set_rgb_values(t_rgb *rgb)
{
	if (rgb->r > 255)
		rgb->r = 255;
	else if (rgb->r < 0)
		rgb->r = 0;
	if (rgb->g > 255)
		rgb->g = 255;
	else if (rgb->g < 0)
		rgb->g = 0;
	if (rgb->b > 255)
		rgb->b = 255;
	else if (rgb->b < 0)
		rgb->b = 0;
}

void	handle_color_shift(t_data *data, int x, int y, t_rgb rgb)
{
	int	color;

	if (data->color_shift == 1)
		color = (rgb.g << 16) | (rgb.b << 8) | rgb.r;
	else if (data->color_shift == 2)
		color = (rgb.b << 16) | (rgb.r << 8) | rgb.g;
	else if (data->color_shift == 3)
		color = (rgb.r << 16) | (rgb.b << 8) | rgb.g;
	else if (data->color_shift == 4)
		color = (rgb.g << 16) | (rgb.r << 8) | rgb.b;
	else if (data->color_shift == 5)
		color = (rgb.b << 16) | (rgb.g << 8) | rgb.r;
	else
		color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	put_pixel(data, x, y, color);
}

void	handle_exterior_colors(t_data *data, int x, int y, int iter)
{
	t_rgb	rgb;
	double	t;

	t = (double)iter / MAX_ITER;
	rgb.b = (int)(255 * (0.8 + 0.2 * sin(t * 10)));
	rgb.g = (int)(255 * (0.6 + 0.2 * sin(t * 8)));
	rgb.r = (int)(255 * 0.2);
	set_rgb_values(&rgb);
	put_pixel(data, x, y, (rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

int	calculate_color(int iteration, int max_iter, int shift)
{
	double	t;
	double	hsv[3];
	int		rgb[3];

	if (iteration == max_iter)
		return (0x000000);
	t = (double)iteration + 1 - log2(log2(iteration + 1));
	t = t * 20.0 + shift * 5.0;
	hsv[0] = fmod(t * 0.1 + (double)iteration / max_iter * 360.0, 360.0);
	hsv[1] = 0.8 + 0.2 * sin(t * 0.05);
	hsv[2] = 0.7 + 0.3 * sin(t * 0.03) * cos(t * 0.02);
	hsv_to_rgb(hsv[0], hsv[1], hsv[2], rgb);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
