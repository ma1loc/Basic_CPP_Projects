CPP = c++
COMPILE_FLAG = -std=c++98
CPP_FLAGS = -Wall -Wextra -Werror

NAME = a.out
SRC = AMateria.cpp \
	Character.cpp \
	Cure.cpp \
	Ice.cpp \
	main.cpp \
	MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(COMPILE_FLAG) $(CPP_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(COMPILE_FLAG) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

