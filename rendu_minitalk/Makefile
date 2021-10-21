# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 11:19:49 by lmaujean          #+#    #+#              #
#    Updated: 2021/09/24 11:19:51 by lmaujean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk

CLIENT			= client

SERVEUR			= serveur
CC				= gcc
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			= #-fsanitize=address

FOLDER_HEADER	= header/
FOLDER_SRC		= src/

HEADER_SRC		= Minitalk.h
SRC_CLIENT		= client.c
SRC_SERVEUR		= serveur.c

HDR				= $(addprefix ${FOLDER_HEADER}, ${HEADER_SRC})
SRC_C			= $(addprefix ${FOLDER_SRC}, ${SRC_CLIENT})
SRC_S			= $(addprefix ${FOLDER_SRC}, ${SRC_SERVEUR})

OBJ_C			= ${SRC_C:.c=.o}
OBJ_S			= ${SRC_S:.c=.o}
OBJ				= ${SRC_C:.c=.o} ${SRC_S:.c=.o}


LIB				= ./Libft/libft.a

%.o: %.c
			${CC} ${CFLAGS} ${LDFLAGS} -c -o $@ $<

${NAME}:	${CLIENT} ${SERVEUR}

${CLIENT}:	${OBJ_C} ${HDR}
				make -C ./Libft
				${CC} ${CFLAGS} ${LDFLAGS} ${OBJ_C} ${LIB} -o ${CLIENT}

${SERVEUR}:	${OBJ_S} ${HDR}
				make -C ./Libft
				${CC} ${CFLAGS} ${LDFLAGS} ${OBJ_S} ${LIB} -o ${SERVEUR}


all:			${NAME}

clean:
			${RM} ${OBJ}
			make clean -C ./Libft

fclean:			clean
			${RM} ${CLIENT} ${SERVEUR}
			make fclean -C ./Libft

re:			fclean all

norm:
			norminette Libft/ header/ src/

.PHONY:			all clean fclean re bonus norm
