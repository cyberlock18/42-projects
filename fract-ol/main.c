/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:37:07 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/02/26 09:57:39 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	validate_julia_args(char **argv)
{
	if (!ft_is_valid_float(argv[2]) || !ft_is_valid_float(argv[3]))
	{
		ft_printf("Error: Julia parameters must be valid numbers\n");
		ft_printf("Example: ./fractol julia -0.4 0.6\n");
		ft_printf("Note: Only numbers and one decimal point are allowed\n");
		exit(1);
	}
}

void	show_help(void)
{
	ft_printf("Usage: ./fractol [fractal_type]\n");
	ft_printf("Available fractals:\n");
	ft_printf("  mandelbrot\n");
	ft_printf("  julia [real] [imaginary]\n");
	exit(0);
}

int	resize_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->fractal_type == 1)
		mandelbrot(data);
	else if (data->fractal_type == 2)
		render_julia_set(data, data->julia_real, data->julia_im);
	return (0);
}

static void	init_fractal(t_data *data, char **argv)
{
	data->mlx = mlx_init();
	mlx_get_screen_size(data->mlx, &data->width, &data->height);
	data->win = mlx_new_window(data->mlx, data->width,
			data->height, "fract-ol");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->color_shift = 0;
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractal_type = 1;
		mandelbrot(data);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		data->fractal_type = 2;
		data->julia_real = ft_atof(argv[2]);
		data->julia_im = ft_atof(argv[3]);
		render_julia_set(data, data->julia_real, data->julia_im);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0
			&& ft_strcmp(argv[1], "julia") != 0))
		show_help();
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc < 4)
			show_help();
		validate_julia_args(argv);
	}
	init_fractal(&data, argv);
	mlx_hook(data.win, ConfigureNotify,
		StructureNotifyMask, resize_hook, &data);
	handle_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
