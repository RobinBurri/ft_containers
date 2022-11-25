# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburri <rburri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:16:51 by rburri            #+#    #+#              #
#    Updated: 2022/08/19 12:46:10 by rburri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=  main

CC				= c++

CFLAGS			= -Wall -Wextra -Werror -std=c++98

SAN 			= -fsanitize=address

SRC 			= src

BIN				= bin

$(shell mkdir -p $(BIN))

SOURCES			=  $(SRC)/main.cpp\
					$(SRC)/vectors_tests.cpp


OBJS			= $(patsubst %,$(BIN)/%,$(notdir $(SOURCES:.cpp=.o)))

$(BIN)/%.o : $(SRC)/%.cpp
				$(CC) $(CFLAGS) -c $< -o $@
				

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(SAN) $(OBJS) -o $(NAME) 

RM				= /bin/rm -rf

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test