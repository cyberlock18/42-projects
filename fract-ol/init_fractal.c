/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:27:08 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/02/03 20:31:06 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_data *data)
{
    data->min_re = -2.0;
    data->max_re = 0.5;
    data->min_im = -1.25;
    data->max_im = 1.25;
    data->zoom = 1.0;
    data->max_iter = MAX_ITER;
    data->color_shift = 0;
    data->color_mode = 0;
    data->julia_real = 0.285;
    data->julia_im = 0.01;
}
