/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:45:55 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/16 13:10:33 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_a(t_ps *p)
{
		int	i;

		if (p->flags & FLAG_SOLVER)
				p->flags_ab & FLAG_RR ? 0 : ft_putendl("ra");
		if (p->size_a < 2)
				return (0);
		i = p->size_a;
		while (--i > 0)
			ft_swap(&p->a[i], &p->a[i - 1]);
		p->flags_push = 0;
		p->flags_a = 0;
		p->flags_a |= FLAG_RA;
		return (1);
}

int		rotate_b(t_ps *p)
{
		int	i;

		if (p->flags & FLAG_SOLVER)
				p->flags_ab & FLAG_RR ? ft_putendl("rr") : ft_putendl("rb");
		if (p->size_b < 2)
				return (0);
		i = p->size_b;
		while (--i > 0)
			ft_swap(&p->b[i], &p->b[i - 1]);
		p->flags_ab = 0;
		p->flags_push = 0;
		p->flags_b = 0;
		p->flags_b |= FLAG_RB;
		return (1);
}

int		rotate(t_ps *p)
{
		p->flags_ab |= FLAG_RR;
		return (rotate_a(p) && rotate_b(p));
}
