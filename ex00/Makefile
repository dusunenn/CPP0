NAME = megaphone
cc = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
src = ex00.cpp
obj = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(src)
	$(cc) $(CFLAGS) $(src) -o $(NAME)
%.o: %.cpp
	$(cc) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
