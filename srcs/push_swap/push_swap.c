/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/03/20 13:26:56 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
		t_ps	p;

		parse_args(&p, ac, av);
		p.flags |= FLAG_SOLVER;
		p.op.operations = NULL;
		p.op.last_op = NULL;
		if (sorted(p, 0, p.size_a - 1, 0))
						exit(EXIT_SUCCESS);
		if (p.size_a <= 3)
				mini_sort(&p, 'a');
		else if (p.size_a <= 5)
			selection_sort(&p);
		else
			quick_sort(&p, p.size_a - 1, 0);
		ft_putstr(p.op.operations);
		exit(EXIT_SUCCESS);
}
