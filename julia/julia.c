/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:24:45 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:24:47 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(char *x, char *y)
{
	t_connection	*conn;

	fractol_init(&conn);
	conn->r = str_to_double(x);
	conn->im = str_to_double(y);
	draw_julia(conn);
	mlx_put_image_to_window(conn->mlx, conn->win, conn->img_data.img, 0, 0);
	mlx_key_hook(conn->win, handle_keys, conn);
	mlx_hook(conn->win, DESTROY_NOTIFY, 0, close_window, conn);
	mlx_mouse_hook(conn->win, mouse_handler_julia, conn);
	mlx_loop(conn->mlx);
}
