# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 13:33:40 by migusant          #+#    #+#              #
#    Updated: 2025/05/12 17:50:35 by migusant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
# Mandatory Part Commands:                                                     #
#                                                                              #
#  1. make                                                                     #
#    - Default compilation without explicit BUFFER_SIZE                        #
#    - Creates executable: get_next_line                                       #
#                                                                              #
#  2. make buffer                                                              #
#    - Compiles with BUFFER_SIZE=42                                            #
#    - Creates executable: get_next_line                                       #
#                                                                              #
#  3. make re                                                                  #
#    - Cleans everything and recompiles without BUFFER_SIZE                    #
#    - Creates executable: get_next_line                                       #
#                                                                              #
#  4. make re_buffer                                                           #
#    - Cleans everything and recompiles with BUFFER_SIZE=42                    #
#    - Creates executable: get_next_line                                       #
#                                                                              #
#  5. make tests                                                               #
#    - Runs tests for mandatory part                                           #
#    - Requires get_next_line executable                                       #
#                                                                              #
#  6. make valgrind                                                            #
#    - Runs valgrind on mandatory part                                         #
#    - Checks for memory leaks                                                 #
#                                                                              #
# Bonus Part Commands:                                                         #
#                                                                              #
#  7. make bonus                                                               #
#    - Compiles bonus part without explicit BUFFER_SIZE                        #
#    - Creates executable: get_next_line_bonus                                 #
#                                                                              #
#  8. make bonus_buffer                                                        #
#    - Compiles bonus part with BUFFER_SIZE=42                                 #
#    - Creates executable: get_next_line_bonus                                 #
#                                                                              #
#  9. make re_bonus                                                            #
#    - Cleans everything and recompiles bonus without BUFFER_SIZE              #
#    - Creates executable: get_next_line_bonus                                 #
#                                                                              #
#  10. make re_bonus_buffer                                                    #
#    - Cleans everything and recompiles bonus with BUFFER_SIZE=42              #
#    - Creates executable: get_next_line_bonus                                 #
#                                                                              #
#  11. make bonus_tests                                                        #
#    - Runs tests for bonus part                                               #
#    - Requires get_next_line_bonus executable                                 #
#                                                                              #
#  12. make bonus_valgrind                                                     #
#    - Runs valgrind on bonus part                                             #
#    - Checks for memory leaks                                                 #
#                                                                              #
# Common Commands:                                                             #
#                                                                              #
#  13. make clean                                                              #
#    - Removes all object files (.o)                                           #
#                                                                              #
#  14. make fclean                                                             #
#    - Removes all object files and executables                                #
#                                                                              #
#  15. make create                                                             #
#    - Creates test files if they don't exist                                  #
#                                                                              #
#  16. make delete                                                             #
#    - Removes all test files (test_*.txt and test[1-3].txt)                   #
#                                                                              #
# **************************************************************************** #

# Program names
NAME = get_next_line
BONUS_NAME = get_next_line_bonus

# Source files for mandatory part
CFILES = get_next_line.c get_next_line_utils.c .main.c
OFILES = $(CFILES:.c=.o)

# Source files for bonus part
BCFILES = get_next_line_bonus.c get_next_line_utils_bonus.c .main_bonus.c
BOFILES = $(BCFILES:.c=.o)

# Compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror
BUFFER = -D BUFFER_SIZE=42
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
RM = rm -f

# Default target
all: .non_buffer_flag $(NAME)

.non_buffer_flag: $(CFILES)
	@$(RM) .buffer_flag
	@if [ -f "$(word 1,$(OFILES))" ]; then \
		echo "Deleting buffered object files..."; \
		$(RM) $(OFILES); \
	fi
	@echo "Compiling files without buffer..."
	$(CC) $(FLAGS) -c $(CFILES)
	@touch .non_buffer_flag

# Compile mandatory part
$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

# Compile bonus part
bonus: .bonus_non_buffer_flag $(BONUS_NAME)

.bonus_non_buffer_flag: $(BCFILES)
	@$(RM) .bonus_buffer_flag
	@if [ -f "$(word 1,$(BOFILES))" ]; then \
		echo "Deleting buffered bonus object files..."; \
		$(RM) $(BOFILES); \
	fi
	@echo "Compiling bonus files without buffer..."
	$(CC) $(FLAGS) -c $(BCFILES)
	@touch .bonus_non_buffer_flag

$(BONUS_NAME): $(BOFILES)
	$(CC) $(FLAGS) $(BOFILES) -o $(BONUS_NAME)

# Default compilation without BUFFER_SIZE flag
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Target for compiling with BUFFER_SIZE
buffer: .buffer_flag $(NAME)

.buffer_flag: $(CFILES)
	@$(RM) .non_buffer_flag
	@if [ -f "$(word 1,$(OFILES))" ]; then \
		echo "Deleting non-buffered object files..."; \
		$(RM) $(OFILES); \
	fi
	@echo "Compiling files with BUFFER_SIZE=42..."
	$(CC) $(FLAGS) $(BUFFER) -c $(CFILES)
	@touch .buffer_flag

# Target for compiling bonus with BUFFER_SIZE
bonus_buffer: .bonus_buffer_flag $(BONUS_NAME)

.bonus_buffer_flag: $(BCFILES)
	@$(RM) .bonus_non_buffer_flag
	@if [ -f "$(word 1,$(BOFILES))" ]; then \
		echo "Deleting non-buffered bonus object files..."; \
		$(RM) $(BOFILES); \
	fi
	@echo "Compiling bonus files with BUFFER_SIZE=42..."
	$(CC) $(FLAGS) $(BUFFER) -c $(BCFILES)
	@touch .bonus_buffer_flag

# Create test files if they don't exist
create:
	@if [ ! -f "test_normal.txt" ] || [ ! -f "test1.txt" ] || \
		[ ! -f "test_normal_bonus.txt" ] || [ ! -f "test1_bonus.txt" ]; then \
		echo "Creating test files..."; \
		bash create_test_files.sh; \
		echo "All test files created successfully!"; \
	else \
		echo "Test files already exist. Use 'make delete' to remove them first."; \
	fi

# Clean object files
clean:
	@if [ -f "$(word 1,$(OFILES))" ] || [ -f "$(word 1,$(BOFILES))" ] || \
		[ -f ".buffer_flag" ] || [ -f ".non_buffer_flag" ] || \
		[ -f ".bonus_buffer_flag" ] || [ -f ".bonus_non_buffer_flag" ]; then \
		echo "Cleaning object files..."; \
		$(RM) $(OFILES) $(BOFILES) .buffer_flag .non_buffer_flag .bonus_buffer_flag .bonus_non_buffer_flag; \
	else \
		echo "No object files to clean."; \
	fi

# Clean everything
fclean: 
	@if [ -f "$(word 1,$(OFILES))" ] || [ -f "$(word 1,$(BOFILES))" ] || \
		[ -f ".buffer_flag" ] || [ -f ".non_buffer_flag" ] || \
		[ -f ".bonus_buffer_flag" ] || [ -f ".bonus_non_buffer_flag" ]; then \
		echo "Cleaning object files..."; \
		$(RM) $(OFILES) $(BOFILES) .buffer_flag .non_buffer_flag .bonus_buffer_flag .bonus_non_buffer_flag; \
	else \
		echo "No object files to clean."; \
	fi
	@if [ -f "$(NAME)" ] || [ -f "$(BONUS_NAME)" ]; then \
		echo "Cleaning executable files..."; \
		$(RM) $(NAME) $(BONUS_NAME); \
	else \
		echo "No executable files to clean."; \
	fi

# Delete test files
delete:
	@if ls test_*.txt test[1-3].txt test[1-3]_bonus.txt 1> /dev/null 2>&1; then \
		echo "Deleting test files..."; \
		$(RM) test_*.txt test[1-3].txt test[1-3]_bonus.txt; \
		echo "Test files cleaned."; \
	else \
		echo "No test files found to delete. Use 'make create' to create them first."; \
	fi

# Recompile everything
re: fclean all

# Recompile with buffer
re_buffer: fclean buffer

# Recompile bonus
re_bonus: fclean bonus

# Recompile bonus with buffer
re_bonus_buffer: fclean bonus_buffer

# Run tests
tests:
	@if [ ! -f "$(NAME)" ]; then \
		echo "Error: $(NAME) not found. Please run 'make' first."; \
		exit 1; \
	fi
	@$(MAKE) create
	@./$(NAME)

# Run bonus tests
bonus_tests:
	@if [ ! -f "$(BONUS_NAME)" ]; then \
		echo "Error: $(BONUS_NAME) not found. Please run 'make bonus' first."; \
		exit 1; \
	fi
	@$(MAKE) create
	@./$(BONUS_NAME)

# Run valgrind
valgrind: $(NAME)
	$(VALGRIND) ./$(NAME)

# Run valgrind on bonus
bonus_valgrind: $(BONUS_NAME)
	$(VALGRIND) ./$(BONUS_NAME)

# Define phony targets
.PHONY: all clean fclean re bonus buffer bonus_buffer tests bonus_tests create delete re_buffer re_bonus re_bonus_buffer valgrind bonus_valgrind