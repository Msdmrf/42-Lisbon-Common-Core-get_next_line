# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    create_test_files.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 12:38:24 by migusant          #+#    #+#              #
#    Updated: 2025/05/10 15:46:39 by migusant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Normal test file
echo -e "Hello, this is a normal file\nwith multiple lines\ntesting get_next_line\nLast line without newline" > test_normal.txt

# Empty file
touch test_empty.txt

# Long line file
echo -n "ThisIsAVeryLongLineWithoutAnyNewlineCharacterToTestHowTheGetNextLineFunctionHandlesLongLinesAndMemoryManagement" > test_long.txt

# File with only newlines
echo -e "\n\n\n" > test_newlines.txt

# Multiple FD test files
echo -e "First line of file 1\nSecond line of file 1" > test1.txt
echo -e "First line of file 2\nSecond line of file 2" > test2.txt
echo -e "First line of file 3\nSecond line of file 3" > test3.txt

# Normal test file for bonus
echo -e "This is a normal test file\nwith multiple lines\nand a final line" > test_normal_bonus.txt

# Empty file for bonus
touch test_empty_bonus.txt

# Long line file for bonus
perl -e 'print "A" x 10000' > test_long_bonus.txt

# Only newlines for bonus
echo -e "\n\n\n\n\n" > test_newlines_bonus.txt

# Multiple FD test files for bonus
echo -e "File 1, Line 1\nFile 1, Line 2" > test1_bonus.txt
echo -e "File 2, Line 1\nFile 2, Line 2" > test2_bonus.txt
echo -e "File 3, Line 1\nFile 3, Line 2" > test3_bonus.txt