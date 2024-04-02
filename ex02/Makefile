NAME 		= 	Identify

SRCS		=	main.cpp 
OBJS		=	$(SRCS:.cpp=.o)

CC = g++
CFLAGS = -std=c++03 -Wall -Wextra -Werror -gdwarf-4 -Wno-unused
 CFLAGS += -g3 
# CFLAGS += -fsanitize=address
ifeq ($(DEBUG),true)
	CFLAGS += -g
endif
OCFLAGS		=	-Wall -Wextra -Werror

all:	 		$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OCFLAGS) $(OBJS) -o $@

%.o: %.cpp
	 $(CC) $(CFLAGS) -c $< -o $@

clean:
				@rm -f $(OBJS)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all
