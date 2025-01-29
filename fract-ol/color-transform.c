/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color-transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:18:02 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/29 09:57:52 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void	normalize_rgb_values(int *r, int *g, int *b)
{
	if (*r > 255)
		*r = 255;
	if (*r < 0)
		*r = 0;
	if (*g > 255)
		*g = 255;
	if (*g < 0)
		*g = 0;
	if (*b > 255)
		*b = 255;
	if (*b < 0)
		*b = 0;
}

void	set_rgb(int *rgb, double r, double g, double b)
{
	rgb[0] = (int)r;
	rgb[1] = (int)g;
	rgb[2] = (int)b;
	normalize_rgb_values(&rgb[0], &rgb[1], &rgb[2]);
}

void	set_color_values(int hi, t_color_params params, int *rgb)
{
	if (hi == 0)
		set_rgb(rgb, params.v, params.t, params.p);
	else if (hi == 1)
		set_rgb(rgb, params.q, params.v, params.p);
	else if (hi == 2)
		set_rgb(rgb, params.p, params.v, params.t);
	else if (hi == 3)
		set_rgb(rgb, params.p, params.q, params.v);
	else if (hi == 4)
		set_rgb(rgb, params.t, params.p, params.v);
	else
		set_rgb(rgb, params.v, params.p, params.q);
}

void	hsv_to_rgb(double h, double s, double v, int *rgb)
{
	int				hi;
	double			f;
	t_color_params	params;

	hi = ((int)(h / 60.0)) % 6;
	f = h / 60.0 - hi;
	params.p = v * (1 - s);
	params.q = v * (1 - f * s);
	params.t = v * (1 - (1 - f) * s);
	params.v = v * 255;
	params.p *= 255;
	params.q *= 255;
	params.t *= 255;
	set_color_values(hi, params, rgb);
}
