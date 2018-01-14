#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/30 18:43:03 by ahrytsen          #+#    #+#              #
#    Updated: 2018/01/14 14:24:31 by ahrytsen         ###   ########.fr        #
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
SRC			=	FdF.c utils.c
HDR			=	inc/FdF.h
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


$(NAME)	:		$(OBJ) $(HDR)
ifdef SUB_MAKE1
				@(cd $(SUB_MAKE1) && $(MAKE))
endif
ifdef SUB_MAKE2
				@(cd $(SUB_MAKE2) && $(MAKE) -j3)
endif
				@$(CC) $(INCLUDE) $(INC_LIB) $(CFLAGS) -O3 -o $(NAME) $(OBJ)
				@$(ECHO) "\033[31m> \033[32mFdF: Compiled\033[0m"

clean	:
				@(cd $(DIROBJ) && $(RM) $(OBJ))
ifdef SUB_MAKE1
				@(cd $(SUB_MAKE1) && $(MAKE) clean)
endif
ifdef SUB_MAKE2
				@(cd $(SUB_MAKE2) && $(MAKE) clean)
endif
				@$(ECHO) "\033[31m> \033[33mFdF: Directory cleaned\033[0m"

all		:		$(NAME)

fclean	:		clean
ifdef SUB_MAKE1
				@(cd $(SUB_MAKE1) && $(MAKE) fclean)
endif
ifdef SUB_MAKE2
				@(cd $(SUB_MAKE2) && $(MAKE) fclean)
endif
				-@$(RM) $(NAME)
				@$(ECHO) "\033[31m> \033[33mFdF: Remove executable\033[0m"

re		:		fclean all

.PHONY	:		all clean re

$(OBJ)	: $(DIROBJ)%.o : $(DIRSRC)%.c
				@$(CC) $(INCLUDE) $(CFLAGS) -O3 -o $(DIROBJ)/$@ -c $<
