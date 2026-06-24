/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:05:17 by yuak              #+#    #+#             */
/*   Updated: 2026/06/24 19:57:39 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(void *param)
{
	t_connection	*conn;

	conn = (t_connection *) param;
	mlx_destroy_image(conn->mlx, conn->img_data.img);
	mlx_destroy_window(conn->mlx, conn->win);
	mlx_destroy_display(conn->mlx);
	free(conn->mlx);
	free(conn);
	exit(0);
}
