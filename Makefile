# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:48:38 by ailopez-          #+#    #+#              #
#    Updated: 2022/05/23 20:04:02 by ailopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= 	a.out

SRCS		=	main.c src/ft_printf.c src/ft_numbrs.c src/ft_strings.c

LIBFT		= 	libft/libft.a

OBJS		=	$(SRCS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


%.o: %.c
		@${CC} ${CFLAGS} -I./ -c $< -o $@
		@echo "$(MAGENTA) ${CC} ${CFLAGS}  -I./ -c $< -o $(DEF_COLOR)"

all: ${NAME}

${NAME}:${OBJS} inc/ft_printf.h
		@${CC} ${OBJS} ${LIBFT} -o ${NAME}
		@echo "$(CYAN) ${OBJS} ${LIBFT} linked $(DEF_COLOR)"$
		@echo "$(GREEN) ft_printf -> ${NAME} done$(DEF_COLOR)"
		@${RM} ${OBJS}
#Regla para borrar todos los objetos y directorios
clean:
		@${RM} ${OBJS}
		@echo "$(RED) ${RM} ${OBJS}$(DEF_COLOR)"
#Regla para borrar todo lo que ha sido creado or el makefile
fclean:	clean
		@${RM} ${NAME} 
		@echo "$(RED) ${RM} ${NAME} $(DEF_COLOR)"

#Regla  para rehacer todo
re:		fclean all

.PHONY: fclean, all, clean, re
