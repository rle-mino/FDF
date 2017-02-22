# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 13:18:55 by rle-mino          #+#    #+#              #
#    Updated: 2016/02/21 07:57:57 by rle-mino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=			fdf


#SOURCE
SRC		=			disply_color.c			\
					fdf_error.c				\
					fdf_map.c				\
					fdf_parse.c				\
					fdf_parse2.c			\
					fdf_to_mlx.c			\
					main.c

OBJ		=			$(SRC:.c=.o)



#COLOR
KCYN	=		"\033[0;36m"
KRESET	=		"\033[0m"
KRED	=		"\033[0;31m"
KWHI	=		"\033[1;37m"


#OTHER
FLAGS	=		-Wall -Wextra -Werror


#RULES
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(OBJ) -lft -L ./libft -lmlx -Iincludes -framework OpenGL -framework AppKit -o $(NAME)
	@echo $(KWHI)"Compiling" $(KRESET)"fdf\t\t["$(KCYN)"SUCCESS"$(KRESET)"]"

%.o: %.c
	@gcc -c $(FLAGS) -I includes $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo $(KRED)"removal" $(KRESET)"libft.a\t\t["$(KCYN)"SUCCESS"$(KRESET)"]"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo $(KRED)"removal" $(KRESET)"fdf\t\t["$(KCYN)"SUCCESS"$(KRESET)"]"

re: fclean $(NAME)
