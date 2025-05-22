NAME = polymorph

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = obj

SRCS = main.cpp \
       Animal.cpp \
       Dog.cpp \
       Cat.cpp \
       WrongAnimal.cpp \
       WrongCat.cpp \
	   Brain.cpp

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

HEADERS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re