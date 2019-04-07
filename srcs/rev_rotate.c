/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:46:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/04/07 10:44:44 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	All elements are shifted down, the bottom-most element is put at the top
*/

static int	rev_rotate_a(t_ps *p)
{
	int	i;

	if (p->size_a < 2)
		return (0);
	i = 0;
	while (++i < p->size_a)
		ft_swap(&p->a[i], &p->a[i - 1]);
	return (1);
}

static int	rev_rotate_b(t_ps *p)
{
	int	i;

	if (p->size_b < 2)
		return (0);
	i = 0;
	while (++i < p->size_b)
		ft_swap(&p->b[i], &p->b[i - 1]);
	return (1);
}

int			rev_rotate(t_ps *p, char c)
{
	int		ret;
	char	*cmd;

	if (c == 'a')
	{
		cmd = "rra";
		ret = rev_rotate_a(p);
	}
	else if (c == 'b')
	{
		cmd = "rrb";
		ret = rev_rotate_b(p);
	}
	else
	{
		cmd = "rrr";
		ret = rev_rotate_a(p) && rev_rotate_b(p);
	}
	p->flags & FLAG_SOLVER ? add_operation(&p->operations, cmd) : 0;
	return (ret);
}
