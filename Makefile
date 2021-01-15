SRCS	=	./ft_strlen.c \
			./ft_putstr_fd.c \
			./ft_strjoin_free.c \
			./ft_strdup_null.c \
			./ft_substr.c \
			./ft_isdigit.c \
			./ft_atoi.c \
			./ft_itoa.c \
			./ft_utoa.c \
			./hexademical_toa.c \
			./get_format.c \
			./get_str_zero.c \
			./get_str_space.c \
			./get_str_minus.c \
			./get_str_d.c \
			./get_str_u.c \
			./get_str_xx.c \
			./get_str_c.c \
			./get_str_s.c \
			./get_str_p.c \
			./ft_printf.c \

NAME	= libftprintf.a
OBJS	= $(SRCS:.c=.o)
INCS	= .
RM		= rm -f
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
