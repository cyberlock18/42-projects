/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:37:07 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 21:46:25 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void show_help(void)
{
    ft_printf("Usage: ./fractol [fractal_type]\n");
    ft_printf("Available fractals:\n");
    ft_printf("  mandelbrot\n");
    ft_printf("  julia [real] [imaginary]\n");
    exit(0);
}

int main(int argc, char **argv)
{
    t_data  data;

    // Validación de argumentos
    if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 &&
                     ft_strcmp(argv[1], "julia") != 0))
        show_help();
    // Inicialización de MiniLibX y configuración
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 800, "fract-ol");
    data.img = mlx_new_image(data.mlx, 800, 800);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
                                  &data.line_length, &data.endian);
    // Selección del fractal
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
        mandelbrot(&data);
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        if (argc < 4)
            show_help();
        double real = ft_atof(argv[2]);
        double imaginary = ft_atof(argv[3]);
        render_julia_set(&data, real, imaginary);
    }
    // Configurar eventos y bucle principal
    handle_hooks(&data);
    mlx_loop(data.mlx);
    return (0);
}


