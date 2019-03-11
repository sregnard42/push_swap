# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    my_test.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 02:23:04 by sregnard          #+#    #+#              #
#    Updated: 2019/03/11 16:30:33 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARG=`ruby -e "puts((1..42).to_a.shuffle.join(' '))"`

./push_swap $ARG | ./checker $ARG -c -v
./push_swap $ARG | wc -l
#./push_swap $ARG
#./checker $ARG
