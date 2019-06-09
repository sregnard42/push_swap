/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/09 11:27:57 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	p;
	t_list	*operation;

	parse_args(&p, ac, av);
	p.flags |= FLAG_SOLVER;
	p.operation_first = NULL;
	p.operation_last = NULL;
	if (sorted(p, 0, p.size_a - 1, 0))
		exit(EXIT_SUCCESS);
	if (p.size_a <= 3)
		mini_sort(&p, 'a');
	else if (p.size_a <= 6)
		insertion_sort(&p);
	else
		select_insert_sort(&p);
	operation = p.operation_first;
	while (operation)
	{
		ft_putendl((char *)operation->content);
		operation = operation->next;
	}
	exit(EXIT_SUCCESS);
}
