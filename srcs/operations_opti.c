/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_opti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:56:44 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/24 12:14:54 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**		Returns 1 if optimization successful
*/

static int	opt_push(t_ps *p)
{
	t_list	*operation;
	char	*op;

	operation = p->operation_last;
	op = operation->content;
	if (ft_strequ(op, "pb"))
	{
		p->operation_last = operation->prev;
		ft_lstdelone(&operation, &del_operation);
		return (1);
	}
	return (0);
}

/*
**		Returns 1 if optimization successful
*/

static int	opt_rev_rotate(t_ps *p)
{
	t_list	*operation;
	char	*op;

	operation = p->operation_last;
	while (operation)
	{
		op = operation->content;
		if (ft_strlen(op) == 2)
			return (0);
		if (ft_strequ(op, "rra"))
		{
			op[2] = 'r';
			return (1);
		}
		operation = operation->prev;
	}
	return (0);
}

/*
**		Returns 1 if optimization successful
*/

static int	opt_rotate(t_ps *p)
{
	t_list	*operation;
	char	*op;

	operation = p->operation_last;
	while (operation)
	{
		op = operation->content;
		if (ft_strlen(op) == 3)
			return (0);
		if (op[0] == 'p' || op[0] == 's')
			return (0);
		if (ft_strequ(op, "ra"))
		{
			op[1] = 'r';
			return (1);
		}
		operation = operation->prev;
	}
	return (0);
}

/*
**		Returns 1 if optimization successful
*/

int			opt_operation(t_ps *p, char *op)
{
	if (!p->operation_first || !p->operation_last)
		return (0);
	if (ft_strequ(op, "pa"))
		return (opt_push(p));
	if (ft_strequ(op, "rb"))
		return (opt_rotate(p));
	if (ft_strequ(op, "rrb"))
		return (opt_rev_rotate(p));
	return (0);
}
