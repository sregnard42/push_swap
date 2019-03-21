/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:46:27 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/21 15:26:50 by sregnard         ###   ########.fr       */
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

typedef struct	s_ps
{
		char	*operations;
		int		*a;
		int		*b;
		int		size_a;
		int		size_b;
		int		flags;
}				t_ps;

enum			e_flags
{
				FLAG_DISPLAY = (1 << 0),
				FLAG_COLOR = (1 << 1),
				FLAG_SOLVER = (1 << 2),
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
int				(*rotate_function(t_ps *p, int pos, char c))(t_ps *p, char);
int				sorted(t_ps p, char c, int top, int bottom);

/*
**				operations.c
*/

int				add_operation(char **operations, char *new_op);
char			**opti_operations(char **operations);

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
