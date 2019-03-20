/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:25:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/20 12:38:39 by sregnard         ###   ########.fr       */
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

static int	select_min(t_ps *p, int top)
{
		int	pos;

		if (sorted(*p, 'a', p->size_a - 1, 0))
				return (1);
		pos = find_min(p);
		if (!(goto_pos(p, pos, 'a')))
				return (1);
		push(p, 'b');
		return (select_min(p, --top));
}

int			selection_sort(t_ps *p)
{
		select_min(p, p->size_a - 1);
		while (p->size_b && push(p, 'a'))
				;
		return (1);
}
