/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:46:27 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/20 13:20:41 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define DEBUG			1
# define ERR_DEFAULT	"Error\n"

# define SLP_NONE		0
# define SLP_SHORT		1
# define SLP_LONG		2

# define LINES_LIMIT	42

typedef struct	s_op
{
		char	*operations;
		char	*last_op;
}				t_op;

typedef struct	s_ps
{
		t_op	op;
		int		*a;
		int		*b;
		int		size_a;
		int		size_b;
		int		flags_a;
		int		flags_b;
		int		flags_ab;
		int		flags_push;
		int		flags;
}				t_ps;

enum			e_flags
{
				FLAG_DISPLAY = (1 << 0),
				FLAG_COLOR = (1 << 1),
				FLAG_SOLVER = (1 << 2),
};

enum			e_flags_push
{
				FLAG_PA = (1 << 0),
				FLAG_PB = (1 << 1),
};

enum			e_flags_a
{
				FLAG_SA = (1 << 0),
				FLAG_RA = (1 << 1),
				FLAG_RRA = (1 << 2),
};

enum			e_flags_b
{
				FLAG_SB = (1 << 0),
				FLAG_RB = (1 << 1),
				FLAG_RRB = (1 << 2),
};

enum			e_flags_ab
{
				FLAG_SS = (1 << 1),
				FLAG_RR = (1 << 2),
				FLAG_RRR = (1 << 3),
};

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
int				sorted(t_ps p, char c, int top, int bottom);

/*
**				operations.c
*/

int				add_operation(t_op *op, char *new_op);

/*
**				Allowed operations
*/

int				push(t_ps *p, char c);
int				swap(t_ps *p, char c);
int				rotate(t_ps *p, char c);
int				rev_rotate(t_ps *p, char c);

/*
**				Sorting algorithms
*/

int				mini_sort(t_ps *p, char c);
int				selection_sort(t_ps *p);
int				quick_sort(t_ps *p, int top, int bottom);

#endif
