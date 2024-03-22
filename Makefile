NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -I./include
SRCDIR	= src
RM		= rm -f

SRC = $(SRCDIR)/main.c \
	$(SRCDIR)/short_sort.c \
	$(SRCDIR)/long_sort.c \
	$(SRCDIR)/stack_utils.c \
	$(SRCDIR)/command.c \
	$(SRCDIR)/check.c \


all: $(NAME)

# Regola per compilare l'eseguibile
$(NAME): $(SRC)
	@make -C libft/
	$(CC) $(CFLAGS) -o bin/$(NAME) $(SRC) -Llibft -lft
	@echo "${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}"
	@${MAKE} camel


# Regola clean per rimuovere gli oggetti
clean:
	@make clean -C libft/

# Regola fclean per rimuovere gli oggetti e l'eseguibile
fclean: clean
	@make fclean -C libft/
	@$(RM) $(NAME)

# Regola re per ricompilare tutto
re: fclean all

# Regola per non considerare i file con questi nomi come obiettivi
.PHONY: all clean fclean re
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
