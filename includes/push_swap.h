/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:46:27 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/11 13:18:50 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "time.h"

# define DEBUG			1
# define ERR_DEFAULT	"Error\n"

# define SLP_NONE		0
# define SLP_SHORT		0.1 * 1000000
# define SLP_NORMAL		1 * 1000000
# define SLP_LONG		2 * 1000000

# define LINES_LIMIT	46
# define COLS_LIMIT		11

typedef struct	s_ps
{
	t_list		*operation_first;
	t_list		*operation_last;
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
	int			flags;
}				t_ps;

typedef struct	s_stack
{
	int			*tab;
	int			size;
}				t_stack;

enum			e_flags
{
	FLAG_DISPLAY = (1 << 0),
	FLAG_COLOR = (1 << 1),
	FLAG_SOLVER = (1 << 2),
	FLAG_MIN = (1 << 3),
	FLAG_MAX = (1 << 4),
};

typedef int		(*t_rotf)(t_ps *, char);

/*
**				parsing.c
*/

void			parse_args(t_ps *p, int ac, char **av);

/*
**				display.c
*/

void			trigger_error(char *error);
void			print_stacks(t_ps p, char *s, float interval);

/*
**				utils.c
*/

int				find_pos(t_ps *p, int val, char c);
int				get_val(t_ps *p, int pos, char c);
int				goto_pos(t_ps *p, int pos, char c);
t_rotf			rotate_function(t_ps *p, int pos, char c);
int				sorted(t_ps p, char c, int top, int bottom);

/*
**				min_max.c
*/

int				find_min(t_ps *p, char c);
int				find_max(t_ps *p, char c);
int				find_min_capped(t_ps *p, char c, int cap);
int				find_max_capped(t_ps *p, char c, int cap);
int				find_closest(int top, int tar1, int tar2);

/*
**				Operations
*/

int				add_operation(t_ps *p, char *new_op);
int				opt_operation(t_ps *p, char *op);
void			del_operation(void **content, size_t content_size);

/*
**				Instructions
*/

int				push(t_ps *p, char c);
int				swap(t_ps *p, char c);
int				rotate(t_ps *p, char c);
int				rev_rotate(t_ps *p, char c);

/*
**				Sorting algorithms
*/

/*
**				Use when list size <= 3
*/

int				mini_sort(t_ps *p, char c);

/*
**				Use when list size <= 6
*/

int				insertion_sort(t_ps *p);

/*
**				Use when list size > 6
*/

int				*sort_tab(int *tab, int size);
int				select_insert_sort(t_ps *p);

#endif
