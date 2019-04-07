/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:39:30 by sregnard          #+#    #+#             */
/*   Updated: 2019/04/07 10:44:54 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**		Find the index of the given value in the given stack
*/

int		find_pos(t_ps *p, int val, char c)
{
	int		*tab;
	int		size;
	int		pos;

	tab = c == 'a' ? p->a : p->b;
	size = c == 'a' ? p->size_a : p->size_b;
	pos = 0;
	while (pos < size)
		if (tab[pos++] == val)
			return (--pos);
	return (-1);
}

/*
**		Find the value of the given pos
**		If pos is outside array it loops back into it
*/

int		get_val(t_ps *p, int pos, char c)
{
	int		*tab;
	int		size;

	tab = c == 'a' ? p->a : p->b;
	size = c == 'a' ? p->size_a : p->size_b;
	pos += pos < 0 ? size : -size;
	return (tab[pos]);
}

/*
**		Rotate the stack until the value at given index is at the top
**		rotating or rev_rotating depending on which one use less operations
**		Return 1 if successfully rotated until arriving at position
**		Return 0 if stopped because the stack is already sorted
*/

int		goto_pos(t_ps *p, int pos, char c)
{
	int		*tab;
	int		size;
	int		top;
	int		val;
	int		(*f)(t_ps *, char);

	tab = c == 'a' ? p->a : p->b;
	size = c == 'a' ? p->size_a : p->size_b;
	top = size - 1;
	val = tab[pos];
	f = rotate_function(p, pos, c);
	while (tab[top] != val)
		f(p, c);
	return (1);
}

t_rotf	rotate_function(t_ps *p, int pos, char c)
{
	int		*tab;
	int		size;
	int		top;
	int		val;
	int		(*f)(t_ps *, char);

	tab = c == 'a' ? p->a : p->b;
	size = c == 'a' ? p->size_a : p->size_b;
	top = size - 1;
	val = tab[pos];
	f = ((size / 2) / (pos + 1) < 2) ? rotate : rev_rotate;
	return (f);
}

/*
**		Call with c == 'a' for A, check if sorted (top to bottom) 1, 2, 3...
**		Call with c == 'b' for B, check if sorted (top to bottom) 9, 8, 7...
**		if (!(c == 'a' || c == 'b')) check if A is sorted B is empty
**		Anything else to check if A is sorted and B empty
*/

int		sorted(t_ps p, char c, int top, int bottom)
{
	int	*tab;
	int	size;
	int	order;

	order = 1;
	if (c == 'b')
	{
		tab = p.b;
		size = p.size_b;
		order = -1;
	}
	else
	{
		tab = p.a;
		size = p.size_a;
		if (!(c == 'a') && p.size_b != 0)
			return (0);
	}
	c != 'a' && c != 'b' ? top = size : ++top;
	if (top - bottom < 2)
		return (1);
	while (--top > bottom)
		if (tab[top] * order > tab[top - 1] * order)
			return (0);
	return (1);
}
