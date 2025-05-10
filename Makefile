# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 13:33:40 by migusant          #+#    #+#              #
#    Updated: 2025/05/10 18:01:12 by migusant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
BONUS_NAME = get_next_line_bonus

CFILES = get_next_line.c get_next_line_utils.c .main.c
OFILES = $(CFILES:.c=.o)

BCFILES = get_next_line_bonus.c get_next_line_utils_bonus.c .main_bonus.c
BOFILES = $(BCFILES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
BUFFER = -D BUFFER_SIZE=42
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
RM = rm -f

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

$(BONUS_NAME): $(BOFILES)
	$(CC) $(FLAGS) $(BOFILES) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(FLAGS) $(BUFFER) -c $< -o $@

bonus: $(BONUS_NAME)

create:
	@if [ ! -f "test_normal.txt" ] || [ ! -f "test1.txt" ] || \
		[ ! -f "test_normal_bonus.txt" ] || [ ! -f "test1_bonus.txt" ]; then \
		echo "Creating test files..."; \
		bash create_test_files.sh; \
		echo "All test files created successfully!"; \
	else \
		echo "Test files already exist. Use 'make delete' to remove them first."; \
	fi

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OFILES) $(BOFILES)

fclean: clean
	@echo "Cleaning executable files..."
	@$(RM) $(NAME) $(BONUS_NAME)

delete:
	@if ls test_*.txt test[1-3].txt test[1-3]_bonus.txt 1> /dev/null 2>&1; then \
		echo "Deleting test files..."; \
		$(RM) test_*.txt test[1-3].txt test[1-3]_bonus.txt; \
		echo "Test files cleaned."; \
	else \
		echo "No test files found to delete. Use 'make create' to create them first."; \
	fi

re: fclean all

tests:
	@if [ ! -f "$(NAME)" ]; then \
		echo "Error: $(NAME) not found. Please run 'make' first."; \
		exit 1; \
	fi
	@$(MAKE) create
	@./$(NAME)

tests_bonus:
	@if [ ! -f "$(BONUS_NAME)" ]; then \
		echo "Error: $(BONUS_NAME) not found. Please run 'make bonus' first."; \
		exit 1; \
	fi
	@$(MAKE) create
	@./$(BONUS_NAME)

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME)

valgrind_bonus: $(BONUS)
	$(VALGRIND) ./$(BONUS)

.PHONY: all clean fclean re bonus test test_bonus create delete