/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:05:17 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:05:18 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(t_connection *conn)
{
	mlx_destroy_image(conn->mlx, conn->img_data.img);
	mlx_destroy_window(conn->mlx, conn->win);
	mlx_destroy_display(conn->mlx);
	free(conn->mlx);
	free(conn);
	exit(0);
}
