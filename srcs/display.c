/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:14:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/25 16:34:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void		trigger_error(char *error)
{
		if (!error || !DEBUG)
				error = ERR_DEFAULT;
		write(2, error, ft_strlen(error));
		exit(EXIT_FAILURE);
}

void		print_stacks(t_ps p, char *s, int interval)
{
		system("clear");
		ft_putendl(s);
		ft_printf(" ______________ \t ______________ \n");
		ft_printf("/ %12s \\\t/ %-12s \\\n", "A", "B");
		ft_printf("----------------\t----------------\n");
		--p.size_a;
		--p.size_b;
		while (p.size_a >= 0 || p.size_b >= 0)
		{
				if (p.size_a >= 0)
						ft_printf("| %12d |\t", p.a[p.size_a--]);
				else
						ft_printf("| %12s |\t", "");
				if (p.size_b >= 0)
						ft_printf("| %-12d |\n", p.b[p.size_b--]);
				else
						ft_printf("| %-12s |\n", "");
		}
		ft_printf("----------------\t----------------\n");
		sleep(interval);
}
