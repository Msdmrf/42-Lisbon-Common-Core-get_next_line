# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 13:33:40 by migusant          #+#    #+#              #
#    Updated: 2025/05/10 13:16:20 by migusant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CFILES = get_next_line.c get_next_line_utils.c

OFILES = $(CFILES:.c=.o)

BCFILES = get_next_line_bonus.c get_next_line_utils_bonus.c

BOFILES = $(BCFILES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OFILES)

bonus: $(NAME) $(BOFILES)

$(OFILES): $(CFILES)
	$(CC) $(FLAGS) -c $^
	$(AR) $(NAME) $(OFILES)

$(BOFILES): $(BCFILES)
	$(CC) $(FLAGS) -c $^
	$(AR) $(NAME) $(BOFILES)

clean:
	$(RM) $(OFILES) $(BOFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus