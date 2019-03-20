/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:44:26 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/20 13:23:34 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_a(t_ps *p)
{
		if (p->size_b < 1)
				return (0);
		ft_swap(&p->a[p->size_a++], &p->b[--p->size_b]);
		p->flags_a = 0;
		p->flags_b = 0;
		p->flags_push = 0;
		p->flags_push |= FLAG_PA;
		return (1);
}

static int	push_b(t_ps *p)
{
		if (p->size_a < 1)
				return (0);
		ft_swap(&p->b[p->size_b++], &p->a[--p->size_a]);
		p->flags_a = 0;
		p->flags_b = 0;
		p->flags_push = 0;
		p->flags_push |= FLAG_PB;
		return (1);
}

int			push(t_ps *p, char c)
{
		int		ret;
		char	*cmd;

		ret = 0;
		if (c == 'a')
		{
				cmd = "pa";
				ret = push_a(p);
		}
		else if (c == 'b')
		{
				cmd = "pb";
				ret = push_b(p);
		}
		p->flags & FLAG_SOLVER ? add_operation(&p->op, cmd) : 0;
		return (ret);
}
