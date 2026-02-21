/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:05:09 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:05:11 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_handler_mandelbrot(int button, int x, int y, t_connection *conn)
{
	t_img_data	*i;

	(void) x;
	(void) y;
	i = &conn->img_data;
	mlx_destroy_image(conn->mlx, conn->img_data.img);
	i->img = mlx_new_image(conn->mlx, WIDTH, HEIGHT);
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->line_length, &i->endian);
	if (conn->zoom > 0)
	{
		if (button == 5)
			conn->zoom *= 1.1;
		else if (button == 4)
			conn->zoom /= 1.1;
	}
	else
		return (1);
	draw_mandelbrot(conn);
	mlx_put_image_to_window(conn->mlx, conn->win, conn->img_data.img, 0, 0);
	return (0);
}

int	mouse_handler_julia(int button, int x, int y, t_connection *conn)
{
	t_img_data	*i;

	(void) x;
	(void) y;
	i = &conn->img_data;
	mlx_destroy_image(conn->mlx, conn->img_data.img);
	i->img = mlx_new_image(conn->mlx, WIDTH, HEIGHT);
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->line_length, &i->endian);
	if (conn->zoom > 0)
	{
		if (button == 5)
			conn->zoom *= 1.1;
		else if (button == 4)
			conn->zoom /= 1.1;
	}
	else
		return (1);
	draw_julia(conn);
	mlx_put_image_to_window(conn->mlx, conn->win, conn->img_data.img, 0, 0);
	return (0);
}
