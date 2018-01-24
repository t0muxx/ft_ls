/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:35:35 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/05 17:07:22 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_simple(t_dirfile *last, t_opt *opt)
{
	while (last)
	{
		ft_print_fname(last);
		if (ft_strlen(last->owner) != 0)
			ft_strdel(&(last->owner));
		if (ft_strlen(last->group) != 0)
			ft_strdel(&(last->group));
		opt->l = opt->l;
		ft_putendl("");
		last = last->next;
	}
}

void	ft_print_path(char *path, int rec)
{
	if (rec == TRUE)
	{
		ft_putstr(".");
		if (path[0] != '/')
			ft_putstr("/");
		ft_putstr(path);
		ft_putendl(":");
	}
	else
	{
		ft_putstr(path);
		ft_putendl(":");
	}
}

void	ft_print_sizeormajmin(t_dirfile *last, t_maxvalue max)
{
	char		*ptr;
	static int	space;

	if (last->type == 'b' || last->type == 'c')
	{
		ft_putstr("  ");
		ptr = ft_itoa(last->major);
		space = ft_printspace(max.maj, ft_strlen(ptr));
		free(ptr);
		ft_putnbr(last->major);
		ft_putstr(", ");
		ptr = ft_itoa(last->minor);
		space = space + ft_printspace(max.min, ft_strlen(ptr));
		ft_putnbr(last->minor);
		space = space + 3;
	}
	else
	{
		ft_putstr("  ");
		ft_printspace(space, 0);
		ptr = ft_itoa(last->size);
		ft_printspace(max.size, ft_strlen(ptr));
		ft_putnbr(last->size);
	}
	free(ptr);
}

void	ft_lst_print_ln(t_dirfile *last)
{
	if (last->type == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(last->lnpath);
		ft_putendl("");
	}
	else
		ft_putendl("");
}
