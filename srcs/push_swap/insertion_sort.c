/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:41:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/06 13:50:14 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int insert_nb(t_ps *p, int nb)
{
		int min;
		int max;
		int	target;

		if (p->size_b < 3 || p->size_a + p->size_b <= 6)
				return push(p, 'b');
		if (p->size_b == 3)
			mini_sort(p, 'b');
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
**	Use only if p->size_a >= 4 && p->size_a <= 6
*/

int insertion_sort(t_ps *p)
{
		int max[3];

		max[0] = p->a[find_max(p, 'a')];
		max[1] = p->a[find_max_capped(p, 'a', max[0])];
		max[2] = p->a[find_max_capped(p, 'a', max[1])];
		while (p->size_a > 3)
		{
				while (p->a[p->size_a - 1] == max[0]
								|| p->a[p->size_a - 1] == max[1]
								|| p->a[p->size_a - 1] == max[2])
						rotate(p, 'a');
				insert_nb(p, p->a[p->size_a - 1]);
		}
		mini_sort(p, 'a');
		if (p->size_b <= 3)
			mini_sort(p, 'b');
		else
			goto_pos(p, find_max(p, 'b'), 'b');
		while (p->size_b)
				push(p, 'a');
		goto_pos(p, find_min(p, 'a'), 'a');
		return (1);
}
