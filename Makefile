##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC    =	main.c	\
			read_file.c \
			find_path.c 	\
			parsing.c	\
			my_str_to_word_array.c	\
			get_nb_rooms.c	\
			get_nb_links.c	\
			get_connection.c	\
			bubble_sort.c	\
			display.c	\
			utility_function_str_to_word_array.c	\
			display_ants_moves.c	\
			check_if_finished.c	\
			check_anthill_validity.c	\

OBJ    =    $(SRC:.c=.o)

##CFLAGS = -Wall -Wshadow -Wextra -I./include -g

NAME	=	lem_in

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) -Llib -lmy

clean:
		rm $(OBJ)
		make clean -C lib/my

fclean: clean
		rm -f $(NAME)

re:		fclean all

git:
	echo -e "*.a\n*.o\n*#*#*\n#*\n.#*\n*~" > .gitignore
	echo -e "vgcore*\n*.log\na.out\n.vscode*" >> .gitignore
	echo $(NAME) >> .gitignore

style:
	/home/${USER}/coding-style-checker/coding-style.sh . .
	grep -v MAJOR:C-O1 coding-style-reports.log || true
	rm -f coding-style-reports.log
