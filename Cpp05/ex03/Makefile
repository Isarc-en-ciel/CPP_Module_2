# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 16:58:24 by iwaslet           #+#    #+#              #
#    Updated: 2025/11/06 17:59:50 by iwaslet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Bureaucrat
CC= c++
CPPFLAGS= -Werror -Wextra -Wall -std=c++98 -g3 -fsanitize=address

SRCS= main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp \

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
