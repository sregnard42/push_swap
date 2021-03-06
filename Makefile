# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2019/06/26 18:40:09 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER					=	checker
PUSH_SWAP				=	push_swap

LIBDIR					=	libft/
LIBFT					=	$(LIBDIR)libft.a

HEADDIR					=	includes/
HEADERS					=	-I $(HEADDIR)
HEADERS					+=	-I $(LIBDIR)$(HEADDIR)

DEPENDENCIES			=	$(HEADDIR)push_swap.h

SRCDIR					=	srcs/
OBJDIR					=	objs/

SRCNAME					=	swap.c \
							push.c \
							rotate.c \
							rev_rotate.c \
							parsing.c \
							utils.c \
							display.c \
							operations.c \
							operations_opti.c \
							free.c
SRC						:=	$(addprefix $(SRCDIR), $(SRCNAME))
OBJ						=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

DIR_CHECK				=	$(CHECKER)/
SRCDIR_CHECK			=	$(SRCDIR)$(DIR_CHECK)
OBJDIR_CHECK			=	$(OBJDIR)$(DIR_CHECK)

SRCNAME					=	checker.c
SRC_CHECK				:=	$(addprefix $(SRCDIR_CHECK), $(SRCNAME))
OBJ_CHECK				=	$(SRC_CHECK:$(SRCDIR_CHECK)%.c=$(OBJDIR_CHECK)%.o)

DIR_PUSH				=	$(PUSH_SWAP)/
SRCDIR_PUSH				=	$(SRCDIR)$(DIR_PUSH)
OBJDIR_PUSH				=	$(OBJDIR)$(DIR_PUSH)

SRCNAME					=	push_swap.c \
							mini_sort.c \
							insertion_sort.c \
							select_insert_sort.c \
							min_max.c \
							sort.c
SRC_PUSH				:=	$(addprefix $(SRCDIR_PUSH), $(SRCNAME))
OBJ_PUSH				=	$(SRC_PUSH:$(SRCDIR_PUSH)%.c=$(OBJDIR_PUSH)%.o)

CC						=	gcc	
CFLAGS					=	-Wall -Wextra -Werror

all						:	$(LIBFT) $(CHECKER) $(PUSH_SWAP)

$(LIBFT)				:
	@make -C $(LIBDIR)

$(CHECKER)				:	$(LIBFT) $(OBJ_CHECK) $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) $(LIBFT) -o $@ $(OBJ) $(OBJ_CHECK)

$(PUSH_SWAP)			:	$(LIBFT) $(OBJ_PUSH) $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) $(LIBFT) -o $@ $(OBJ) $(OBJ_PUSH)

$(OBJDIR_CHECK)%.o		:	$(SRCDIR_CHECK)%.c $(DEPENDENCIES)
	@mkdir -p $(OBJDIR_CHECK);
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJDIR_PUSH)%.o		:	$(SRCDIR_PUSH)%.c $(DEPENDENCIES)
	@mkdir -p $(OBJDIR_PUSH);
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJDIR)%.o			:	$(SRCDIR)%.c
	@mkdir -p $(OBJDIR);
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

clean					:
	rm -rf $(OBJDIR)
	make clean -C $(LIBDIR)

fclean					:	clean
	rm -rf $(CHECKER) $(PUSH_SWAP)
	make fclean -C $(LIBDIR)

re						:	fclean	all

ps						:
	rm -rf objs/
	make
