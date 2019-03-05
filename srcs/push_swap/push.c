/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:50:45 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/04 15:50:00 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_sorted(int *stack, int size, int order)
{
		while (--size)
				if (stack[size] * order > stack[size - 1] * order)
						return (0);
		return (1);
}

static int	pa(t_ps *p)
{
		if (p->size_b < 1 || p->flags_b & FLAG_PB)
				return (0);
		return (push_a(p));
}

static int	pb(t_ps *p)
{
		if (p->size_a < 1 || p->flags_a & FLAG_PA)
				return (0);
		return (push_b(p));
}

int	ps_push(t_ps *p)
{
		char	*cmd;

		cmd = NULL;
		if (pa(p))
				cmd = "pa";
		else if(pb(p))
				cmd = "pb";
		ft_putendl(cmd);
		return (cmd != NULL);
}
