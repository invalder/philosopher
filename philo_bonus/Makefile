# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnakarac <nnakarac@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 02:14:56 by nnakarac          #+#    #+#              #
#    Updated: 2022/09/30 17:27:37 by nnakarac         ###   ########.fr        #
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
		philo_exit_handler.c \
		philo_err_handler.c \
		philo_init.c \
		philo_init2.c \
		philo_fork.c \
		philo_routine.c \
		philo_actions.c \
		philo_timer_routine.c \

OBJS	= $(SRCS:.c=.o)

NORM = norminette -R CheckForbiddenSourceHeaderDefine | grep -c 'Error:' || true

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	MEME = aplay images/meme2.mp3 &
else
	MEME = afplay images/meme2.mp3 -v 0.2 &
endif


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
	@$(MEME)
	@$(NORM)

.PHONY: fclean all clean re philo norm meow meow2 pointer
