# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 02:14:56 by nnakarac          #+#    #+#              #
#    Updated: 2022/09/25 03:17:33 by nnakarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED='\033[0;31m'
NC='\033[0m'

NAME	= philo_bonus
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -rf

SRC_DIR	= srcs/
OBJ_DIR	= objs/
INC_DIR	= includes

INCS	= -I$(INC_DIR)

SRCS	= philo.c \
		philo_utils.c \
		philo_handler.c \
		philo_rules.c \
		philo_time_handler.c \
		philo_init.c \

OBJS	= $(SRCS:.c=.o)

.SILENT: pointer meow

all: $(NAME)

meow:
	./images/meow.sh

meow2:
	./images/meow2.sh

pointer:
	./images/pointer.sh

$(NAME): pointer $(addprefix $(OBJ_DIR),$(OBJS))
		@$(CC) -pthread -g $(CFLAGS) $(addprefix $(OBJ_DIR),$(OBJS)) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -g -pthread $(CFLAGS) -c $< $(INCS) -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(RM) "$(NAME).dSYM"

fclean: clean

re: fclean all

norm: meow
	norminette -R CheckForbiddenSourceHeader
	norminette -R CheckDefine

.PHONY: fclean all clean re philo norm meow meow2 pointer
