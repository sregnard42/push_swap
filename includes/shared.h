/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:46:27 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 16:30:16 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "libft.h"

# define DEBUG			1
# define ERR_DEFAULT	"Error\n"

typedef struct	s_ps
{
		int		*a;
		int		*b;
		int		size_a;
		int		size_b;
		int		flags_a;
		int		flags_b;
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
				FLAG_SA = (1 << 1),
				FLAG_RA = (1 << 2),
				FLAG_RRA = (1 << 3),
};

enum			e_flags_b
{
				FLAG_SB = (1 << 1),
				FLAG_RB = (1 << 2),
				FLAG_RRB = (1 << 3),
};

void			trigger_error(char *error);
void			parse_args(t_ps *p, int ac, char **av);
void			print_stacks(t_ps p, char *s, int interval);
int				sorted(t_ps p);

int				swap_a(t_ps *p);
int				swap_b(t_ps *p);
int				swap(t_ps *p);

int				push_a(t_ps *p);
int				push_b(t_ps *p);

int				rotate_a(t_ps *p);
int				rotate_b(t_ps *p);
int				rotate(t_ps *p);

int				rev_rotate_a(t_ps *p);
int				rev_rotate_b(t_ps *p);
int				rev_rotate(t_ps *p);

#endif
