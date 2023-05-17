# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besalort <besalort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 14:19:30 by besalort          #+#    #+#              #
#    Updated: 2023/05/16 16:42:08 by besalort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./src/pipex.c \
	./src/ft_free.c \
	./src/ft_check.c \
	./src/ft_path.c \
	./src/ft_load.c \
	./src/ft_access.c \
	./src/ft_processes.c \
	./src/ft_cmd.c \
	./src/ft_list.c \
	./src/ft_run.c \

LIBFT = $(LIBFT_PATH)libft.a

LIBFT_PATH = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}



OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re