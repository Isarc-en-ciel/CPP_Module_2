# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 16:35:52 by iwaslet           #+#    #+#              #
#    Updated: 2025/11/11 17:20:29 by iwaslet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= Serializer
CC= c++
CPPFLAGS= -Werror -Wextra -Wall -std=c++98 -g3 -fsanitize=address

SRCS= main.cpp \
		Serializer.cpp \

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
