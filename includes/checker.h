/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:27:57 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/19 23:28:32 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

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
