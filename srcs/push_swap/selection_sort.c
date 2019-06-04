/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:25:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/04 13:14:39 by sregnard         ###   ########.fr       */
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
**	target = min_1 => FLAG_MIN => force target on min_0 next call
**	target = max_1 => FLAG_MAX => force target on max_0 next call
*/

static int	find_target(t_ps *p, int top)
{
	int target;
	int	min[3];
	int	max[3];

	min[0] = find_min(p, 'a');
	max[0] = find_max(p, 'a');
	min[1] = find_min_capped(p, 'a', min[0]);
	max[1] = find_max_capped(p, 'a', max[0]);
	min[2] = (p->flags |= FLAG_MIN  || min[1] == -1) ? min[0]
			: find_closest(top, min[0], min[1]);
	max[2] = (p->flags |= FLAG_MAX  || max[1] == -1) ? max[0]
			: find_closest(top, max[0], max[1]);
	target = find_closest(top, min[2], max[2]);
	if (target == min[0])
			p->flags &= ~FLAG_MIN;
	else if (target == max[0])
			p->flags &= ~FLAG_MIN;
	else if (target == min[1])
			p->flags |= FLAG_MIN;
	else if (target == max[1])
			p->flags |= FLAG_MAX;
	/*
	ft_printf("______________________________\n");
	for (int i = 0; i < 3; i++)
		ft_printf("min[%d] = %d\nmax[%d] = %d\n", i, min[i], i, max[i]);
	ft_printf("target = %d\n", target);
	ft_printf("______________________________\n");
	*/
	return (target);
}

static int	push_all(t_ps *p, int top)
{
	int	target;

	if (!p->size_a)
		return (1);
	target = find_target(p, top);
	goto_pos(p, target, 'a');
	insert_nb(p, p->a[0]);
	return (push_all(p, --top));
}

int			selection_sort(t_ps *p)
{
	push_all(p, p->size_a - 1);
	mini_sort(p, 'a');
	while (p->size_b && push(p, 'a'))
		;
	goto_pos(p, find_min(p, 'a'), 'a');
	return (1);
}
