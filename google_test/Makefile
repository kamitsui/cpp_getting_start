# Directories
OBJ_DIR = objs
DEP_DIR = .deps

# Source files
SRCS = \
	   math_functions.cpp
TEST_SRCS = \
			math_functions_test.cpp

# Object files and dependency files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o)) \
	   $(addprefix $(OBJ_DIR)/, $(TEST_SRCS:.cpp=.o))

DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.cpp=.d)) \
	   $(addprefix $(DEP_DIR)/, $(TEST_SRCS:.cpp=.d))

# Build target
NAME=test_exe_math_functions

# Compiler
CXX = c++
CXXFLAGS = #-Wall -Wextra -Werror #-std=c++98
CF_DEP = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Rules for building object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CXX) $(CXXFLAGS) $(CF_DEP) -c $< -o $@

$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: $(NAME)

# Target
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
