# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abartell <abartell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 10:16:43 by abartell          #+#    #+#              #
#    Updated: 2022/12/13 11:18:46 by abartell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME				:=		push_swap

CFLAGS				:=		-Wall - Wextra- Werror

FT_PRINTF_DIR		:= 		ft_printf
FT_PRINTF_A			:= 		./ft_printf/libftprintf.a

LIBFT_DIR			:= 		libft
LIBFT_A				:= 		libft.a

INC					:=		inc/

SRC_FILES			:=		push_swap.c pushing.c swaping.c \
							

SRC					:=		${addprefix src/, ${SRC_FILES}}

RM					:= 		rm -rf

NR					:=		norminette -R CheckForbiddenSourceHeader

# **************************************************************************** #
# RULES

all: ${NAME}

${NAME}:${OBJS}
	echo "make $(FT_PRINTF_DIR)"
	make -C $(FT_PRINTF_DIR)
	echo "make $(LIBFT_DIR)"
	make -C $(LIBFT_DIR)
	${CC} ${CFLAGS} -I${INC} $(FT_PRINTF_A) $(LIBFT_A) -o $@ $^
	@echo "$(NAME) compiled and ready to be tested!"
	@echo "Ready for swap_push or push_swap!"

.c.o:
	${CC} ${CFLAGS} -I${INC} -c $< -o $@

clean:
	${RM} ${OBJS}
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	${RM} ${NAME}
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	@echo "Everything cleaned up for $(NAME)!"

re: fclean all

.PHONY:		all clean fclean re