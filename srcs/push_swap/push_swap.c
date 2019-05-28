/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:37:09 by sregnard          #+#    #+#             */
/*   Updated: 2019/05/28 19:28:33 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps p;

	parse_args(&p, ac, av);
	p.flags |= FLAG_SOLVER;
	p.operations = NULL;
	if (sorted(p, 0, p.size_a - 1, 0))
		exit(EXIT_SUCCESS);
	if (p.size_a <= 3)
		mini_sort(&p, 'a');
	else if (p.size_a <= 5)
		insertion_sort(&p);
	else
		//selection_sort(&p);
		quick_sort(&p, p.size_a - 1, 0);
	ft_print_tab(opti_operations(p.operations));
	exit(EXIT_SUCCESS);
}
