/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:41:15 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/05 11:52:14 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_fname(t_dirfile *node)
{
	if (COLOR == TRUE)
	{
		if (node->type == 'd')
			ft_putstr_color(node->name, ANSI_COLOR_CYAN);
		else if (node->type == 'l')
			ft_putstr_color(node->name, ANSI_COLOR_PURPLE);
		else if (node->type == 'c')
			ft_putstr_color(node->name, ANSI_COLOR_BLUE_ON_YELLOW);
		else if (node->type == 'b')
			ft_putstr_color(node->name, ANSI_COLOR_BLUE_ON_YELLOW);
		else if (ft_strchr(node->perm, 'x') != NULL)
			ft_putstr_color(node->name, ANSI_COLOR_RED);
		else
			ft_putstr(node->name);
	}
	else
		ft_putstr(node->name);
}

void	ft_print_owner(t_dirfile *last, t_maxvalue max)
{
	ft_putstr(last->owner);
	ft_printspace(max.owner, ft_strlen(last->owner));
	ft_strdel(&(last->owner));
	ft_putstr("  ");
}
