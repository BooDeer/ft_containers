CC = c++

NAME = containers

FLAGS = -std=c++98 -Wall -Wextra -Werror \
		-g									# Debugging line

UNAME_S = $(shell uname -s)	# check which Os am I using

FILE = main.cpp

all: $(NAME)
	@echo "Creating the program..."

$(NAME):
	@c++ main.cpp && ./a.out
# @echo "reached here"
# ifeq ($(UNAME_S),Linux)			#* Linux
# 	g++ $(FLAGS) $(FILE) -o $(NAME)
# else ifeq ($(UNAME_S), Darwin)	#* Macos
# 	c++ $(FLAGS) $(FILE) -o $(NAME)
# endif

t:
	@c++ test.cpp && ./a.out

#TODO: check why the below code doesn't work properly
# ifeq ($(UNAME_S),Linux)			#* Linux
# 	@g++	test.cpp
# 	./a.out
# else ifeq ($(UNAME_S), Darwin)	#* Macos
# 	@c++ test.cpp && ./a.out
# endif

re: clean all

clean:
	@echo "Deleting the program..."
	@rm -f $(NAME)

fclean: clean
