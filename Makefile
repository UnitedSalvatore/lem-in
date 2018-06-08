NAME = lem-in

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = main.c \
			read_data.c \
			parse.c \
			validate.c \
			connect_rooms.c \
			find_path.c \
			errors.c \
			functions.c 

SOURCES = $(addprefix ./src/, $(FILENAMES))
OBJECTS = $(addprefix ./, $(SOURCES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror -g
FLAGS += -I./

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) -o $@ $(FLAGS) $(OBJECTS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)/

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make -C $(LIBFT_DIR)/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
