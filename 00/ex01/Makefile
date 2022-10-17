CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

NAME = phonebook

SRCS = main.cpp \
		Contact.cpp \
		PhoneBook.cpp


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

.PHONY: all clean fclean re test