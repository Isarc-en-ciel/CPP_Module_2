# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 16:10:12 by iwaslet           #+#    #+#              #
#    Updated: 2026/01/09 16:12:23 by iwaslet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Span
CC= c++
CPPFLAGS= -Werror -Wextra -Wall -std=c++98 -fsanitize=address

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