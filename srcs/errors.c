/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:39:53 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/19 23:32:37 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	trigger_error(char *error)
{
		if (!error)
				error = ERR_DEFAULT;
		write(2, error, ft_strlen(error));
		exit(EXIT_FAILURE);
}
