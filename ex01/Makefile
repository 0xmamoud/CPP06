
NAME = serialize

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM	= rm -rf

HEADER = Serializer.hpp \

SRC = main.cpp \
			Serializer.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -I HEADER -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re
