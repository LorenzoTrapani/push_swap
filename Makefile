NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -I./include
SRCDIR	= src
BINDIR = bin
RM		= rm -f

SRC = main.c \
	short_sort.c \
	long_sort.c \
	stack_utils.c \
	check.c \
	free.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	swap.c \
	set.c \
	insertion_sort.c \

OBJ := $(SRC:%.c=$(SRCDIR)/%.o)

all: $(BINDIR)/$(NAME)

$(BINDIR)/$(NAME): $(OBJ)
	@make -C libft/
	$(CC) $(CFLAGS)  $(OBJ) -o $@ -Llibft -lft
	@echo "${BOLD}Creating  -> ${RED}${NAME}${NO_COLOR}"
	@${MAKE} camel

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft/
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C libft/
	@$(RM) $(BINDIR)/$(NAME)
	@echo "${BOLD}Cleaning  -> ${RED}${NAME}${NO_COLOR}"
	@${MAKE} camel_clean

re: fclean all

.PHONY: clean fclean re all
.SILENT:

RED         := ${shell tput setaf 1}
BLUE        := ${shell tput setaf 4}
NO_COLOR    := ${shell tput sgr0}
BOLD        := ${shell tput bold}

camel:
	
	@echo '	    ⣎⣓⢶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ '
	@echo '	⢰⡩⢪⡁⢉⣿⠄⢿⣶⠆⠀⠀⠀⡠⠒⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo '	⣾⣀⣎⡱⢢⡉⠴⠀⡾⠀⠀⠀⡸⠒⠀⠀⠱⡄⠀⠀⠀⠀⠀⠀⠀'
	@echo '	⠙⠛⠁⠀⠘⠀⠀⢸⠁⢀⠠⠮⣤⣀⣀⡀⣀⣸⠷⠦⢀⠀⠀⠀⠀'
	@echo '	⠀⠀⠀⠀⠘⡄⠀⠈⠒⡎⠀⠀⠀⠀⠈⠉⠉⠀⠀⠈⢒⠵⠀⠀⠀'
	@echo '	⠀⠀⠀⠀⠀⠈⠢⠄⡀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠘⣗⡀⠀⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠈⡟⡀⠀⠀⣰⣞⣀⢠⠶⡀⠀⠸⡉⢳⠦⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⢡⠀⠠⠃⠀⠀⠈⠶⡈⠣⡀⢱⠵⣀⠇'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣰⠀⢰⠀⠀⠀⠀⠀⠈⢣⢥⢠⠇⠹⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢩⠏⠇⠀⠀⠀⠀⠀⢀⢆⠞⡜⠀⠀⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⢀⣠⠎⠜⠐⡄⠀⠀⠀⣀⡠⠊⣦⠂⠃⠀⠀⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠈⠛⠯⢎⣢⡥⠀⠀⠘⠺⠼⢮⡟⣄⠇⠀⠀⠀'

camel_clean:
	
	@echo '	    ⣎⣓⢶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ '
	@echo '                               '
	@echo '	⣾⣀⣎⡱⢢⡉⠴⠀⡾⠀⠀⠀⡸⠒⠀⠀⠱⡄⠀⠀⠀⠀⠀⠀⠀'
	@echo ''
	@echo '	⠀⠀⠀⠀⠘⡄⠀⠈⠒⡎⠀⠀⠀⠀⠈⠉⠉⠀⠀⠈⢒⠵⠀⠀⠀'
	@echo ''
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠈⡟⡀⠀⠀⣰⣞⣀⢠⠶⡀⠀⠸⡉⢳⠦⠀'
	@echo ''
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣰⠀⢰⠀⠀⠀⠀⠀⠈⢣⢥⢠⠇⠹⠀'
	@echo '⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⢀⣠⠎⠜⠐⡄⠀⠀⠀⣀⡠⠊⣦⠂⠃⠀⠀⠀'
	@echo ''