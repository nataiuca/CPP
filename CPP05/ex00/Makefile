# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 21:22:16 by natferna          #+#    #+#              #
#    Updated: 2025/11/06 20:41:39 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp Bureaucrat.cpp
OBJ		= $(SRC:.cpp=.o)

RM = rm -f

GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

%.o: %.cpp Bureaucrat.hpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling: $<$(RESET)"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)🧹 Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)💥 Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
