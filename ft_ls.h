/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:59:23 by tmaraval          #+#    #+#             */
/*   Updated: 2018/01/05 17:09:57 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <dirent.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <locale.h>
# include <langinfo.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <grp.h>
# include <string.h>
# include <errno.h>
# define TRUE 1
# define FALSE 0
# define FT_LS "ft_ls: "
# define BUFF_SIZE 5
# define COLOR TRUE
# define SIXMONTHS ((365 / 2) * 86400)

typedef struct	s_mdate
{
	char day[4];
	char month[4];
	char daynbr[3];
	char hour[6];
	char year[6];
}				t_mdate;

typedef struct	s_opt
{
	int		l;
	int		rec;
	int		a;
	int		r;
	int		t;
	int		g;
	int		one;
	char	**dir;

}				t_opt;

typedef	struct	s_dirfile
{
	char				name[256];
	char				type;
	char				perm[10];
	int					nblink;
	char				*owner;
	char				*group;
	int					size;
	int					major;
	int					minor;
	int					blocknbr;
	time_t				t_mtime;
	t_mdate				date;
	char				lnpath[254];
	struct s_dirfile	*next;

}				t_dirfile;

typedef struct	s_maxvalue
{
	size_t nblink;
	size_t owner;
	size_t group;
	size_t size;
	size_t maj;
	size_t min;
}				t_maxvalue;

void			ft_ls_init_opt(t_opt *opt);
void			ft_ls_get_diropt(t_opt *opt, int i, int arc, char **arv);
void			ft_ls_get_opt(t_opt *opt, int arc, char **arv);
char			ft_ls_conv_type(const struct stat buf);
char			*ft_ls_conv_perm(const struct stat buf);
t_mdate			ft_ls_conv_mdate(const char *str);
int				ft_ls_isdir(char *path);
void			ft_ls_firstcheck(t_opt *opt);
int				ft_ls_print_dir(char *path, t_opt *opt);
void			ft_lstdirfileadd(t_dirfile **alst, t_dirfile *new);
t_dirfile		*ft_dirfilenew(char *filename, struct stat buf, char *catpath);
void			ft_lst_swap(t_dirfile *node1, t_dirfile *node2);
void			ft_lst_sort(t_dirfile *start);
void			ft_ls_freeopt(t_opt *opt);
void			ft_ls_print_mdate(t_mdate mdate, t_dirfile *last);
t_maxvalue		ft_lst_maxdigit(t_dirfile *last);
int				ft_printspace(int max, int len);
void			ft_lst_print(t_dirfile *last, t_opt *opt, int total);
void			ft_lst_free(t_dirfile *list);
char			*ft_getpath(char *path, char *d_name);
void			ft_print_usage(int i, int j, char **arv);
void			ft_ls_perr(char *path);
int				ft_fill_lst(t_dirfile **last, char *path, t_opt *opt);
void			ft_print_simple(t_dirfile *last, t_opt *opt);
int				ft_ls_recur(char *path, t_opt *opt);
void			ft_print_path(char *path, int rec);
void			ft_print_sizeormajmin(t_dirfile *last, t_maxvalue max);
void			ft_sort_optdir(char **dir, int dirnbr);
void			ft_lst_sortedinsert(t_dirfile **last, t_dirfile *new_node);
int				ft_lst_whichsort(char *name, t_dirfile *new_node, t_opt *opt);
void			ft_revlist(t_dirfile **last);
void			ft_lst_sortedinsertbytime(t_dirfile **last,
t_dirfile *new_node);
t_dirfile		*ft_simplefilenew(char *filename, struct stat buf,
char *catpath);
int				ft_get_dirnbr(char **dir);
void			ft_delete_in_tab(char **dir, int index);
double			ft_difftime(time_t v1, time_t v2);
void			ft_print_optarg(t_opt *opt, int originaldirnbr,
int deleteddirnbr);
void			ft_lst_cpyvalue(t_dirfile **new, char *filename,
struct stat buf, char *catpath);
void			ft_init_maxvalue(t_maxvalue *max);
void			ft_lst_manage_itoa(t_dirfile *last, t_maxvalue *max);
void			ft_lst_manage_ln(t_dirfile **new, char *catpath);
void			ft_ls_manage_opt(t_opt *opt, char **arv, int i, int j);
void			ft_ls_manage_err(char **arv, int i, int j);
void			ft_lst_print_ln(t_dirfile *last);
void			ft_print_fname(t_dirfile *node);
void			ft_print_owner(t_dirfile *last, t_maxvalue max);
#endif
