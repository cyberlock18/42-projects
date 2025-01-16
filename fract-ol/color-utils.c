/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:27:08 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/16 20:27:17 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int calculate_color(int iteration, int max_iter, int shift)
{
    double t;

    if (iteration == max_iter)
        return (0x000000); // Negro para los puntos que no escapan
    t = (double)iteration / max_iter;
    return ((int)(9 * (1 - t) * t * t * t * 255) << (16 + shift) | // Rojo
            (int)(15 * (1 - t) * (1 - t) * t * t * 255) << (8 + shift) | // Verde
            (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255) << shift); // Azul
}
