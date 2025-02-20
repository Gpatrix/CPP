CC		= c++
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

RM		= rm -f

NAME	= whatever

FILE	= main.cpp

OBJS	= $(FILE:%.cpp=%.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
