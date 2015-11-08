NAME = ft_retro
FLAGS = -Wall -Wextra -Werror
SRCS = 		src/Env.class.cpp \
			src/GameEntity.class.cpp \
			src/Enemy.class.cpp \
			src/Player.class.cpp \
			src/HUD.class.cpp \
			src/Timer.class.cpp \
			src/Bonus.class.cpp \
			src/BigShip.class.cpp \
			src/main.cpp

INC = -I./inc

all: make

make:
	clang++ $(NOFLAGS) $(SRCS) -I./inc/ -lncurses -o $(NAME)

re: all

fclean:
	rm $(NAME)
