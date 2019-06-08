/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:45:55 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/08 11:15:25 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	All elements are shifted up, the top-most element is put at the bottom
*/

static int	rotate_a(t_ps *p)
{
	int	i;

	if (p->size_a < 2)
		return (1);
	i = p->size_a;
	while (--i > 0)
		ft_swap(&p->a[i], &p->a[i - 1]);
	return (1);
}

static int	rotate_b(t_ps *p)
{
	int	i;

	if (p->size_b < 2)
		return (1);
	i = p->size_b;
	while (--i > 0)
		ft_swap(&p->b[i], &p->b[i - 1]);
	return (1);
}

int			rotate(t_ps *p, char c)
{
	int		ret;
	char	*cmd;

	if (c == 'a')
	{
		cmd = "ra";
		ret = rotate_a(p);
	}
	else if (c == 'b')
	{
		cmd = "rb";
		ret = rotate_b(p);
	}
	else
	{
		cmd = "rr";
		ret = rotate_a(p) && rotate_b(p);
	}
	p->flags & FLAG_SOLVER ? add_operation(p, cmd) : 0;
	return (ret);
}
