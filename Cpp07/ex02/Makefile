# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 20:47:36 by iwaslet           #+#    #+#              #
#    Updated: 2025/12/11 20:47:45 by iwaslet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Array
CC= c++
CPPFLAGS= -Werror -Wextra -Wall -std=c++98 -g3 -fsanitize=address

SRCS= main.cpp \

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