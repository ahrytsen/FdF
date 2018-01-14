#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/30 18:43:03 by ahrytsen          #+#    #+#              #
#    Updated: 2018/01/14 16:01:12 by ahrytsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf
DIRSRC		=	./src/
DIROBJ		=	./obj/
INCLUDE		=	-I./inc/ -I./libft/ -I/minilibx/
SUB_MAKE1	=	./minilibx/
SUB_MAKE2	=	./libft/
INC_LIB		=	-L./libft -lftprintf -L./minilibx -lmlx -framework OpenGL		\
				-framework AppKit
SRC			=	fdf.c utils.c
HDR			=	inc/fdf.h
OBJ			=	$(addprefix $(DIROBJ), $(SRC:.c=.o))

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

CC			=	gcc
RM			=	rm -f
ECHO		=	echo


$(NAME)	:		$(OBJ)
ifdef SUB_MAKE1
				@$(MAKE) -C $(SUB_MAKE1) -j3
endif
ifdef SUB_MAKE2
				@$(MAKE) -C $(SUB_MAKE2) -j3
endif
				@$(CC) $(INCLUDE) $(INC_LIB) $(CFLAGS) -O3 -o $(NAME) $(OBJ)
				@$(ECHO) "\033[31m> \033[32mFdF: Compiled\033[0m"

clean	:
				@($(RM) $(OBJ))
ifdef SUB_MAKE1
				@$(MAKE) -C $(SUB_MAKE1) clean
endif
ifdef SUB_MAKE2
				@$(MAKE) -C $(SUB_MAKE2) clean
endif
				@$(ECHO) "\033[31m> \033[33mFdF: Directory cleaned\033[0m"

all		:		$(NAME)

fclean	:		clean
ifdef SUB_MAKE1
				@$(MAKE) -C $(SUB_MAKE1) fclean
endif
ifdef SUB_MAKE2
				@$(MAKE) -C $(SUB_MAKE2) fclean
endif
				-@$(RM) $(NAME)
				@$(ECHO) "\033[31m> \033[33mFdF: Remove executable\033[0m"

re		:		fclean all

.PHONY	:		all clean re

$(OBJ)	: $(DIROBJ)%.o : $(DIRSRC)%.c $(HDR)
				@$(CC) $(INCLUDE) $(CFLAGS) -O3 -o $@ -c $<
