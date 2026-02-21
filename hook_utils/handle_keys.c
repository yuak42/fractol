/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:05:23 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:05:24 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_keys(int keycode, void *param)
{
	t_connection	*conn;

	conn = (t_connection *) param;
	if (keycode == KEY_ESC)
		close_window(conn);
	return (0);
}
