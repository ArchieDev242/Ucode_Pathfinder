CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic
EXECUTABLE := pathfinder
LIBRARY := libmx/libmx.a

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc
LIB_INC_DIR := libmx/inc

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: all clean uninstall reinstall

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIBRARY) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -Llibmx -lmx -o $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/*.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_INC_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBRARY):
	make -C libmx

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(LIBRARY)
	rm -f $(EXECUTABLE)

uninstall: clean
	make -sC libmx uninstall
	rm -f $(LIBRARY)

reinstall: uninstall all
