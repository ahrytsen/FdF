/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:56:03 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/01/13 22:43:49 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FdF.h>

static int	ft_esc(int key)
{
	key == ESC ? exit(0) : 0;
	return (0);
}

static int	ft_save_line(char *line, t_env *env)
{
	char	**spl;
	int		*tmp;
	int		i;

	spl = ft_strsplit(line, ' ');
	i = 0;
	while (spl[i++]);
	!(tmp = malloc(sizeof(int) * i)) ? perror("./fdf") : 0;
	!tmp ? exit(1) : 0;
	i = 0;
	while (spl[i])
	{
		tmp[i] = ft_atoi(spl[i]);
		free(spl[i++]);
	}
	if (!ft_lstpush_back(&env->data, tmp, sizeof(int) * i))
	{
		perror("./fdf");
		exit(1);
	}
	free(tmp);
	free(spl);
	return (i);
}

static void	ft_read_map(int fd, t_env *env)
{
	char	*line;
	int		ret;

	(get_next_line(fd, &line) != 1)
		? exit(write(2, "./fdf: map error\n", 17) > 0) : env->s_h++;
	env->s_w = ft_save_line(line, env);
	free(line);
	while ((ret = get_next_line(fd, &line)))
	{
		(ft_save_line(line, env) != env->s_w || ret == -1)
			? exit(write(2, "./fdf: map error\n", 17) > 0) : env->s_h++;
		free(line);
	}
}

static void	ft_print(t_env	*env)
{
	t_list	*d;
	int		x;
	int		y;
	t_point	p[2];

	y = 0;
	while (env->data)
	{
		x = 0;
		while (x < env->s_w)
		{
			if (env->next)
			{
				p[0] = {x, y, env->data[x]};
				p[1] = {x, y + 1, env->next->data[x]};
				ft_draw_line(env, ft_conv_point(p[0]),
							ft_conv_point(p[1]));
			}
			if (x + 1 < env->s_w)
			{
				p[0] = {x, y, env->data[x]};
				p[1] = {x, y + 1, env->next->data[x]};
			ft_draw_line(ft_conv_point({x, y, env->data[j]}),
							ft_conv_point({x + 1, y, env->nexdata[x + 1]})) : 0;
			x++;
		}
		y++;
		env->data = env->data->next;
	}
}

int			main(int ac, char **av)
{
	int				fd;
	static t_env	env;

	(ac != 2) ?	exit(ft_printf("usage: ./fdf map\n") > 0) : 0;
	((fd = open(av[1], O_RDONLY)) == -1) ? perror(av[0]) : 0;
	fd == -1 ? exit(1) : 0;
	ft_read_map(fd, &env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, W_WIDTH, W_HIGHT, "FdF by ahrytsen!");
	ft_print(&env);
	mlx_key_hook(env.win, &ft_esc, 0);
	mlx_hook(env.win, 17, 0, (int (*)())&exit, 0);
	mlx_loop(env.mlx);
}
