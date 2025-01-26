/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:27:08 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/26 20:13:35 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int get_psychedelic_color(double t, int iteration, int max_iter)
{
    double hue;
    double saturation;
    double brightness;
    int r, g, b;
    
    // Calcular el tono (hue) basado en la iteración
    hue = fmod(t * 0.1 + (double)iteration / max_iter * 360.0, 360.0);
    
    // Saturación pulsante
    saturation = 0.8 + 0.2 * sin(t * 0.05);
    
    // Brillo pulsante con efecto psicodélico
    brightness = 0.7 + 0.3 * sin(t * 0.03) * cos(t * 0.02);

    // Convertir HSV a RGB con efectos psicodélicos
    double h = hue / 60.0;
    double s = saturation;
    double v = brightness;
    
    int hi = (int)h % 6;
    double f = h - (int)h;
    double p = v * (1 - s);
    double q = v * (1 - f * s);
    double u = v * (1 - (1 - f) * s);

    v *= 255;
    p *= 255;
    q *= 255;
    u *= 255;

    switch (hi) {
        case 0: r = v; g = u; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = u; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = u; g = p; b = v; break;
        default: r = v; g = p; b = q;
    }

    // Añadir efectos de neón
    r = (int)(r * (1.0 + 0.2 * sin(t * 0.1)));
    g = (int)(g * (1.0 + 0.2 * sin(t * 0.12)));
    b = (int)(b * (1.0 + 0.2 * sin(t * 0.14)));

    // Asegurar que los valores estén en el rango correcto
    r = r > 255 ? 255 : (r < 0 ? 0 : r);
    g = g > 255 ? 255 : (g < 0 ? 0 : g);
    b = b > 255 ? 255 : (b < 0 ? 0 : b);

    return (r << 16) | (g << 8) | b;
}

int calculate_color(int iteration, int max_iter, int shift)
{
    double t;

    if (iteration == max_iter)
        return (0x000000);

    // Suavizado mejorado para transiciones más suaves
    t = (double)iteration + 1 - log2(log2(iteration + 1));
    t = t * 20.0 + shift * 5.0; // Aumentar la variación de color
    
    return get_psychedelic_color(t, iteration, max_iter);
}

void	handle_exterior_colors(t_data *data, int x, int y, int iter)
{
	t_rgb	rgb;
	double	t;

	t = (double)iter / MAX_ITER;
	// Colores fijos para el exterior - tonos azul-verdoso estáticos
	rgb.b = (int)(255 * (0.8 + 0.2 * sin(t * 10)));
	rgb.g = (int)(255 * (0.6 + 0.2 * sin(t * 8)));
	rgb.r = (int)(255 * 0.2);
	
	set_rgb_values(&rgb);
	// Color directo sin usar handle_color_shift para el exterior
	put_pixel(data, x, y, (rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

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

	// Esta función ahora solo se usa para el interior
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
