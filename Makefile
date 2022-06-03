# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:48:38 by ailopez-          #+#    #+#              #
#    Updated: 2022/06/03 13:50:22 by aitoraudi        ###   ########.fr        #
#    Updated: 2022/05/24 00:35:24 by aitorlope        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#Variables

NAME		= libftprintf.a
INCLUDE		= inc
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -MMD -I
RM			= rm -f
AR			= ar rcs

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

#Sources

SRC_FILES	=	ft_printf_aux ft_printf_itoa ft_printf_du ft_printf_sc ft_printf_xp ft_printf 
SRC_FILES_B	=	ft_printf_aux_bonus ft_printf_itoa_bonus ft_printf_du_bonus ft_printf_sc_bonus \
				ft_printf_xp_bonus ft_printf_bonus 

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_B 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_B)))
OBJ_B		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_B)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:	makelibs
	@$(MAKE)	$(NAME)

makelibs:	
			@$(MAKE) -C $(LIBFT)
			
-include 	${DEPS}
$(NAME):	$(OBJ) ${LIBFT}/libft.a
			cp libft/libft.a .
			mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(MAGENTA)$(AR) $(NAME) $(OBJ)$(DEF_COLOR)"
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

bonus:		$(OBJ_B) ${LIBFT}/libft.a
			@make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ_B)
			@echo "$(YELLOW)$(AR) $(NAME) $(OBJ_B)$(DEF_COLOR)"			
			@echo "$(GREEN)ft_printf bonus compiled!$(DEF_COLOR)"
			@touch $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(CYAN)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"
			${RM} bonus

re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

