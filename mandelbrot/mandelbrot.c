/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:24:15 by yuak              #+#    #+#             */
/*   Updated: 2026/06/24 20:01:11 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(void)
{
	t_connection	*conn;

	fractol_init(&conn);
	draw_mandelbrot(conn);
	mlx_put_image_to_window(conn->mlx, conn->win, conn->img_data.img, 0, 0);
	mlx_key_hook(conn->win, handle_keys, conn);
	// mlx_hook(conn->win, DESTROY_NOTIFY, 0, close_window, conn);
	mlx_mouse_hook(conn->win, mouse_handler_mandelbrot, conn);
	mlx_loop(conn->mlx);
}
