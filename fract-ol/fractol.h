/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:13:27 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/02/03 20:31:06 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITER 100
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>       // Para las constantes de eventos como ConfigureNotify
# include <X11/keysym.h>  // (Opcional) Si necesitas manejar teclas específicas

// Struct for fractal settings
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;// Ancho de la ventana
	int		height;// Alto de la ventana
	int		fractal_type;// 1 para Mandelbrot, 2 para Julia
	double	julia_real;// Constante real para Julia
	double	julia_im;// Constante imaginaria para Julia
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	int		color_shift;// Añadir esta variable para el cambio de color
	int		color_mode;
	int		max_iter;
}	t_data;

typedef struct s_color_params
{
	double	v;
	double	p;
	double	q;
	double	t;
}	t_color_params;

// Function prototypes
void	mandelbrot(t_data *data);
void	render_julia_set(t_data *data, double constant_real,
			double constant_imaginary);
void	handle_hooks(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	show_help(void);
void	validate_julia_args(char **argv);
void	set_rgb_values(t_rgb *rgb);
void	handle_color_shift(t_data *data, int x, int y, t_rgb rgb);
void	handle_exterior_colors(t_data *data, int x, int y, int iter);
int		mouse_hooks(int button, int x, int y, t_data *data);
int		resize_hook(t_data *data);
int		close_window(t_data *data);
int		key_hooks(int keycode, t_data *data);
int		calculate_color(int iteration, int max_iter, int shift);

// Añadir nuevos prototipos
void	hsv_to_rgb(double h, double s, double v, int *rgb);
void	set_color_values(int hi, t_color_params params, int *rgb);
void	set_rgb(int *rgb, double r, double g, double b);

#endif
