# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besalort <besalort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 14:19:30 by besalort          #+#    #+#              #
#    Updated: 2023/07/06 16:27:27 by besalort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_B = pipex_bonus

SRC = ./src/pipex.c \
	./src/ft_free.c \
	./src/ft_open.c \
	./src/ft_path.c \
	./src/ft_load.c \
	./src/ft_access.c \
	./src/ft_processes.c \
	./src/ft_cmd.c \
	./src/ft_list.c \
	./src/ft_run.c \
	./src/ft_here_doc.c \

SRC_BONUS = ./src/bonus/pipex_bonus.c \
	./src/bonus/ft_free_bonus.c \
	./src/bonus/ft_open_bonus.c \
	./src/bonus/ft_path_bonus.c \
	./src/bonus/ft_load_bonus.c \
	./src/bonus/ft_access_bonus.c \
	./src/bonus/ft_processes_bonus.c \
	./src/bonus/ft_cmd_bonus.c \
	./src/bonus/ft_list_bonus.c \
	./src/bonus/ft_run_bonus.c \
	./src/bonus/ft_here_doc_bonus.c \

LIBFT = $(LIBFT_PATH)libft.a

LIBFT_PATH = src/libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}



OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME) : $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_B) : $(OBJ_BONUS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_B)

all : $(NAME)

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	make clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	make fclean -C $(LIBFT_PATH)

re : fclean all

bonus : $(NAME_B)

.PHONY : all clean fclean re bonus