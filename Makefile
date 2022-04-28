# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 02:16:27 by jhgoncal          #+#    #+#              #
#    Updated: 2022/04/28 02:16:27 by jhgoncal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap

SRCS = ${wildcard operations/*.c} ${wildcard minilibft/*.c} ${wildcard srcs/*.c}
OBJS = ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror -I includes/

CL = ar -rc
RL = ar -s

${NAME}:	${OBJS}
	${CL}	${NAME}	${OBJS}
	${RL}	${NAME}
	${CC}	${CFLAGS} -o $@ $^ -Iincludes/

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM}	${NAME}

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader operations/*.c minilibft/*.c
	norminette -R CheckDefine includes/*.h

.PHONY: clean fclean all re