CXX := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98

NAME = zombie

SRCS = Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \
		main.cpp \

OBJS = $(SRCS:.cpp=.o)

.cpp:.o
	${CXX} $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	${CXX} $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re