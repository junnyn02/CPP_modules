# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 10:37:37 by junguyen          #+#    #+#              #
#    Updated: 2025/05/13 14:12:50 by junguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	weapon

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -g -std=c++98

SRC_PATH	=	srcs/

OBJ_PATH	=	obj/

SRC			:=	main.cpp
SRC			+=	Weapon.cpp
SRC			+=	HumanA.cpp
SRC			+=	HumanB.cpp

SRCS		=	${addprefix $(SRC_PATH), $(SRC)}

OBJ			=	$(SRC:.cpp=.o)

OBJS		= 	${addprefix $(OBJ_PATH), $(OBJ)}

INCLUDES 	= 	-I incs/

RM			=	 rm -rfd

RED			:=	"\033[0;31m\033[1m"
GREEN		:=	"\033[0;32m\033[1m"
BLUE		:=	"\033[0;34m\033[1m"
YELLOW		:=	"\033[1;33m\033[1m"
PURPLE		:=	"\033[0;35m\033[1m"
CYAN		:=	"\033[0;36m\033[1m"
WHITE		:=	"\033[0;37m\033[1m"
NO_STYLE	:=	"\033[0m"

all:		$(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDES) -c  $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)
		@echo $(GREEN)$(NAME) compiled!$(NO_STYLE)


clean:	
		@$(RM) $(OBJ_PATH)
		@echo $(YELLOW)object clean! $(NO_STYLE)

fclean: clean
		@$(RM) $(NAME)
		@echo $(RED)$(NAME) deleted!$(NO_STYLE)

re: fclean all
		@echo $(PURPLE)$(NAME) reloaded!$(NO_STYLE)

.PHONY: all clean fclean re