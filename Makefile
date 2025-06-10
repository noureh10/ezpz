# @ Author: Nour Echaara
# @ Create Time: 2025-06-02 23:15:47
# @ Modified by: Nour Echaara
# @ Modified time: 2025-06-08 15:01:05

EXECUTABLE_NAME = ezpz
SRC_DIR = src
OBJ_DIR = objects

FILES = $(SRC_DIR)/commands/ACommand.cpp \
        $(SRC_DIR)/commands/Help.cpp \
        $(SRC_DIR)/commands/Interactive.cpp \
        $(SRC_DIR)/commands/Modlist.cpp \
        $(SRC_DIR)/commands/Setconfig.cpp \
        $(SRC_DIR)/commands/Start.cpp \
        $(SRC_DIR)/commands/Status.cpp \
        $(SRC_DIR)/commands/Version.cpp \
        $(SRC_DIR)/main.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:$(SRC_DIR)/%.cpp=%.o))
DEPS = $(OBJ:.o=.d)

HEADER = $(SRC_DIR)/commands/command_header/ACommand.hpp \
         $(SRC_DIR)/commands/command_header/Help.hpp \
         $(SRC_DIR)/commands/command_header/Interactive.hpp \
         $(SRC_DIR)/commands/command_header/Modlist.hpp \
         $(SRC_DIR)/commands/command_header/SetConfig.hpp \
         $(SRC_DIR)/commands/command_header/Start.hpp \
         $(SRC_DIR)/commands/command_header/Status.hpp \
         $(SRC_DIR)/commands/command_header/Version.hpp

CC = c++
CXXFLAGS = -Wall -Wextra -g -std=c++17 -I$(SRC_DIR)

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJ)
	@$(CC) $(CXXFLAGS) $(OBJ) -o $(EXECUTABLE_NAME)
	@printf "$(GREEN)- $(EXECUTABLE_NAME) is ready\n$(RESET)"

run: all
	./$(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)- Object files removed\n$(RESET)"

fclean: clean
	@$(RM) $(EXECUTABLE_NAME)
	@printf "$(YELLOW)- Executable deleted\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re run