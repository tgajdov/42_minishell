# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
#LDFLAGS = -I /Users/$(shell whoami)/.brew/opt/readline/include/readline -L /Users/$(shell whoami)/.brew/opt/readline/lib -L./Libft -lft -lreadline -lhistory -lncurses #Version avec readline de brew sur le mac
LDFLAGS = -I./Readline -L./Readline -L./Libft -lft -lreadline -lhistory -lncurses #ORIGINAL AVEC LE DOSSIER READLINE DU PROJET
#-L .brew/opt/readline/lib
#-I .brew/opt/readline/include


# Directories
SRC_DIR = .
OBJ_DIR = ./obj
INC_DIR = ./Include
LIBFT_DIR = ./Libft

# Source files
SRC_MAIN = $(wildcard $(SRC_DIR)/*.c)
SRC_FIRSTPARSE = $(wildcard $(SRC_DIR)/FirstParse/*.c)
SRC_PARSING = $(wildcard $(SRC_DIR)/Parsing/*.c)
SRC_OPERATORS = $(wildcard $(SRC_DIR)/Operators/*.c)
SRC_CMD = $(wildcard $(SRC_DIR)/Cmd/*.c)
SRC_LEXING = $(wildcard $(SRC_DIR)/Lexing/*.c)
SRC_MNSH = $(wildcard $(SRC_DIR)/Mnsh/*.c)
SRC_UTILS = $(wildcard $(SRC_DIR)/Utils/*.c)

# Object files
OBJ_MAIN = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_MAIN))
OBJ_FIRSTPARSE = $(patsubst $(SRC_DIR)/FirstParse/%.c,$(OBJ_DIR)/FirstParse/%.o,$(SRC_FIRSTPARSE))
OBJ_PARSING = $(patsubst $(SRC_DIR)/Parsing/%.c,$(OBJ_DIR)/Parsing/%.o,$(SRC_PARSING))
OBJ_OPERATORS = $(patsubst $(SRC_DIR)/Operators/%.c,$(OBJ_DIR)/Operators/%.o,$(SRC_OPERATORS))
OBJ_CMD = $(patsubst $(SRC_DIR)/Cmd/%.c,$(OBJ_DIR)/Cmd/%.o,$(SRC_CMD))
OBJ_LEXING = $(patsubst $(SRC_DIR)/Lexing/%.c,$(OBJ_DIR)/Lexing/%.o,$(SRC_LEXING))
OBJ_MNSH = $(patsubst $(SRC_DIR)/Mnsh/%.c,$(OBJ_DIR)/Mnsh/%.o,$(SRC_MNSH))
OBJ_UTILS = $(patsubst $(SRC_DIR)/Utils/%.c,$(OBJ_DIR)/Utils/%.o,$(SRC_UTILS))

# Executable
EXECUTABLE = minishell

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Rule to make the executable
$(EXECUTABLE): $(OBJ_MAIN) $(OBJ_FIRSTPARSE) $(OBJ_PARSING) $(OBJ_OPERATORS) $(OBJ_CMD) $(OBJ_LEXING) $(OBJ_MNSH) $(OBJ_UTILS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to make object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	make directories
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

directories:
	mkdir -p $(OBJ_DIR)/FirstParse $(OBJ_DIR)/Parsing $(OBJ_DIR)/Operators $(OBJ_DIR)/Cmd $(OBJ_DIR)/Bonus $(OBJ_DIR)/Lexing $(OBJ_DIR)/Mnsh $(OBJ_DIR)/Utils

# Rule to compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Rule for cleaning object files
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Rule for cleaning the executable
fclean: clean
	rm -f $(EXECUTABLE)
	rm -f $(LIBFT)

# Rule for re-making everything
re: fclean all

# Default rule to build the executable
all: $(EXECUTABLE)

.PHONY: all clean fclean re directories
