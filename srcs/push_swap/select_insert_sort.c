/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:25:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/09 11:28:51 by sregnard         ###   ########.fr       */
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

static int	find_target(t_ps *p, int top, int **seg, int nb_seg)
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
		if (s_index < nb_seg)
			return (find_target(p, top, seg, nb_seg));
		return (-1);
}

static int	push_all(t_ps *p, int top, int **seg, int nb_seg)
{
		int			target;

		if (!p->size_a)
				return (1);
		target = find_target(p, top, seg, nb_seg);
		goto_pos(p, target, 'a');
		insert_nb(p, p->a[top]);
		return (push_all(p, --top, seg, nb_seg));
}

static int	**segments(int *tab, int size, int nb_seg)
{
		int		**seg;
		int		i;

		seg = (int **)malloc(sizeof(int *) * nb_seg);
		i = 0;
		while (i < nb_seg)
		{
				seg[i] = (int *)malloc(sizeof(int) * 2);
				seg[i][0] = tab[(int)(size * (1 / (float)nb_seg) * i)];
				seg[i][1] = tab[(int)(size * (1 / (float)nb_seg) * (i + 1) - 1)];
				++i;
		}
		return (seg);
}

/*
**			100 nb -> 5 segments
**			500 nb -> 11 segments
**			segments = (3 / 200) * nb + 3.5
*/

int			select_insert_sort(t_ps *p)
{
		int		*tab;
		int		**seg;
		int		nb_seg;

		tab = sort_tab(p->a, p->size_a);
		nb_seg = (3.0 / 200) * p->size_a + 3.5;
		seg = segments(tab, p->size_a, nb_seg);
		ft_memdel((void **)&tab);
		push_all(p, p->size_a - 1, seg, nb_seg);
		while (p->size_b && push(p, 'a'))
				;
		goto_pos(p, find_min(p, 'a'), 'a');
		return (1);
}
