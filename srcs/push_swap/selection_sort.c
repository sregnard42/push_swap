/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:25:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/14 12:50:47 by sregnard         ###   ########.fr       */
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

int			selection_sort(t_ps *p)
{
		int top;
		int	min;
		int	pos;

		top = p->size_a - 1;
		while (!sorted(*p, 0))
		{
				if ((pos = find_min(p)) == -1)
						break ;
				min = p->a[pos];
				while (p->a[top] != min)
						((p->size_a / 2) / (pos + 1) < 2) ? rotate_a(p)
								: rev_rotate_a(p);
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
