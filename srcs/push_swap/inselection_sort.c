/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inselection_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:25:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/06 15:29:11 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int insert_nb(t_ps *p, int nb)
{
		int min;
		int max;
		int	target;

		if (p->size_b < 2)
				return push(p, 'b');
		min = find_min(p, 'b');
		max = find_max(p, 'b');
		if (nb < p->b[min] || nb > p->b[max])
				target = max;
		else
				target = find_max_capped(p, 'b', nb);
		goto_pos(p, target, 'b');
		push(p, 'b');
		return (1);
}

static int	find_target(t_ps *p, int top, int seg[5][2])
{
		static int	s_index = 0;
		int			left;
		int			right;
		int			nb;
		int			i;

		left = seg[s_index][0];
		right = seg[s_index][1];
		i = 0;
		while (i < p->size_a / 2 + 1)
		{
				nb = p->a[top - i];
				if (left <= nb && nb <= right)
						return (top - i);
				nb = p->a[i];
				if (left <= nb && nb <= right)
						return (i);
				++i;
		}	
		++s_index;
		if (s_index < 5)
			return (find_target(p, top, seg));
		return (-1);
}

static int	push_all(t_ps *p, int top, int seg[5][2])
{
		int			target;

		if (!p->size_a)
				return (1);
		target = find_target(p, top, seg);
		goto_pos(p, target, 'a');
		insert_nb(p, p->a[top]);
		return (push_all(p, --top, seg));
}

static int	segments(int *tab, int size, int seg[5][2])
{
		int		i;

		i = 0;
		while (i < 5)
		{
				seg[i][0] = tab[(int)(size * 0.2 * i)];
				seg[i][1] = tab[(int)(size * 0.2 * (i + 1) - 1)];
				++i;
		}
		return (1);
}

int			inselection_sort(t_ps *p)
{
		int		*tab;
		int		seg[5][2];

		tab = sort_tab(p->a, p->size_a);
		segments(tab, p->size_a, seg);
		push_all(p, p->size_a - 1, seg);
		while (p->size_b && push(p, 'a'))
				;
		goto_pos(p, find_min(p, 'a'), 'a');
		return (1);
}
