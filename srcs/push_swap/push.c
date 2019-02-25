/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:50:45 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 14:23:42 by sregnard         ###   ########.fr       */
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
		p->size_b < 1 ? ft_printf("size_b = %d\n", p->size_b) : 0;
		if (stack_sorted(p->a, p->size_a, 1)
						&& stack_sorted(p->b, p->size_b, -1))
		{
				p->size_b < 1 ? ft_printf("size_b = %d\n", p->size_b) : 0;
				return (push_a(p));
		}
		return (0);
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
		int		a;
		int		b;

		cmd = NULL;
		a = pa(p);
		b = pb(p);
		if (a)
				cmd = "pa";
		else if (b)
				cmd = "pb";
		ft_putendl(cmd);
		return (cmd != NULL);
}
