/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:24:26 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:24:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	paint_mandelbrot(t_connection *conn, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		x_temp;
	int			color;
	int			i;

	c.x = (x - WIDTH / 2.0) * (4.0 * conn->zoom / WIDTH) - 0.5;
	c.y = -((y - HEIGHT / 2.0) * (4.0 * conn->zoom / WIDTH));
	z.x = 0;
	z.y = 0;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < MAX_ITER)
	{
		x_temp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = x_temp;
		i++;
	}
	if (i == MAX_ITER)
		color = 0x000000;
	else
		color = get_color(i);
	put_pixel(&conn->img_data, x, y, color);
}
