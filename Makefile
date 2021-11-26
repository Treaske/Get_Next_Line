# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 16:53:48 by ade-blas          #+#    #+#              #
#    Updated: 2021/11/18 16:57:33 by ade-blas         ###   ########.fr        #
#                                                                              #
# **************************************************************************				= gcc
CFLAGS		= -Wall -Werror -Wextra
LIB1		= ar -rcs
RM			= /bin/rm -f

NAME        =get_next_line.a

INCLUDE		=get_next_line.h
SRCS		= get_next_line.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
