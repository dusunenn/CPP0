NAME = PhoneBook
CXX= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
src = Contact.cpp PhoneBook.cpp main.cpp
obj = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(src)
	$(CXX) $(CFLAGS) $(src) -o $(NAME)
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
