CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME := Libmx
EXECUTABLE := libmx.a

.PHONY: all clean uninstall reinstall

all: $(NAME)

$(NAME):
	mkdir -p ./obj
	$(CC) $(CFLAGS) -c ./src/*.c
	mv ./*.o ./obj
	ar rcs $(EXECUTABLE) ./obj/*.o

clean:
	rm -rf ./obj

uninstall:
	rm -rf ./obj
	rm -rf $(EXECUTABLE)

reinstall: uninstall $(NAME)
