/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx-utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:13:15 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 22:22:44 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int key_hooks(int keycode, t_data *data)
{
    if (keycode == 65307) // Tecla ESC el 53 en linux y 65307 en windows mac
        close_window(data);
    return (0);
}

int mouse_hooks(int button, int x, int y)
{
    (void)x;
    (void)y;
    if (button == 4)
        ft_printf("Zoom in\n");
    else if (button == 5)
        ft_printf("Zoom out\n");
    return (0);
}


void handle_hooks(t_data *data)
{
    mlx_key_hook(data->win, key_hooks, data);
    mlx_mouse_hook(data->win, mouse_hooks, data);
    mlx_hook(data->win, 17, 0, close_window, data); // Evento de cierre de ventana
}

void put_pixel(t_data *data, int x, int y, int color)
{
    char *pixel;

    if (x >= 0 && x < 800 && y >= 0 && y < 800)
    {
        pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pixel = color;
    }
}
