NAME		= ex03

CC			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/

SRC_FILES	= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
            $(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
            mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
            $(CC) $(CXXFLAGS) -c $< -o $@

clean:
            $(RM) $(OBJ_DIR)

fclean:		clean
            $(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re