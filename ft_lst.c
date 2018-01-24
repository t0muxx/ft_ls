/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:54:25 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/08 08:24:58 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lst_swap(t_dirfile *node1, t_dirfile *node2)
{
	t_dirfile	temp;
	size_t		lenght;

	lenght = sizeof(t_dirfile) - sizeof(t_dirfile *);
	ft_memcpy(&temp, node1, lenght);
	ft_memcpy(node1, node2, lenght);
	ft_memcpy(node2, &temp, lenght);
}

t_maxvalue	ft_lst_maxdigit(t_dirfile *last)
{
	t_maxvalue	max;

	ft_init_maxvalue(&max);
	while (last)
	{
		ft_lst_manage_itoa(last, &max);
		if (ft_strlen(last->owner) > max.owner)
			max.owner = ft_strlen(last->owner);
		if (ft_strlen(last->group) > max.group)
			max.group = ft_strlen(last->group);
		last = last->next;
	}
	return (max);
}

void		ft_lstdirfileadd(t_dirfile **alst, t_dirfile *new)
{
	new->next = *alst;
	*alst = new;
}

void		ft_lst_cpyvalue(t_dirfile **new, char *filename, struct stat buf,
char *catpath)
{
	struct passwd	*usr;
	struct group	*grp;

	ft_strcpy((*new)->name, filename);
	(*new)->type = ft_ls_conv_type(buf);
	ft_strcpy((*new)->perm, ft_ls_conv_perm(buf));
	(*new)->perm[9] = '\0';
	(*new)->nblink = (int)buf.st_nlink;
	if ((usr = getpwuid(buf.st_uid)) == NULL)
		(*new)->owner = ft_itoa(buf.st_uid);
	else
		(*new)->owner = ft_strdup(usr->pw_name);
	if ((grp = getgrgid(buf.st_gid)) == NULL)
		(*new)->group = ft_itoa(buf.st_gid);
	else
		(*new)->group = ft_strdup(grp->gr_name);
	(*new)->size = (int)buf.st_size;
	(*new)->date = ft_ls_conv_mdate(ctime(&buf.st_mtime));
	(*new)->blocknbr = (int)buf.st_blocks;
	(*new)->major = major(buf.st_rdev);
	(*new)->minor = minor(buf.st_rdev);
	(*new)->t_mtime = buf.st_mtime;
	ft_lst_manage_ln(new, catpath);
}

t_dirfile	*ft_dirfilenew(char *filename, struct stat buf, char *catpath)
{
	t_dirfile *new;

	if (!(new = malloc(sizeof(t_dirfile))))
		return (NULL);
	if (filename == NULL)
		return (NULL);
	else
	{
		ft_lst_cpyvalue(&new, filename, buf, catpath);
	}
	new->next = NULL;
	return (new);
}
