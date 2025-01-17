/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:13:27 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/16 20:54:17 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITER 100
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>       // Para las constantes de eventos como ConfigureNotify
# include <X11/keysym.h>  // (Opcional) Si necesitas manejar teclas específicas

// Struct for fractal settings
typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
    double  zoom;
    double  offset_x;
    double  offset_y;
    int     fractal_type;
    double  julia_real;
    double  julia_im;
    int     color_shift; // Nuevo campo para el desplazamiento del color
}               t_data;


// Function prototypes
void    mandelbrot(t_data *data);
void    render_julia_set(t_data *data, double constant_real, double constant_imaginary);
void    handle_hooks(t_data *data);
void    put_pixel(t_data *data, int x, int y, int color);
void    show_help(void);
int     mouse_hooks(int button, int x, int y, t_data *data); // Modificada esta línea
int     resize_hook(t_data *data);
int     close_window_properly(t_data *data);
int     key_hooks(int keycode, t_data *data);
int calculate_color(int iteration, int max_iter, int shift);

#endif
