/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:13:27 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/15 22:31:42 by ruortiz-         ###   ########.fr       */
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

// Struct for fractal settings
typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

// Function prototypes
void    mandelbrot(t_data *data);
void    render_julia_set(t_data *data, double constant_real, double constant_imaginary);
void    handle_hooks(t_data *data);
void    put_pixel(t_data *data, int x, int y, int color);
void    show_help(void);
int mouse_hooks(int button, int x, int y);

#endif
