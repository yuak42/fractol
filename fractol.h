/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:02:03 by yuak              #+#    #+#             */
/*   Updated: 2025/12/11 21:02:05 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <float.h>

typedef struct s_complex {
	double	x;
	double	y;
}	t_complex;

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_connection {
	void		*mlx;
	void		*win;
	t_img_data	img_data;
	double		zoom;
	double		r;
	double		im;
}	t_connection;

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 42
# define KEY_ESC 65307
# define DESTROY_NOTIFY 17

void	show_help(void);
void	mandelbrot(void);
void	fractol_init(t_connection **conn);
void	paint_mandelbrot(t_connection *conn, int x, int y);
void	paint_julia(t_connection *conn, int x, int y, t_complex c);
void	julia(char *x, char *y);
void	put_pixel(t_img_data *img_data, double x, double y, int color);
int		get_color(int i);
int		handle_keys(int keycode, void *param);
int		close_window(t_connection *conn);
int		mouse_handler_mandelbrot(int button, int x, int y, t_connection *conn);
int		mouse_handler_julia(int button, int x, int y, t_connection *conn);
void	draw_mandelbrot(t_connection *conn);
void	draw_julia(t_connection *conn);
char	*remove_space(char *str);
int		is_double(char *s);
double	str_to_double(char *s);
int		is_exactly_zero(char *s);

#endif
