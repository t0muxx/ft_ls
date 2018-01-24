/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:22:35 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/05 11:34:55 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_cpyopt(t_opt *opt, int i, int arc, char **arv)
{
	int j;

	j = 0;
	if ((arc - i + 1) == 1)
	{
		opt->dir[0] = ft_strdup(".");
		j++;
		opt->dir[1] = 0;
	}
	else
	{
		while (i < arc)
		{
			if (i < arc)
				opt->dir[j] = ft_strdup(arv[i]);
			i++;
			j++;
		}
		opt->dir[j] = 0;
	}
}

void		ft_ls_get_diropt(t_opt *opt, int i, int arc, char **arv)
{
	if ((opt->dir = (char **)malloc(sizeof(char *) * (arc - i + 1))) == NULL)
	{
		ft_putendl("some malloc failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_ls_cpyopt(opt, i, arc, arv);
	}
}

void		ft_ls_get_opt(t_opt *opt, int arc, char **arv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	ft_ls_init_opt(opt);
	while (i < arc && arv[i][0] == '-' && arv[i][1] > 0 && arv[i][1] < 127
	&& ft_strcmp(arv[i], "--") != 0)
	{
		j = 0;
		while (arv[i][j] != '\0' && i < arc)
		{
			ft_ls_manage_err(arv, i, j);
			ft_ls_manage_opt(opt, arv, i, j);
			j++;
		}
		i++;
	}
	if (arc > 1 && arv[i - 1][j - 1] == '1')
		opt->one = TRUE;
	if (i < arc && ft_strcmp(arv[i], "--") == 0)
		i++;
	ft_ls_get_diropt(opt, i, arc, arv);
}

char		*ft_getpath(char *path, char *d_name)
{
	char *ret;

	if ((ret = (char *)malloc(sizeof(char) *
	(ft_strlen(path) + ft_strlen(d_name) + 2))) == NULL)
	{
		ft_putendl("some malloc failed");
		exit(EXIT_FAILURE);
	}
	ft_bzero(ret, ft_strlen(path) + ft_strlen(d_name) + 2);
	if (ft_strcmp(path, ".") == 0)
	{
		ft_strcat(ret, d_name);
		ret[ft_strlen(path) + ft_strlen(d_name) + 1] = '\0';
		return (ret);
	}
	ft_strcat(ret, path);
	ft_strcat(ret, "/");
	ft_strcat(ret, d_name);
	return (ret);
}
