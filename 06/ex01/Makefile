CXX := c++
INCLUDE_FLAGS := -I includes/
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 ${INCLUDE_FLAGS} -MMD -pedantic

NAME = serialize

SRCS = srcs/main.cpp \
		srcs/Data.cpp

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

.PHONY: all clean fclean re scan-build pre-push
