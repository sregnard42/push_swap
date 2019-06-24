/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:51:39 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/24 12:14:39 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_operation(t_ps *p, char *new_op)
{
	t_list	*operation;

	if (opt_operation(p, new_op))
		return (1);
	operation = ft_lstnew(new_op, sizeof(char *));
	!operation ? trigger_error(p, "Error malloc node\n") : 0;
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
