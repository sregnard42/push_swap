# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2019/05/28 14:40:25 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER					=	checker
PUSH_SWAP				=	push_swap

LIBDIR					=	libft/
LIBFT					=	$(LIBDIR)libft.a

HEADDIR					=	includes/
HEADERS					=	-I $(HEADDIR)
HEADERS					+=	-I $(LIBDIR)$(HEADDIR)

DEPENDENCIES			=	push_swap.h

SRCDIR					=	srcs/
OBJDIR					=	objs/

SRCNAME					=	parsing.c \
							utils.c \
							display.c \
							operations.c \
							swap.c \
							push.c \
							rotate.c \
							rev_rotate.c
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
							selection_sort.c \
							insertion_sort.c \
							quick_sort.c
SRC_PUSH				:=	$(addprefix $(SRCDIR_PUSH), $(SRCNAME))
OBJ_PUSH				=	$(SRC_PUSH:$(SRCDIR_PUSH)%.c=$(OBJDIR_PUSH)%.o)

CC						=	gcc	
CFLAGS					=	-Wall -Wextra -Werror

all						:	$(LIBFT) $(CHECKER) $(PUSH_SWAP)

$(LIBFT)				:
	@make -C $(LIBDIR)

$(CHECKER)				:	$(OBJ_CHECK) $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) $(LIBFT) -o $@ $(OBJ) $(OBJ_CHECK)

$(PUSH_SWAP)			:	$(OBJ_PUSH) $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) $(LIBFT) -o $@ $(OBJ) $(OBJ_PUSH)

$(OBJDIR_CHECK)%.o		:	$(SRCDIR_CHECK)%.c
	@mkdir -p $(OBJDIR_CHECK);
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(OBJDIR_PUSH)%.o		:	$(SRCDIR_PUSH)%.c
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
