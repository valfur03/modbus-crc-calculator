NAME		= crc
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= c++
CFLAGS		+= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
