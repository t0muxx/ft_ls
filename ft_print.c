/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 07:59:36 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/05 15:47:03 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_printspace(int max, int len)
{
	int i;

	i = 0;
	while (i < (max - len))
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

void	ft_lst_printfield(t_dirfile *last, t_maxvalue max, t_opt *opt)
{
	char *ptr;

	ptr = ft_itoa(last->nblink);
	ft_putchar(last->type);
	ft_putstr(last->perm);
	ft_putstr("  ");
	ft_printspace(max.nblink, ft_strlen(ptr));
	free(ptr);
	ft_putnbr(last->nblink);
	ft_putstr(" ");
	if (opt->g != TRUE)
		ft_print_owner(last, max);
	ft_putstr(last->group);
	ft_printspace(max.group, ft_strlen(last->group));
	ft_strdel(&(last->group));
	ft_print_sizeormajmin(last, max);
	ft_putstr(" ");
	ft_ls_print_mdate(last->date, last);
	ft_putstr(" ");
	ft_print_fname(last);
	ft_lst_print_ln(last);
}

void	ft_lst_printtotal(t_dirfile *last)
{
	int total;

	total = 0;
	while (last)
	{
		total = total + last->blocknbr;
		last = last->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putendl("");
}

void	ft_lst_print(t_dirfile *last, t_opt *opt, int total)
{
	t_maxvalue max;

	if ((opt->l == FALSE && opt->g == FALSE) || opt->one == TRUE)
		ft_print_simple(last, opt);
	else
	{
		max = ft_lst_maxdigit(last);
		if (total == TRUE)
		{
			if (last != NULL)
				ft_lst_printtotal(last);
		}
		while (last != NULL)
		{
			ft_lst_printfield(last, max, opt);
			last = last->next;
		}
	}
}

void	ft_ls_print_mdate(t_mdate mdate, t_dirfile *last)
{
	ft_putstr(mdate.month);
	if (ft_strlen(mdate.daynbr) == 2)
		ft_putstr(" ");
	else
		ft_putstr("  ");
	ft_putstr(mdate.daynbr);
	ft_putstr(" ");
	if (!(last->t_mtime + SIXMONTHS > time(NULL)
	&& last->t_mtime < time(NULL) + SIXMONTHS))
	{
		ft_putstr(" ");
		ft_putstr(mdate.year);
	}
	else
		ft_putstr(mdate.hour);
}
