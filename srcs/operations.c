/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:51:39 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/17 21:36:54 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			add_operation(char **operations, char *new_op)
{
		*operations = ft_stradd(*operations, new_op);
		*operations = ft_stradd(*operations, "\n");
		return (1);
}

static int	next(char *op_a, char *op_b)
{
		if (!(op_a && *op_a && op_b && *op_b))
				return (0);
		if (ft_strequ(op_b, "pa") || ft_strequ(op_b, "pb"))
				return (0);
		if (ft_strequ(op_a, "sa") || ft_strequ(op_b, "sa"))
				if (ft_strequ(op_a, "sb") || ft_strequ(op_b, "sb"))
						return (2);
		if (ft_strequ(op_a, "ra") || ft_strequ(op_b, "ra"))
				if (ft_strequ(op_a, "rb") || ft_strequ(op_b, "rb"))
						return (3);
		if (ft_strequ(op_a, "rra") || ft_strequ(op_b, "rra"))
				if (ft_strequ(op_a, "rrb") || ft_strequ(op_b, "rrb"))
						return (4);
		return (1);
}

static int	cancel(char *op_a, char *op_b)
{
		if (!(op_a && *op_a && op_b && *op_b))
				return (0);
		if (ft_strequ(op_b, "pa") || ft_strequ(op_b, "pb"))
				return (0);
		if (ft_strequ(op_a, "rra") || ft_strequ(op_b, "rra"))
				if (ft_strequ(op_a, "ra") || ft_strequ(op_b, "ra"))
						return (1);
		if (ft_strequ(op_a, "rrb") || ft_strequ(op_b, "rrb"))
				if (ft_strequ(op_a, "rb") || ft_strequ(op_b, "rb"))
						return (1);
		if (ft_strequ(op_a, "sa") && ft_strequ(op_b, "sa"))
				return (1);
		if (ft_strequ(op_a, "sb") && ft_strequ(op_b, "sb"))
				return (1);
		return (0);
}

static int	opti_op(char **op)
{
		char	*op_a;
		char	*op_b;
		int		ret;

		if (ft_strequ(*op, "pa") || ft_strequ(*op, "pb"))
				return (0);
		op_a = *(op - 1);
		op_b = *op;
		if (cancel(op_a, op_b))
		{
				ft_remove_elem_tab(op - 1);
				ft_remove_elem_tab(op - 1);
				return (1);
		}
		ret = next(op_a, op_b);
		if (ret == 0 || ret == 1)
				return (0);
		ft_remove_elem_tab(op);
		ret == 2 ? ft_strcpy(op_a, "ss") : 0;
		ret == 3 ? ft_strcpy(op_a, "rr") : 0;
		ret == 4 ? ft_strcpy(op_a, "rrr") : 0;
		return (1);
}

char		**opti_operations(char *operations)
{
		char	**op;
		int		i;

		if (!ft_strlen(operations))
				return (NULL);
		if (!(op = ft_strsplit(operations, '\n')))
				return (NULL);
		if (ft_nb_str_tab(op) < 2)
				return (op);
		i = 1;
		while (op + i && op[i])
				opti_op(op + i++);
		i = 0;
		while (op + i && op[i])
		{
				if (!ft_strlen(op[i]))
						op[i] = op[i];
				i++;
		}
		return (op);
}
