/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:58:26 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:58:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color(int i)
{
	int	color;
	int	m;
	int	increase;
	int	decrease;

	m = 0x0000FF / (MAX_ITER / 2);
	increase = m * i;
	decrease = m * (i - MAX_ITER / 2);
	if (i < MAX_ITER / 2)
	{	
		color = 0x000000;
		color += increase;
		color = color << 8;
		color += increase;
		color = color << 8;
		color += 0x0000FF;
	}
	else
	{
		color = 0xFFFFFF;
		color -= (decrease << 8);
		color -= decrease;
	}
	return (color);
}
