/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:34:15 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/05 14:59:22 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_a(t_ps *p)
{
		if (p->flags & FLAG_SOLVER)
				p->flags_ab & FLAG_SS ? 0 : ft_putendl("sa");
		if (p->size_a < 2 || p->flags_a & FLAG_SA)
				return (0);
		ft_swap(&p->a[p->size_a - 1], &p->a[p->size_a - 2]);
		p->flags_push = 0;
		p->flags_a = 0;
		p->flags_a |= FLAG_SA;
		return (1);
}

int		swap_b(t_ps *p)
{
		if (p->flags & FLAG_SOLVER)
				p->flags_ab & FLAG_SS ? ft_putendl("ss") : ft_putendl("sb");
		if (p->size_b < 2 || p->flags_b & FLAG_SB)
				return (0);
		ft_swap(&p->b[p->size_b - 1], &p->b[p->size_b - 2]);
		p->flags_ab = 0;
		p->flags_push = 0;
		p->flags_b = 0;
		p->flags_b |= FLAG_SB;
		return (1);
}

int		swap(t_ps *p)
{
		p->flags_ab |= FLAG_SS;
		return (swap_a(p) && swap_b(p));
}
