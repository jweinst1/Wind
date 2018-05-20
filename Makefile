CC = gcc
INC_DIR = include

C_FILES := $(wildcard src/*/*.c)
OBJ_FILES := $(patsubst src/%,lib/%,$(C_FILES:.c=.o))
LD_FLAGS :=
CC_FLAGS := -c -Wall -I$(INC_DIR) -DWindData_BUF_SIZE=50000

clean:
	rm -rf bin
	rm -rf lib

all: bin/Wind

bin/Wind: $(OBJ_FILES) ; $(CC) $(LD_FLAGS) -o $@ $^ | mkdir -p bin

lib/%.o: src/%.c
	    mkdir -p $(dir $@)
	    $(CC) $(CC_FLAGS) -c -o $@ $<
