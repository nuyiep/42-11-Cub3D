# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plau <plau@student.42.kl>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2023/06/17 18:01:28 by plau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

CC			= gcc
MLX			= mlx/libmlx.a
CFLAGS		= -Wall -Wextra -Werror -Imlx
MLXFLAGS	= -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FSANS		= -fsanitize=address -g3

DSRCS		= srcs					\
			  srcs/validation		\
			  srcs/parsing			\
			  srcs/render			\
			  srcs/controls			\
			  srcs/utils			\
			  srcs/initialize		\

DOBJS		= objs/

# all these files doesn't require directory path ya
FILES		=	init_vars \
				parse_directions \
				parse_elements \
				parse_store_map \
				utils_map \
				utils \
				valid_check_file \
				valid_map \
				valid_map_wall \
				valid_map_elements

FOBJS		= $(addprefix $(DOBJS), $(addsuffix .o, $(FILES:.c=.o)))

vpath %.c $(DSRCS)

LIBD		= libft
LIBA		= libft.a

all:		$(NAME)

$(DOBJS)%.o: %.c
	@mkdir -p objs/
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	# @$(CC) $(CFLAGS) $(FSANS) -I. -c $< -o $@

${NAME}:	srcs/main.c ${LIBD}/${LIBA} ${PRINTFD}/${PRINTFA} ${FOBJS}
	@echo "Compiling: srcs/main.c"
	@${CC} ${CFLAGS} -I. srcs/main.c ${FOBJS} ${LIBD}/${LIBA} ${MLX} ${MLXFLAGS} -o ${NAME}
	# @${CC} ${CFLAGS} $(FSANS) -I. srcs/main.c ${FOBJS} ${LIBD}/${LIBA} ${MLX} ${MLXFLAGS} -o ${NAME}

${LIBD}/${LIBA}:
	@make -C ${LIBD}

clean: ${OBJ}
	@make clean -C ${LIBD}
	@rm -rf ${DOBJS}
	@echo clean done

fclean: clean
	@make fclean -C ${LIBD}
	@rm -rf ${NAME}
	@echo fclean done

re: fclean all

.PHONY:	all clean fclean re
