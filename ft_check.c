/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:52:26 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/04 14:26:32 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_error(t_opt *opt)
{
	int				i;
	struct stat		buf;

	i = 0;
	while (opt->dir[i])
	{
		if (ft_ls_isdir(opt->dir[i]) == FALSE
		&& (lstat(opt->dir[i], &buf)) == -1)
		{
			ft_ls_perr(opt->dir[i]);
			ft_delete_in_tab(opt->dir, i);
			i--;
		}
		i++;
	}
}

int		ft_ls_isdir(char *path)
{
	DIR *pdir;

	if ((pdir = opendir(path)) == NULL)
		return (FALSE);
	closedir(pdir);
	return (TRUE);
}

void	ft_ls_firstcheck(t_opt *opt)
{
	int			i;
	int			originaldirnbr;
	t_dirfile	*last;
	int			deleteddirnbr;

	last = NULL;
	i = 0;
	originaldirnbr = ft_get_dirnbr(opt->dir);
	ft_sort_optdir(opt->dir, ft_get_dirnbr(opt->dir));
	ft_check_error(opt);
	deleteddirnbr = originaldirnbr - ft_get_dirnbr(opt->dir);
	ft_sort_optdir(opt->dir, ft_get_dirnbr(opt->dir));
	ft_print_optarg(opt, originaldirnbr, deleteddirnbr);
}
