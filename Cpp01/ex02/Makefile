NAME		= brain

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98


SRC_FILES	=	main.cpp \

SRCS		=	$(SRC_FILES)
OBJS		=	$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re