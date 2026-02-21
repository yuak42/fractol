/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:28:03 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 19:28:04 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10) && !av[1][10])
		mandelbrot();
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5) && !av[1][5])
	{
		if (is_double(av[2]) && is_double(av[3]))
			julia(av[2], av[3]);
		else
			show_help();
	}
	else
		show_help();
	return (0);
}

void	show_help(void)
{
	ft_printf("\nExpected usage:\n\n./fractol mandelbrot\n");
	ft_printf("\nor\n\n./fractol julia <real> <imag>\n");
	ft_printf("\nSome Examples for julia sets:\n");
	ft_printf("------------------------------\n");
	ft_printf("./fractol julia 0.285 0\n");
	ft_printf("./fractol julia 0.285 0.01\n");
	ft_printf("./fractol julia -0.8 0.156\n");
}
