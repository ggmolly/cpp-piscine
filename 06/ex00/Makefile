CXX := c++
INCLUDE_FLAGS := -I includes/
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 ${INCLUDE_FLAGS} -MMD -pedantic

NAME = convert

SRCS = srcs/main.cpp \
		srcs/char.cpp \
		srcs/double.cpp \
		srcs/float.cpp \
		srcs/int.cpp \

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

.cpp:.o
	${CXX} $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile
	${CXX} $(CXXFLAGS) -o $(NAME) $(OBJS)

-include $(OBJS:.o=.d)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

# Custom rules to reinforce rigor

leak-test: all
	valgrind --leak-check=full --show-below-main=yes --show-leak-kinds=all ./$(NAME)

scan-build: fclean clean
	scan-build-12 make | grep "^scan-build:"

pre-push: scan-build leak-test
	make fclean

test: all
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	./$(NAME) 42.0
	./$(NAME) 42.1234
	./$(NAME) 127
	./$(NAME) 2147483648
	./$(NAME) -2147483649
	./$(NAME) 12312312312312312312312312364554654564564456456456546456987887879987978789789789978174174147225582583396369369
	./$(NAME) -12312312312312312312312312364554654564564456456456546456987887879987978789789789978174174147225582583396369369
	./$(NAME) A

.PHONY: all clean fclean re scan-build pre-push
