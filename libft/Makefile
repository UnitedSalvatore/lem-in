NAME =	libft.a

LIBFT_DIR		= ./libft
LIBFT_SRC		= $(addprefix $(LIBFT_DIR)/, $(shell cat $(LIBFT_DIR)/FILENAMES))
LIBFT_OBJ		= $(LIBFT_SRC:.c=.o)

FT_GETLINE_DIR	= ./ft_getline
FT_GETLINE_SRC	= $(addprefix $(FT_GETLINE_DIR)/, $(shell cat $(FT_GETLINE_DIR)/FILENAMES))
FT_GETLINE_OBJ	= $(FT_GETLINE_SRC:.c=.o)

FT_PRINTF_DIR	= ./ft_printf
FT_PRINTF_SRC	= $(addprefix $(FT_PRINTF_DIR)/, $(shell cat $(FT_PRINTF_DIR)/FILENAMES))
FT_PRINTF_OBJ	= $(FT_PRINTF_SRC:.c=.o)

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./include/

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(FT_GETLINE_OBJ) $(FT_PRINTF_OBJ)
	ar rc $(NAME) $(LIBFT_OBJ) $(FT_GETLINE_OBJ) $(FT_PRINTF_OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(LIBFT_DIR)/*.o
	rm -f $(FT_GETLINE_DIR)/*.o
	rm -f $(FT_PRINTF_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
