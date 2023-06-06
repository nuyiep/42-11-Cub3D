# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2023/06/06 15:24:42 by zwong            ###   ########.fr        #
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

DOBJS		= objs/

# all these files doesn't require directory path ya
FILES		=	valid_test	\
				render_test	\

FOBJS		= $(addprefix $(DOBJS), $(addsuffix .o, $(FILES:.c=.o)))

vpath %.c $(DSRCS)

LIBD		= libft
LIBA		= libft.a

all:		$(NAME)

$(DOBJS)%.o: %.c
	@mkdir -p objs/
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

${NAME}:	srcs/main.c ${LIBD}/${LIBA} ${PRINTFD}/${PRINTFA} ${FOBJS}
	@echo "Compiling: srcs/main.c"
	@${CC} ${CFLAGS} -I. srcs/main.c ${FOBJS} ${LIBD}/${LIBA} ${MLX} ${MLXFLAGS} -o ${NAME}

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

# NAME		=	cub3D
# LIBFT		=	libft/libft.a
# CC			=	gcc
# RM			=	rm -rf
# MKDIR		=	mkdir -p
# CFLAGS		=	-Wall -Wextra -Werror -Imlx
# # CFLAGS		=	-fsanitize=address -g3
# MLXFLAGS	=	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
# SRCsS_FILES	=	main \
# 				c3d_checkelement \
# 				c3d_checkfile \
# 				c3d_exit \
# 				c3d_hook \
# 				c3d_init
				
# SRCsS		= 	$(addprefix $(SRCsS_DIR), $(addsuffix .c, $(SRCsS_FILES)))
# OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCsS_FILES)))
# SRCsS_DIR	=	srcss/
# LIBFT_DIR	=	libft/
# OBJS_DIR	=	objs/

# all:			
# 				$(MKDIR) $(OBJS_DIR)
# 				make libft
# 				make $(NAME)

# $(OBJS_DIR)%.o: $(SRCsS_DIR)%.c
# 				$(CC) $(CFLAGS) -c $< -o $@

# $(NAME):		$(OBJS)
# 				$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) $(MLXFLAGS) -o $(NAME)

# libft:
# 				make -C $(LIBFT_DIR)

# clean:
# 				$(RM) $(OBJS_DIR)
# 				make clean -C $(LIBFT_DIR)

# fclean:			clean
# 				make fclean -C $(LIBFT_DIR)
# 				$(RM) $(NAME)

# re:				fclean all

# .PHONY:			all bonus libft clean fclean re