/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 08:07:14 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/04 18:04:57 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lst_sortedinsert(t_dirfile **last, t_dirfile *new_node)
{
	t_dirfile	*current;

	if (*last == NULL || ft_strcmp((*last)->name, new_node->name) >= 0)
	{
		new_node->next = *last;
		*last = new_node;
	}
	else
	{
		current = *last;
		while (current->next != NULL &&
		ft_strcmp(current->next->name, new_node->name) < 0)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

double	ft_difftime(time_t v1, time_t v2)
{
	return ((double)v1 - (double)v2);
}

void	ft_lst_sortedinsertbytime(t_dirfile **last, t_dirfile *new_node)
{
	t_dirfile	*current;

	if (*last == NULL || ft_difftime((*last)->t_mtime, new_node->t_mtime) < 0)
	{
		new_node->next = *last;
		*last = new_node;
	}
	else
	{
		current = *last;
		while (current->next != NULL &&
		ft_difftime(current->next->t_mtime, new_node->t_mtime) >= 0)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
		if (ft_strcmp(current->name, new_node->name) > 0
		&& ft_difftime(current->t_mtime, new_node->t_mtime) == 0)
			ft_lst_swap(current, new_node);
	}
}

void	ft_revlist(t_dirfile **last)
{
	t_dirfile *prev;
	t_dirfile *current;
	t_dirfile *next;

	prev = NULL;
	current = *last;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*last = prev;
}
