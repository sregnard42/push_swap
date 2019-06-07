/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:51:39 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/07 15:52:31 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			add_operation(char **operations, char *new_op)
{
		*operations = ft_stradd(*operations, new_op);
		*operations = ft_stradd(*operations, "\n");
		return (1);
}

static int	opti_swap(char **op_a, char **op_b, char *a, char *b)
{
		if ((a[1] == 'a' && b[0] == 'r' && b[ft_strlen(b) - 1] == 'b')
						|| (a[1] == 'b' && b[0] == 'r'
								&& b[ft_strlen(b) - 1] == 'a'))
				return (1);
		if ((ft_strequ(a, "sa") && ft_strequ(b, "sb"))
			   || (ft_strequ(a, "sa") && ft_strequ(b, "sb")))
		{
				ft_strcpy(b, "ss");
				ft_remove_elem_tab(op_a);
				return (0);
		}
		if (ft_strequ(a, "ss"))
		{
				if (ft_strequ(b, "sa"))
						ft_strcpy(b, "sb");
				else if (ft_strequ(b, "sb"))
						ft_strcpy(b, "sa");
				ft_remove_elem_tab(op_a);
				return (0);
		}
		if ((a[1] == 'a' && ft_strequ(b, "sa"))
						|| (a[1] == 'b' && ft_strequ(b, "sb"))
						|| (a[1] == 's' && ft_strequ(b, "ss")))
		{
				ft_remove_elem_tab(op_b);
				ft_remove_elem_tab(op_a);
				return (0);
		}
		return (0);
}

static int	opti_rotate(char **op_a, char **op_b, char *a, char *b)
{
		if (a[1] == 'a' && (ft_strequ(b, "ra") || ft_strequ(b, "rr")
								|| ft_strequ(b, "sb")))
				return (1);
		if (a[1] == 'b' && (ft_strequ(b, "rb") || ft_strequ(b, "rr")
								|| ft_strequ(b, "sa")))
				return (1);
		if ((a[1] == 'a' && ft_strequ(b, "rb"))
						|| (a[1] == 'b' && ft_strequ(b, "ra")))
		{
				ft_strcpy(b, "rr");
				ft_remove_elem_tab(op_a);
				return (0);
		}
		if (ft_strequ(a, "rr"))
		{
				if (ft_strequ(b, "rra"))
						ft_strcpy(b, "rb");
				else if (ft_strequ(b, "rrb"))
						ft_strcpy(b, "ra");
				ft_remove_elem_tab(op_a);
				return (0);
		}
		if ((a[1] == 'a' && ft_strequ(b, "rra"))
						|| (a[1] == 'b' && ft_strequ(b, "rrb")))
		{
				ft_remove_elem_tab(op_b);
				ft_remove_elem_tab(op_a);
				return (0);
		}
		return (0);
}

static int	opti_rev_rotate(char **op_a, char **op_b, char *a, char *b)
{
		if (a[2] == 'a' && (ft_strequ(b, "rra") || ft_strequ(b, "rrr")))
				return (1);
		if (a[2] == 'a' && ft_strequ(b, "sb"))
				return (1);
		if (a[2] == 'b' && (ft_strequ(b, "rrb") || ft_strequ(b, "rrr")))
				return (1);
		if (a[2] == 'b' && ft_strequ(b, "sa"))
				return (1);
		if ((a[2] == 'a' && ft_strequ(b, "rrb"))
						|| (a[2] == 'b' && ft_strequ(b, "rra")))
		{
				ft_strcpy(b, "rrr");
				ft_remove_elem_tab(op_a);
				return (0);
		}
		if ((a[2] == 'a' && ft_strequ(b, "ra"))
						|| (a[2] == 'b' && ft_strequ(b, "rb")))
		{
				ft_remove_elem_tab(op_b);
				ft_remove_elem_tab(op_a);
				return (0);
		}
		return (0);
}

static int	opti_op(char **op)
{
		char	*op_a;
		char	*op_b;
		int		ret;
		int		i;

		i = 0;
		ret = 1;
		op_a = *(op - 1);
		while (op + i && op[i] && ret)
		{
				op_b = *(op + i);
				if (op_a[0] == 's')
						ret = opti_swap(op - 1, op + i, op_a, op_b);
				else if (ft_strlen(op_a) == 2 && op_a[0] == 'r')
						ret = opti_rotate(op - 1, op + i, op_a, op_b);
				else if (ft_strlen(op_a) == 3 && op_a[0] == 'r')
						ret = opti_rev_rotate(op - 1, op + i, op_a, op_b);
				else
						ret = -1;
				if (ret)
						++i;
		}
		return (1);
}

char		**opti_operations(char *operations)
{
		char	**op;
		int		i;

		if(!(ft_strlen(operations) && (op = ft_strsplit(operations, '\n'))))
				return (NULL);
		if (ft_nb_str_tab(op) < 2)
				return (op);
		i = 1;
		while (op + i && op[i])
				opti_op(op + i++);
		return (op);
}
