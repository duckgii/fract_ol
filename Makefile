CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol

LIBFT_DIR = ./libft/
LIB = $(LIBFT_DIR)libft.a 

PRINTF_DIR = ./printf/
PRINT = $(PRINTF_DIR)libftprintf.a

SRCS_DIR = ./mandatory/
SRCS = $(SRCS_DIR)fractol.c\
		$(SRCS_DIR)fractol_utils.c\
		$(SRCS_DIR)key_hook.c\
		$(SRCS_DIR)mouse_hook.c\
		$(SRCS_DIR)calculate_type.c\
		$(SRCS_DIR)ft_atod.c

BONUS_DIR = ./bonus/
BUNUS_SRCS = $(BONUS_DIR)fractol_bonus.c\
			$(BONUS_DIR)fractol_utils_bonus.c\
			$(BONUS_DIR)key_hook_bonus.c\
			$(BONUS_DIR)mouse_hook_bonus.c\
			$(BONUS_DIR)calculate_type_bonus.c\
			$(BONUS_DIR)ft_atod_bonus.c

OBJS = $(SRCS:.c=.o)

BUNUS_OBJS = $(BUNUS_SRCS:.c=.o)

all : $(NAME)

bonus : $(LIB) $(BUNUS_OBJS) $(PRINT)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)
	touch bo

clean : 
	rm -f $(OBJS)
	rm -f $(BUNUS_OBJS) bo
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:
	make fclean
	make all

$(NAME) : $(LIB) $(OBJS) $(PRINT)
		$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $^ -o $@ 

$(LIB) :
	make -C $(LIBFT_DIR) bonus

$(PRINT) : 
	make -C $(PRINTF_DIR) all

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -Imlx -c $< -o $@

$(BUNUS_OBJS) : %.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -Imlx -c $< -o $@

.PHONY : all clean fclean re 



