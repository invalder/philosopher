# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 02:14:56 by nnakarac          #+#    #+#              #
#    Updated: 2022/09/14 23:09:28 by nnakarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
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
		philo_init.c \
		philo_routine.c \
		philo_actions.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJS))
		@$(CC) -pthread -g $(CFLAGS) $(addprefix $(OBJ_DIR),$(OBJS)) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -pthread -g $(CFLAGS) -c $< $(INCS) -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(RM) "$(NAME).dSYM"

fclean: clean

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader
	norminette -R CheckDefine

.PHONY: fclean all clean re philo norm
