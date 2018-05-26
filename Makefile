CC = gcc
INC_DIR = include

WIND_MEM_BUF = 100000
WIND_MEM_LOAD = 10000

C_FILES := $(wildcard src/*/*.c)
OBJ_FILES := $(patsubst src/%,lib/%,$(C_FILES:.c=.o))
LD_FLAGS :=
MEM_FLAGS := -DWindData_BUF_SIZE=$(WIND_MEM_BUF) -DWindData_LOAD_SIZE=$(WIND_MEM_LOAD)
CC_FLAGS := -c -Wall -I$(INC_DIR) $(MEM_FLAGS)

clean:
	rm -rf bin
	rm -rf lib

all: bin/Wind

bin/Wind: $(OBJ_FILES) ; $(CC) $(LD_FLAGS) -o $@ $^ | mkdir -p bin

lib/%.o: src/%.c
	    mkdir -p $(dir $@)
	    $(CC) $(CC_FLAGS) -c -o $@ $<
