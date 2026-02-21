/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:23:04 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 20:23:06 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	put_pixel(t_img_data *img_data, double x, double y, int color)
{
	char	*pixel_first_byte;

	pixel_first_byte = img_data->addr;
	pixel_first_byte += (int) x * (img_data->bpp / 8);
	pixel_first_byte += (int) y * img_data->line_length;
	*(unsigned int *) pixel_first_byte = color;
}
