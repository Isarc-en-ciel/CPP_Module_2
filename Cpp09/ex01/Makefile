# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 18:08:17 by iwaslet           #+#    #+#              #
#    Updated: 2026/01/29 18:25:07 by iwaslet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= RPN
CC= c++
CPPFLAGS= -Werror -Wextra -Wall -std=c++98 -fsanitize=address

SRCS= main.cpp \
		RPN.cpp\

OBJS=$(SRCS:.cpp=.o)

$(NAME) :$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf  $(NAME)

re: fclean all

.PHONY: all clean fclean re