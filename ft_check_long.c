/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 08:38:26 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/05 11:47:06 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_cpy_arg_file(t_dirfile **last, t_opt *opt, int *j, int *i)
{
	t_dirfile	*file;
	char		lk[255];
	struct stat buf;
	struct stat bufln;

	ft_bzero(lk, 255);
	lstat(opt->dir[*i], &buf);
	if (S_ISDIR(buf.st_mode) == 0)
	{
		if (S_ISLNK(buf.st_mode) == 1 && readlink(opt->dir[*i], lk, 255) != -1)
			lstat(lk, &bufln);
		if ((S_ISDIR(bufln.st_mode) != 1 || opt->l == TRUE
		|| S_ISLNK(buf.st_mode) != 1))
		{
			file = ft_simplefilenew(opt->dir[*i], buf, opt->dir[*i]);
			if (opt->t == TRUE)
				ft_lst_sortedinsertbytime(last, file);
			else
				ft_lst_sortedinsert(last, file);
			ft_delete_in_tab(opt->dir, (*i)--);
			(*j)++;
		}
	}
}

void	ft_print_arg_file(t_opt *opt, int originaldirnbr, int deleteddirnbr)
{
	int			i;
	t_dirfile	*last;
	int			j;

	last = NULL;
	i = 0;
	j = 0;
	while (opt->dir[i])
	{
		ft_cpy_arg_file(&last, opt, &j, &i);
		i++;
	}
	if (opt->r == TRUE)
		ft_revlist(&last);
	ft_lst_print(last, opt, FALSE);
	if (last != NULL && j != (originaldirnbr - deleteddirnbr))
		ft_putendl("");
	ft_lst_free(last);
}

void	ft_print_dir(t_opt *opt, int *i, int dirnbr, int originaldirnbr)
{
	if (opt->rec == TRUE)
	{
		if (dirnbr > 1)
			ft_print_path(opt->dir[*i], FALSE);
		ft_ls_recur(opt->dir[*i], opt);
		if (*i != dirnbr - 1)
			ft_putendl("");
	}
	else
	{
		if (originaldirnbr > 1)
			ft_print_path(opt->dir[*i], FALSE);
		ft_ls_print_dir(opt->dir[*i], opt);
		if (*i != dirnbr - 1)
			ft_putendl("");
	}
}

void	ft_print_arg_dir(t_opt *opt, int originaldirnbr)
{
	int			i;
	struct stat	buf;
	int			dirnbr;
	char		link[255];

	i = 0;
	dirnbr = ft_get_dirnbr(opt->dir);
	while (opt->dir[i])
	{
		ft_bzero(link, 255);
		lstat(opt->dir[i], &buf);
		if (S_ISLNK(buf.st_mode) == 1 && opt->l == FALSE)
		{
			readlink(opt->dir[i], link, 255);
			stat(link, &buf);
		}
		if (S_ISDIR(buf.st_mode) == 1)
			ft_print_dir(opt, &i, dirnbr, originaldirnbr);
		i++;
	}
}

void	ft_print_optarg(t_opt *opt, int originaldirnbr, int deleteddirnbr)
{
	ft_print_arg_file(opt, originaldirnbr, deleteddirnbr);
	ft_sort_optdir(opt->dir, ft_get_dirnbr(opt->dir));
	ft_print_arg_dir(opt, originaldirnbr);
}
