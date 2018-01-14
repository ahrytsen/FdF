/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:13:36 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/01/14 16:01:40 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point	ft_conv_point(t_point p, t_env *env)
{
	t_point p0;
	t_point p1;
	t_point p2;

	(void)env;
	p0.x = p.x;
	p0.y = p.y * cos(RAD_X) + p.z * sin(RAD_X);
	p0.z = p.z * cos(RAD_X) - p.y * sin(RAD_X);
	p1.x = p0.x * cos(RAD_Y) - p0.z * sin(RAD_Y);
	p1.y = p0.y;
	p1.z = p0.z * cos(RAD_Y) + p0.x * sin(RAD_Y);
	p2.x = p1.x * cos(RAD_Z) + p1.y * sin(RAD_Z) + W_WIDTH / 2
		- (env->s_w / 8) * SZ;
	p2.y = p1.y * cos(RAD_Z) - p1.x * sin(RAD_Z) + W_HEIGHT / 2
		- (env->s_h / 8) * SZ;
	p2.z = p1.z;
	return (p2);
}

void	ft_draw_line(t_env *env, t_point p0, t_point p1)
{
	double	t;
	double	k;
	int		x;
	int		y;

	t = 0.0;
	k = 1.0 / sqrt((pow((p1.x - p0.x), 2) + pow((p1.y - p0.y), 2)));
	x = p0.x;
	y = p0.y;
	while (t <= 1.0)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, COLOR);
		x = p0.x + (p1.x - p0.x) * t;
		y = p0.y + (p1.y - p0.y) * t;
		t += k;
	}
}
