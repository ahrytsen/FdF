/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:55:43 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/01/14 14:25:51 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <libft.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <math.h>

# define W_WIDTH 1000
# define W_HEIGHT 800
# define ESC 53
# define RAD_X -60.0 * (M_PI / 180.0)
# define RAD_Y 45.0 * (M_PI / 180.0)
# define RAD_Z 0.0 * (M_PI / 180.0)
# define SZ 5
# define COLOR 0x00FFFFFF

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		s_w;
	int		s_h;
	t_list	*data;
}				t_env;

t_point			ft_conv_point(t_point p, t_env *env);
void			ft_draw_line(t_env *env, t_point p0, t_point p1);

#endif
