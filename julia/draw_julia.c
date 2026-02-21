/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:24:51 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:24:52 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_julia(t_connection *conn)
{
	t_complex	c;
	int			x;
	int			y;

	c.x = conn->r;
	c.y = conn->im;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			paint_julia(conn, x++, y, c);
		y++;
	}
}
