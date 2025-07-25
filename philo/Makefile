NAME	= philo

CC		= cc
FLAG	= -Wall -Wextra -Werror -g
THREAD	= -pthread
SANI	= -fsanitize=thread

INCLUDE	= include
DIR_O	= file_o

SRC		= philo.c states.c time.c write.c init.c dinner.c\
		  routine.c checker.c logger.c getter.c setter.c utils.c

GREEN	= \033[1;92m
RED		= \033[1;31m
BLUE	= \033[0;90m

OBJ		= $(patsubst %.c,$(DIR_O)/%.o,$(SRC))

all: $(NAME)

$(DIR_O):
	@mkdir -p $(DIR_O)
	
$(DIR_O)/%.o: %.c | $(DIR_O)
	@echo -e "Compilation de $< vers $@"
	@$(CC) $(FLAG) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $(NAME) && echo -e "$(GREEN)COMPILATION SUCCEED"\
	"\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
	"⣿⣿⣿⣿⣿⣿⣿⠛⢩⣴⣶⣶⣶⣌⠙⠫⠛⢋⣭⣤⣤⣤⣤⡙⣿⣿⣿⣿⣿⣿\n"\
	"⣿⣿⣿⣿⣿⡟⢡⣾⣿⠿⣛⣛⣛⣛⣛⡳⠆⢻⣿⣿⣿⠿⠿⠷⡌⠻⣿⣿⣿⣿\n"\
	"⣿⣿⣿⣿⠏⣰⣿⣿⣴⣿⣿⣿⡿⠟⠛⠛⠒⠄⢶⣶⣶⣾⡿⠶⠒⠲⠌⢻⣿⣿\n"\
	"⣿⣿⠏⣡⢨⣝⡻⠿⣿⢛⣩⡵⠞⡫⠭⠭⣭⠭⠤⠈⠭⠒⣒⠩⠭⠭⣍⠒⠈⠛\n"\
	"⡿⢁⣾⣿⣸⣿⣿⣷⣬⡉⠁⠄⠁$(BLUE)⠄⠄⠄⠄⠄⠄⠄$(GREEN)⣶$(BLUE)⠄⠄⠄⠄⠄⠄⠄⠄$(GREEN)⢀\n"\
	"⢡⣾⣿⣿⣿⣿⣿⣿⣿⣧⡀$(BLUE)⠄⠄⠄⠄⠄⠄⠄$(GREEN)⢀⣠⣿⣦⣤⣀⣀⣀⣀⠄⣤⣾\n"\
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⡶⢇⣰⣿⣿⣟⠿⠿⠿⠿⠟⠁⣾⣿⣿\n"\
	"⣿⣿⣿⣿⣿⣿⣿⡟⢛⡛⠿⠿⣿⣧⣶⣶⣿⣿⣿⣿⣿⣷⣼⣿⣿⣿⣧⠸⣿⣿\n"\
	"⠘⢿⣿⣿⣿⣿⣿⡇⢿⡿⠿⠦⣤⣈⣙⡛⠿⠿⠿⣿⣿⣿⣿⠿⠿⠟⠛⡀⢻⣿\n"\
	"$(BLUE)⠄⠄$(GREEN)⠉⠻⢿⣿⣿⣷⣬⣙⠳⠶⢶⣤⣍⣙⡛⠓⠒⠶⠶⠶⠶⠖⢒⣛⣛⠁⣾⣿\n"\
	"$(BLUE)⠄⠄⠄⠄⠄$(GREEN)⠈⠛⠛⠿⠿⣿⣷⣤⣤⣈⣉⣛⣛⣛⡛⠛⠛⠿⠿⠿⠟⢋⣼⣿⣿\n"\
	"$(BLUE)⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(GREEN)⠈⠉⠉⣻⣿⣿⣿⣿⡿⠿⠛⠃$(BLUE)⠄$(GREEN)⠙⠛⠿⢿⣿\n"\
	"$(BLUE)⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(GREEN)⢬⣭⣭⡶⠖⣢⣦⣀$(BLUE)⠄⠄⠄⠄$(GREEN)⢀⣤⣾⣿\n"\
	"$(BLUE)⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(GREEN)⢰⣶⣶⣶⣾⣿⣿⣿⣿⣷⡄$(BLUE)⠄$(GREEN)⢠⣾⣿⣿⣿"

sani: $(OBJ)
	$(CC) $(SANI) $(FLAG) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)COMPILATION SUCCEED\n$(RED)/!\\ DONT VALGRIND /!\\ \n"\
	"/!\\ DONT VALGRIND /!\\ \n/!\\ DONT VALGRIND /!\\ \n/!\\ DONT VALGRIND /!\\"

clean:
	@rm -rf $(DIR_O) && echo -e "${GREEN}FILE .O DELETED"

fclean: clean
	@rm $(NAME) && echo -e "${GREEN}EXEC DELETED"

re: fclean all

.PHONY: all clean fclean re