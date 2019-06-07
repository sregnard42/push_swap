/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/06/07 15:49:10 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	p;

	parse_args(&p, ac, av);
	p.flags |= FLAG_SOLVER;
	p.operations = NULL;
	if (sorted(p, 0, p.size_a - 1, 0))
		exit(EXIT_SUCCESS);
	if (p.size_a <= 3)
		mini_sort(&p, 'a');
	else if (p.size_a <= 6)
		insertion_sort(&p);
	else
		inselection_sort(&p);
//	ft_print_tab(opti_operations(p.operations));
	ft_putendl(p.operations);
	exit(EXIT_SUCCESS);
}
