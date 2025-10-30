# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 14:00:00 by yourname          #+#    #+#              #
#    Updated: 2025/10/30 14:11:41 by natferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src/
INC_DIR = inc/

SRC = $(SRC_DIR)main.cpp \
      $(SRC_DIR)AMateria.cpp \
      $(SRC_DIR)Ice.cpp \
      $(SRC_DIR)Cure.cpp \
      $(SRC_DIR)Character.cpp \
      $(SRC_DIR)MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -f

GREEN  = \033[0;32m
YELLOW = \033[0;33m
RED    = \033[0;31m
RESET  = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@
	@echo "$(YELLOW)Compiling: $<$(RESET)"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)🧹 Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)💥 Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
