NAME := PmergeMe

CXX := c++

CXXFLAGS := -Wall -Wextra -Werror -g -std=c++98

SRC := main.cpp PmergeMe.cpp

OBJ := $(SRC:.cpp=.o)

HEADER := PmergeMe.hpp

RM := rm -f

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# ./PmergeMe `shuf -i 1-100 -n 21 | tr "\n" " "` 1

# -fsanitize=address -O0 