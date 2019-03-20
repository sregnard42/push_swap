/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:51:39 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/20 13:32:50 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	replace_last_char(t_op *op, char c)
{
		char	*p;

		p = op->operations + ft_strlen(op->operations - 2);
		*p = c;
		ft_memdel((void **)&op->last_op);
		return (1);
}

static int	opti_op(t_op *op, char *new_op)
{
		if (!(op->last_op))
				return (0);
		if (ft_strequ(new_op, "sa") || ft_strequ(op->last_op, "sa"))
				if (ft_strequ(new_op, "sb") || ft_strequ(op->last_op, "sb"))
						return (replace_last_char(op, 's'));
		if (ft_strequ(new_op, "ra") || ft_strequ(op->last_op, "ra"))
				if (ft_strequ(new_op, "rb") || ft_strequ(op->last_op, "rb"))
						return (replace_last_char(op, 'r'));
		if (ft_strequ(new_op, "rra") || ft_strequ(op->last_op, "rra"))
				if (ft_strequ(new_op, "rrb") || ft_strequ(op->last_op, "rrb"))
						return (replace_last_char(op, 'r'));
		return (0);
}

int			add_operation(t_op *op, char *new_op)
{
		if (opti_op(op, new_op))
				return (1);
		op->last_op = new_op;
		op->operations = ft_stradd(op->operations, new_op);
		op->operations = ft_stradd(op->operations, "\n");
		return (1);
}
