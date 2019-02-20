/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:27:57 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/20 03:04:42 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"

# define NO_SLEEP		0
# define SHORT_SLEEP	1
# define LONG_SLEEP		2

int		swap_a(t_ps *p);
int		swap_b(t_ps *p);
int		swap(t_ps *p);

int		push_a(t_ps *p);
int		push_b(t_ps *p);

int		rotate_a(t_ps *p);
int		rotate_b(t_ps *p);
int		rotate(t_ps *p);

int		rev_rotate_a(t_ps *p);
int		rev_rotate_b(t_ps *p);
int		rev_rotate(t_ps *p);

#endif
