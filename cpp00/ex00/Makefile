# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 10:37:37 by junguyen          #+#    #+#              #
#    Updated: 2025/03/21 10:49:09 by junguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC =	c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	megaphone.cpp

OBJ		= $(SRC:.cpp=.o)

RM		= rm -rfd

RED			:= "\033[0;31m\033[1m"
GREEN		:= "\033[0;32m\033[1m"
BLUE		:= "\033[0;34m\033[1m"
YELLOW		:= "\033[1;33m\033[1m"
PURPLE		:= "\033[0;35m\033[1m"
CYAN		:= "\033[0;36m\033[1m"
WHITE		:= "\033[0;37m\033[1m"
NO_STYLE	:= "\033[0m"

all:		$(NAME)

$(OBJ)%.o: $(SRC)%.cpp
			$(CC) $(CFLAGS) -c  $< -o $@

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo $(GREEN)$(NAME) compiled!$(NO_STYLE)


clean:	
		@$(RM) $(OBJ)
		@echo $(YELLOW)object clean! $(NO_STYLE)

fclean: clean
		@$(RM) $(NAME)
		@echo $(RED)$(NAME) deleted!$(NO_STYLE)

re: fclean all
		@echo $(PURPLE)$(NAME) reloaded!$(NO_STYLE)

.PHONY: all clean fclean re