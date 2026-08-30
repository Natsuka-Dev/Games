TARGET = minesweeper
CFLAGS = -std=c23 -Wall -Wextra -Werror -D_XOPEN_SOURCE_EXTENDED
SRC = $(wildcard map/*.c) $(wildcard tools/*.c) main.c
OBJ = $(SRC:.c=.o)

all : $(TARGET)

minesweeper : $(OBJ)
	cc $(OBJ) -lncurses -o $(TARGET)

.c.o :
	cc $(CFLAGS) $< -c -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re