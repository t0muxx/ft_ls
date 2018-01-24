/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:58:57 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/04 16:46:28 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_rc(char *path, int i)
{
	if (i > 0)
	{
		ft_putendl("");
		ft_print_path(path, TRUE);
	}
}

int		ft_free_recur(t_dirfile **last)
{
	t_dirfile	*ptr;

	ptr = *last;
	if (last == NULL)
	{
		ft_lst_free(ptr);
		return (0);
	}
	return (1);
}

void	ft_go_recur(t_dirfile *last, char *path, int *i, t_opt *opt)
{
	char *catpath;

	if (ft_strcmp(last->name, ".") != 0 && ft_strcmp(last->name, "..") != 0)
	{
		(*i)++;
		catpath = ft_getpath(path, last->name);
		ft_ls_recur(catpath, opt);
		free(catpath);
	}
}

int		ft_ls_recur(char *path, t_opt *opt)
{
	char		*catpath;
	t_dirfile	*last;
	t_dirfile	*ptr;
	static int	i;

	last = NULL;
	ft_print_rc(path, i);
	catpath = NULL;
	ft_fill_lst(&last, path, opt);
	ptr = last;
	if (ft_free_recur(&last) == 0)
		return (0);
	ft_lst_print(last, opt, TRUE);
	while (last)
	{
		if (last->type == 'd')
		{
			ft_go_recur(last, path, &i, opt);
		}
		last = last->next;
	}
	ft_lst_free(ptr);
	return (1);
}

int		ft_ls_print_dir(char *path, t_opt *opt)
{
	char		*catpath;
	t_dirfile	*last;

	last = NULL;
	catpath = NULL;
	ft_fill_lst(&last, path, opt);
	if (last == NULL)
		return (0);
	ft_lst_print(last, opt, TRUE);
	ft_lst_free(last);
	return (1);
}
