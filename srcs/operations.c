/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:51:39 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/08 15:42:45 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	opt_rotate(char *op, char c)
{
		//	ft_printf("%s & r%c\n", op, c);
		if (c == 'a')
		{
				if (ft_strequ(op, "ra"))
						return (0);
				if (ft_strequ(op, "rb"))
				{
						ft_strcpy(op, "rr");
						return (1);
				}
				if (ft_strequ(op, "rr"))
						return (0);
				if (ft_strequ(op, "rra"))
						return (2);
				if (ft_strequ(op, "rrb"))
						return (-1);
				if (ft_strequ(op, "rrr"))
				{
						ft_strcpy(op, "rb");
						return (1);
				}
		}
		if (c == 'b')
		{
				/*
				if (ft_strequ(op, "rb"))
						return (0);
				if (ft_strequ(op, "ra"))
				{
						ft_strcpy(op, "rr");
						return (1);
				}
				if (ft_strequ(op, "rr"))
						return (0);
				if (ft_strequ(op, "rrb"))
						return (2);
				if (ft_strequ(op, "rra"))
						return (-1);
				if (ft_strequ(op, "rrr"))
				{
						ft_strcpy(op, "ra");
						return (1);
				}
				*/
		}
		return (0);
}

/*
 **			return value > 0 : stop add
 **			return value <= 0 : continue add
 */

static int	opt_rev_rotate(char *op, char c)
{
		//	ft_printf("%s & rr%c\n", op, c);
		op += 0;
		c += 0;
		return (0);
}

/*
 **			return value > 0 : stop add
 **			return value <= 0 : continue add
 */

static int	opt_operation(t_ps *p, char *new_op)
{
		t_list	*operation;
		char	*op;
		int		ret;

		ret = 0;
		operation = p->operation_last;
		while (operation && !ret)
		{
				op = operation->content;
				if (op[0] == 'p' || new_op[0] == 'p')
						return (0);
				if (new_op[0] == 's')
						return (0);
				if (ft_strequ(new_op, "ra") || ft_strequ(new_op, "rb"))
						ret = (opt_rotate(op, new_op[1]));
				if (ft_strequ(new_op, "rra") || ft_strequ(new_op, "rrb"))
						ret = (opt_rev_rotate(op, new_op[2]));
				if (!ret)
					operation = operation->prev;
				//		ft_printf("ret = %d\n\n", ret);
		}
		if (ret == 2)
		{
				if (p->operation_first == operation)
						p->operation_first = operation->next;
				ft_lstdelone(&operation, &del_operation);
		}
		return (ret);
}

int			add_operation(t_ps *p, char *new_op)
{
		t_list	*operation;

		if (p->operation_first && opt_operation(p, new_op))
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
