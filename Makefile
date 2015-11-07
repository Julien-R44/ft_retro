NAME = ft_retro
SRCS = Env.class.cpp \
			GameEntity.class.cpp \
			Logger.class.cpp \
			main.cpp

all: make

make:
	g++ -Wall -Wextra -Werror $(SRCS) -lncurses -o $(NAME)

re: all

fclean:
	rm $(NAME)
