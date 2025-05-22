NAME = materia

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = obj

SRCS = main.cpp \
       AMateria.cpp \
       Ice.cpp \
       Cure.cpp \
       Character.cpp \
       MateriaSource.cpp

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

HEADERS = AMateria.hpp Ice.hpp Cure.hpp \
          ICharacter.hpp Character.hpp \
          IMateriaSource.hpp MateriaSource.hpp

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
