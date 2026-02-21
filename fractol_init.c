/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:29:31 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 19:29:32 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(t_connection *conn);

void	fractol_init(t_connection **connection)
{
	t_connection	*conn;
	t_img_data		*i;

	*connection = (t_connection *) malloc(sizeof(t_connection));
	conn = *connection;
	if (conn == NULL)
		malloc_error(conn);
	conn->mlx = mlx_init();
	if (conn->mlx == NULL)
		malloc_error(conn);
	conn->win = mlx_new_window(conn->mlx, WIDTH, HEIGHT, "Fractol");
	if (conn->win == NULL)
		malloc_error(conn);
	conn->img_data.img = mlx_new_image(conn->mlx, WIDTH, HEIGHT);
	if (conn->img_data.img == NULL)
		malloc_error(conn);
	i = &conn->img_data;
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->line_length, &i->endian);
	conn->zoom = 1.0;
}

static void	malloc_error(t_connection *conn)
{
	if (conn != NULL)
	{
		if (conn->mlx != NULL)
		{
			if (conn->win != NULL)
				mlx_destroy_window(conn->mlx, conn->win);
			mlx_destroy_display(conn->mlx);
			free(conn->mlx);
		}
		free(conn);
	}
	ft_putstr_fd("Malloc error!", 2);
	exit(1);
}
