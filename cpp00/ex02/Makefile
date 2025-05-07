NAME = account_test

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

                  
# ./account_test > my.log
# cut -c 19- my.log > out_clean.log
# cut -c 19- 19920104_091532.log > ref_clean.log
# diff out_clean.log ref_clean.log
