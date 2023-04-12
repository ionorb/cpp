# VARIABLES
COMPILER	= c++
INCLUDES	= ./
FLAGS		= -std=c++98
FLAGS		+= -Wall -Wextra -Werror
FLAGS		+= -g3
FLAGS		+= -I$(INCLUDES)

BINARY = account

SOURCES_DIR		= ./
SOURCES_FILES	=	Account.cpp \
					tests.cpp
SRCS			= $(addprefix $(SOURCES_DIR), $(SOURCES_FILES))

OBJECTS_DIR		= objs/
OBJECTS_FILES	= $(SOURCES_FILES:.cpp=.o)
OBJS			= $(addprefix $(OBJECTS_DIR), $(OBJECTS_FILES))

# RULES
all: $(BINARY)

$(BINARY): $(OBJS)
	@echo "linking objects"
	$(COMPILER) $(FLAGS) $(SRCS) -o $(BINARY)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.cpp
	@mkdir -p $(OBJECTS_DIR)
	@$(COMPILER) $(FLAGS) -c $< -o $@

fclean:
	@echo "removing binary"
	@rm -f $(BINARY)
	@make --no-print-directory clean

clean:
	@echo "removing .o files"
	@rm -rf objs/

re:
	@make --no-print-directory fclean
	@make --no-print-directory all

.phony: clean fclean re