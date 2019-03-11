/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/09 14:36:32 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_ps *p)
{
		int	i;
		int	min;
		int	pos;

		if (p->size_a == 0)
				return (-1);
		i = p->size_a - 1;
		min = p->a[i];
		pos = i;
		while (i--)
				if (min > p->a[i])
				{
						min = p->a[i];
						pos = i;
				}
		return (pos);
}

static int	sort(t_ps *p, int top, int bottom)
{
		int	min;
		int	pos;

		if (top == bottom)
				return (1);
		while (!sorted(*p, 0))
		{
				if ((pos = find_min(p)) == -1)
						break ;
				min = p->a[pos];
				while (p->a[top] != min)
				{
						if (p->a[top - 1] != min && p->a[top] > p->a[top - 1])
								swap_a(p);
						((p->size_a / 2) / (pos + 1) < 2) ? rotate_a(p)
								: rev_rotate_a(p);
				}
				if (sorted(*p, 0))
						return (1);
				if (sorted(*p, 'a'))
						break ;
				push_b(p);
				--top;
		}
		while (p->size_b && push_a(p))
				;
		return (1);
}

int			main(int ac, char **av)
{
		t_ps	p;

		parse_args(&p, ac, av);
		p.flags |= FLAG_SOLVER;
		sort(&p, (p.size_a - 1), 0);
}
