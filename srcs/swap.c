/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:34:15 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/08 11:16:04 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_a(t_ps *p)
{
	if (p->size_a < 2)
		return (1);
	ft_swap(p->a + p->size_a - 1, p->a + p->size_a - 2);
	return (1);
}

static int	swap_b(t_ps *p)
{
	if (p->size_b < 2)
		return (1);
	ft_swap(&p->b[p->size_b - 1], &p->b[p->size_b - 2]);
	return (1);
}

int			swap(t_ps *p, char c)
{
	int		ret;
	char	*cmd;

	if (c == 'a')
	{
		cmd = "sa";
		ret = swap_a(p);
	}
	else if (c == 'b')
	{
		cmd = "sb";
		ret = swap_b(p);
	}
	else
	{
		cmd = "ss";
		ret = swap_a(p) && swap_b(p);
	}
	p->flags & FLAG_SOLVER ? add_operation(p, cmd) : 0;
	return (ret);
}
