/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:51:39 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/09 15:01:02 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
						ft_strcpy(op, "rrr");
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
						ft_strcpy(op, "rr");
						return (1);
				}
				operation = operation->prev;
		}
		return (0);
}

/*
**		Returns 1 if optimization successful
*/

static int	opt_operation(t_ps *p, char *op)
{
		if (!p->operation_first || !p->operation_last)
				return (0);
		if (op[0] != 'r')
				return (0);
		if (ft_strequ(op, "rb"))
				return (opt_rotate(p));
		if (ft_strequ(op, "rrb"))
				return (opt_rev_rotate(p));
		return (0);
}

int			add_operation(t_ps *p, char *new_op)
{
		t_list	*operation;

		if (opt_operation(p, new_op))
				return (1);
		operation = ft_lstnew(new_op, sizeof(char *));
		!operation ? trigger_error("Error malloc node\n") : 0;
		if (!p->operation_first)
		{
				p->operation_first = operation;
				p->operation_last = operation;
				return (1);
		}
		ft_lstadd(&p->operation_last, operation);
		p->operation_last = p->operation_last->next;
		return (1);
}

void	del_operation(void **content, size_t content_size)
{
		content_size += 0;
		ft_memdel(content);
}
