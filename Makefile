# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 15:32:49 by ssabbah           #+#    #+#              #
#    Updated: 2018/06/26 18:27:42 by ssabbah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN = lem-in

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
LIBFT= -Llibft -lft

INC_DIR = inc/


LEMIN_SRC =	lemin.c\
		add_end.c\
		parser.c\
		tree.c\
		is_link.c\
		add_links.c\
		del_link.c\

LEMIN_OBJ = $(LEMIN_SRC:.c=.o)

VPATH= src/

#OBJ_PATH = obj/

INCLUDES = -I $(INC_DIR)


all: libft $(LEMIN)

libft:
	@make -C libft/

# Executables 

$(LEMIN): $(LEMIN_OBJ) 
	@$(CC) -o $@ $(CFLAGS) $^ -I $(INC_DIR) $(LIBFT) 
	@echo "Compiling [$@]"

# Object files 

$(LEMIN_OBJ): $(LEMIN_SRC)
	@$(CC) -c $^ $(CFLAGS) -I $(INC_DIR) 	
	@echo "Compiling [$^]"

# Cleaning rules 

clean:
	@rm -f $(LEMIN_OBJ)
	@rm -rf obj
	@echo "Cleaning [$(LEMIN_OBJ)]"	

fclean: clean
	@rm -rf $(LEMIN) 
	@make fclean -C libft
	@echo "Cleaning [libft lemin]"	

re: fclean all

.PHONY: clean fclean re libft
