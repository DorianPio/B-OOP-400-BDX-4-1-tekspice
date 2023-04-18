##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Rush 3
##

CC			= 	g++

SRC			=	src/main.cpp						\
				src/parser.cpp						\
				src/output.cpp						\
				src/input.cpp						\
				src/clock.cpp						\
				src/false.cpp						\
				src/true.cpp						\
				src/states_fct.cpp					\
				src/build_model.cpp					\
				src/command.cpp						\
				src/components/C4081_and.cpp		\
				src/components/C4071_or.cpp			\
				src/components/C4069_not.cpp		\
				src/components/C4030_xor.cpp		\
				src/components/C4011_nand.cpp		\
				src/components/C4008.cpp			\
				src/components/C4001_nor.cpp		\
				src/components/C4514.cpp


OBJ			=	$(SRC:.cpp=.o)

NAME		=	nanotekspice

CXXFLAGS 	=	-I./include/ -g

RM_F 		=	rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
				@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && echo "Project \033[32msuccessfully\033[0m compiled." || echo "Project compilation \033[31mfailed\033[0m."

clean:
				@$(RM_F) $(OBJ)

fclean:			clean
				@$(RM_F) $(NAME)

re:				fclean all

%.o:			%.cpp
				@echo -n "Compiling \033[0;33mMyGKrellm\033[0m files: $<"
				@$(CC) $(CXXFLAGS) -c $< -o $@ && echo -e " [\033[32mOK\033[0m]" || echo -e " [\033[31mKO\033[0m]"

.PHONY:			all re $(NAME) clean fclean
