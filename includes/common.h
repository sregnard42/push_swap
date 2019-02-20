/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:46:27 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 01:21:03 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

# define ERR_DEFAULT "Error\n"

typedef struct	s_ps
{
		int		*a;
		int		*b;
		int		size_a;
		int		size_b;
}				t_ps;

void			trigger_error(char *error);
void			parse_args(t_ps *p, int ac, char **av);
void			print_stacks(t_ps p);

#endif
