/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:25:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/03 15:29:29 by sregnard         ###   ########.fr       */
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

/*
**	target = min_1 => *code = 1 => force target on min_0 next call
**	target = max_1 => *code = 2 => force target on max_0 next call
*/

static int	find_target(t_ps *p, int top, int *code)
{
	int target;
	int	min;
	int	max;

	min = find_min(p, 'a');
	if (*code == 1)
	{
		*code = 0;
		return (min);
	}
	max = find_max(p, 'a');
	if (*code == 2)
	{
		*code = 0;
		return (max);
	}
	min = find_closest(top, min, find_min(p, 'a'));
	max = find_closest(top, max, find_max(p, 'a'));
	target = find_closest(top, min, max);
	target == find_min(p, 'a') ? *code = 1 : 0;
	target == find_max(p, 'a') ? *code = 2 : 0;
	return (target);
}

static int	push_all(t_ps *p, int top, int code)
{
	/*
	int	max;
	int	min;
	int	dmin;
	int	dmax;

	if (!p->size_a)
		return (1);
	max = find_max(p, 'a');
	min = find_min(p, 'a');
	dmin = min + 1 < top - min ? min + 1 : top - min;
	dmax = max + 1 < top - max ? max + 1 : top - max;
	dmax < dmin ? goto_pos(p, max, 'a') : goto_pos(p, min, 'a');
	*/
	int	target;

	if (!p->size_a)
		return (1);
	target = find_target(p, top, &code);
	goto_pos(p, target, 'a');
	insert_nb(p, p->a[target]);
	return (push_all(p, --top, code));
}

int			selection_sort(t_ps *p)
{
	push_all(p, p->size_a - 1, 0);
	mini_sort(p, 'a');
	while (p->size_b && push(p, 'a'))
		;
	goto_pos(p, find_min(p, 'a'), 'a');
	return (1);
}
