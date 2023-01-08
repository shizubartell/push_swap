# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abartell <abartell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 10:16:43 by abartell          #+#    #+#              #
#    Updated: 2023/01/08 20:38:35 by abartell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME				:=		push_swap

CFLAGS				:=		-Wall -Wextra -Werror
CC					:=		gcc

FT_PRINTF_DIR		:= 		ft_printf
FT_PRINTF_A			:= 		./ft_printf/libftprintf.a

INC					:=		-I ./inc/

SRC_DIR				:=		./src/
OBJ_DIR				:=		./obj/

SRC_FILES			:=		push_swap.c pushing.c swaping.c \
							lists.c rotating.c sorting.c \
							swap_push.c main.c mechanics1.c

OBJ_FILES			:=		${SRC_FILES:.c=.o}
SRC					:=		$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ					:=		$(addprefix $(OBJ_DIR), $(OBJ_FILES))

RM					:= 		rm -rf

NR					:=		norminette -R CheckForbiddenSourceHeader

# **************************************************************************** #
# RULES

all: ${OBJ_DIR} ${NAME}

${NAME}:${OBJ}
	@echo "make $(FT_PRINTF_DIR)"
	make -C $(FT_PRINTF_DIR)
	${CC} ${OBJ} $(FT_PRINTF_A) -o ${NAME}
	@echo "$(NAME) compiled and ready to be tested!"
	@echo "Ready for swap_push or push_swap!"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	${RM} ${OBJS}
	make fclean -C $(FT_PRINTF_DIR)

fclean: clean
	${RM} ${NAME}
	$(RM) $(OBJ_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	@echo "Everything cleaned up for $(NAME)!"

re: fclean all

.PHONY:		all clean fclean re