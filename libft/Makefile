# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:48:38 by ailopez-          #+#    #+#              #
#    Updated: 2022/06/03 13:50:45 by aitoraudi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= 	libft.a

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strchr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlen.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strdup.c \
				ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_calloc.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c


SRCS_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c

OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

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
		@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"	
		${CC} ${CFLAGS} -I./ -c $< -o $@

all: ${NAME}

${NAME}:${OBJS} libft.h
		@ar -crs ${NAME} ${OBJS}
		@echo "$(MAGENTA)$(AR) $(NAME) $(OBJS)$(DEF_COLOR)"
		@echo "$(GREEN)libft compiled!$(DEF_COLOR)"


bonus:${NAME} ${OBJS_BONUS}
		ar -crs ${NAME} ${OBJS_BONUS}
		@touch $@

#Regla para borrar todos los objetos y directorios
clean:
		${RM} ${OBJS}
		@echo "$(CYAN)libft object files cleaned!$(DEF_COLOR)"		

#Regla para borrar todo lo que ha sido creado or el makefile
fclean:	clean
		${RM} ${NAME} 	
		${RM} ${OBJS_BONUS}
		${RM} bonus
		@echo "$(CYAN) libft executable files cleaned!$(DEF_COLOR)"	

#Regla  para rehacer todo
re:		fclean all
		@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

.PHONY: fclean, all, clean, re

