/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:44:26 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/04 16:04:22 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int		push_a(t_ps *p)
{
		if (p->flags & FLAG_SOLVER)
				ft_putendl("pa");
		if (p->size_b < 1 || p->flags_b & FLAG_PB)
				return (0);
		ft_swap(p->a + p->size_a++, p->b + --p->size_b);
		p->flags_b = 0;
		p->flags_a = 0;
		p->flags_push = 0;
		p->flags_push |= FLAG_PA;
		return (1);
}

int		push_b(t_ps *p)
{
		if (p->flags & FLAG_SOLVER)
				ft_putendl("pb");
		if (p->size_a < 1 || p->flags_a & FLAG_PA)
				return (0);
		ft_swap(p->b + p->size_b++, p->a + --p->size_a);
		p->flags_a = 0;
		p->flags_b = 0;
		p->flags_push = 0;
		p->flags_push |= FLAG_PB;
		return (1);
}
