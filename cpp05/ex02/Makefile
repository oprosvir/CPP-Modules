NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = obj

SRCS = main.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       Bureaucrat.cpp \
       PresidentialPardonForm.cpp

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

HEADERS = AForm.hpp ShrubberyCreationForm.hpp \
          RobotomyRequestForm.hpp Bureaucrat.hpp \
          PresidentialPardonForm.hpp

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