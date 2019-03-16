/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:44:26 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/15 13:28:06 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_a(t_ps *p)
{
		if (p->flags & FLAG_SOLVER)
				ft_putendl("pa");
		if (p->size_b < 1)
				return (0);
		ft_swap(&p->a[p->size_a++], &p->b[--p->size_b]);
		p->flags_a = 0;
		p->flags_b = 0;
		p->flags_push = 0;
		p->flags_push |= FLAG_PA;
		return (1);
}

int		push_b(t_ps *p)
{
		if (p->flags & FLAG_SOLVER)
				ft_putendl("pb");
		if (p->size_a < 1)
				return (0);
		ft_swap(&p->b[p->size_b++], &p->a[--p->size_a]);
		p->flags_a = 0;
		p->flags_b = 0;
		p->flags_push = 0;
		p->flags_push |= FLAG_PB;
		return (1);
}
