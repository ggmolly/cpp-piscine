CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME = better_sed

SRCS = main.cpp \
		error.cpp \
		replace.cpp \

OBJS = $(SRCS:.cpp=.o)

.cpp:.o
	${CXX} $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	${CXX} $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re