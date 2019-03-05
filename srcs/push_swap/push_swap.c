/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/05 15:50:55 by sregnard         ###   ########.fr       */
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

static int	sort(t_ps *p)
{
		int	min;
		int	pos;

		while (!sorted(*p, 0))
		{
				if ((pos = find_min(p)) == -1)
						break ;
				min = p->a[pos];
				if ((p->size_a / 2) / (pos + 1) < 2)
						while (p->a[p->size_a - 1] != min)
								rotate_a(p);
				else
						while (p->a[p->size_a - 1] != min)
								rev_rotate_a(p);
				if (sorted(*p, 0))
						return (1);
				if (sorted(*p, 'a'))
						break ;
				push_b(p);
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
		sort(&p);
}
