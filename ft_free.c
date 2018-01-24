/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:52:51 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/04 16:46:22 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lst_free(t_dirfile *list)
{
	t_dirfile *temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
		temp = NULL;
	}
	list = NULL;
}

void	ft_ls_freeopt(t_opt *opt)
{
	int i;

	i = 0;
	while (opt->dir[i])
	{
		free(opt->dir[i]);
		i++;
	}
	free(opt->dir);
	opt->dir = NULL;
}
