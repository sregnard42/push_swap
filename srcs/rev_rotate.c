/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:46:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/05 13:27:53 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int		rev_rotate_a(t_ps *p)
{
		int	i;

		if (p->flags & FLAG_SOLVER)
				p->flags_ab & FLAG_RRR ? 0 : ft_putendl("rra");
		if (p->size_a < 2 || p->flags_a & FLAG_RA)
				return (0);
		i = 0;
		while (++i < p->size_a)
			ft_swap(&p->a[i], &p->a[i - 1]);
		p->flags_push = 0;
		p->flags_a = 0;
		p->flags_a |= FLAG_RRA;
		return (1);
}

int		rev_rotate_b(t_ps *p)
{
		int	i;

		if (p->flags & FLAG_SOLVER)
				p->flags_ab & FLAG_RRR ? ft_putendl("rrr") : ft_putendl("rrb");
		if (p->size_b < 2 || p->flags_b & FLAG_RB)
				return (0);
		i = 0;
		while (++i < p->size_b)
			ft_swap(&p->b[i], &p->b[i - 1]);
		p->flags_ab = 0;
		p->flags_push = 0;
		p->flags_b = 0;
		p->flags_b |= FLAG_RRB;
		return (1);
}

int		rev_rotate(t_ps *p)
{
		p->flags_ab |= FLAG_RRR;
		return (rev_rotate_a(p) && rev_rotate_b(p));
}
