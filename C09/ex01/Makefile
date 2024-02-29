# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drhaouha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 14:33:18 by drhaouha          #+#    #+#              #
#    Updated: 2024/02/26 14:33:22 by drhaouha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=	'\033[0;32m'
ORANGE	=	'\033[0;33m'
RED		=	'\033[0;31m'
NC		=	'\033[0m'

INC		=	./includes/

SRCS	=	ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

SRC		=	./srcs/

OBJS	=	$(addprefix ${SRC}, ${SRCS:.c=.o})

NAME	=	libft.a

.c.o:
			@gcc -Wall -Wextra -Werror -c -I ${INC} $< -o ${<:.c=.o}
			@echo -e ${GREEN}Object ${<:.c=.o} is created.${NC}

${NAME}:	${OBJS}
			 @ar rcs $@ $^
			 @echo -e ${GREEN}Library ${NAME} is created and indexed.${NC}

all:		${NAME}

clean:
			@rm -f ${OBJS}
			@echo -e ${ORANGE}Objects are removed.${NC}

fclean:		clean
			@rm -f ${NAME}
			@echo -e ${RED}Library ${NAME} is removed.${NC}

re:			fclean all

.PHONY:		re fclean clean all