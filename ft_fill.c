/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:22:08 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/04 16:47:19 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_fill_lst_2(t_dirfile **last, char *path, t_opt *opt,
struct dirent *dir)
{
	char			*catpath;
	struct stat		buf;
	t_dirfile		*new;

	catpath = ft_getpath(path, dir->d_name);
	if ((lstat(catpath, &buf)) == -1)
	{
		perror(catpath);
		return (0);
	}
	if (opt->a != TRUE && dir->d_name[0] == '.')
		;
	else
	{
		new = ft_dirfilenew(dir->d_name, buf, catpath);
		if (opt->t == TRUE)
			ft_lst_sortedinsertbytime(last, new);
		else
			ft_lst_sortedinsert(last, new);
	}
	free(catpath);
	return (1);
}

int			ft_fill_lst(t_dirfile **last, char *path, t_opt *opt)
{
	struct dirent	*dir;
	DIR				*pdir;

	if ((pdir = opendir(path)) == NULL)
	{
		ft_ls_perr(path);
		return (0);
	}
	else
	{
		while ((dir = readdir(pdir)) != NULL)
		{
			ft_fill_lst_2(last, path, opt, dir);
		}
		if (opt->r == TRUE)
			ft_revlist(last);
		closedir(pdir);
	}
	return (1);
}

t_dirfile	*ft_simplefilenew(char *filename, struct stat buf, char *catpath)
{
	t_dirfile *new;

	if (!(new = malloc(sizeof(t_dirfile))))
		return (NULL);
	else
	{
		ft_lst_cpyvalue(&new, filename, buf, catpath);
	}
	new->next = NULL;
	return (new);
}
