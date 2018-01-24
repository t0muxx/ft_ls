/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:47:15 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/05 11:33:17 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_init_opt(t_opt *opt)
{
	opt->l = 0;
	opt->rec = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	opt->g = 0;
	opt->one = 0;
}

void		ft_ls_manage_opt(t_opt *opt, char **arv, int i, int j)
{
	if (arv[i][j] == 'l')
		opt->l = TRUE;
	if (arv[i][j] == 'R')
		opt->rec = TRUE;
	if (arv[i][j] == 'a')
		opt->a = TRUE;
	if (arv[i][j] == 'r')
		opt->r = TRUE;
	if (arv[i][j] == 't')
		opt->t = TRUE;
	if (arv[i][j] == 'g')
		opt->g = TRUE;
}

void		ft_ls_manage_err(char **arv, int i, int j)
{
	if ((ft_strchr("-lRart1g", arv[i][j]) == NULL) ||
		(ft_strstr(arv[i], "--") != NULL)
	|| (ft_strstr(arv[i], "--") != NULL)
	|| (ft_strchr(arv[i] + 1, '-')))
	{
		ft_print_usage(i, j, arv);
		exit(EXIT_FAILURE);
	}
}
