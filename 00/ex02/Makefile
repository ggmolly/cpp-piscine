CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = test

SRCS = tests.cpp \
		Account.cpp \


OBJS = $(SRCS:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re