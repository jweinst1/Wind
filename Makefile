# Wind Make File

CC = gcc
# Header Directory
INC_DIR = include

# Determines the static memory size used for the data buffers.
# This value should be higher than WIND_MEM_LOAD
WIND_MEM_BUF = 50000
# Determines the static memory size used for the load buffer.
# This value should be less than WIND_MEM_BUF
WIND_MEM_LOAD = 10000
# Determines the static memory size used for the computation buffer.
# This value should always be less than WIND_MEM_LOAD and WIND_MEM_BUF
# If large WindValues to not need to be handled, this can be left at a very low number.
WIND_MEM_COMP = 2000

C_FILES := $(wildcard src/*/*.c)
OBJ_FILES := $(patsubst src/%,lib/%,$(C_FILES:.c=.o))
LD_FLAGS :=
MEM_FLAGS := -DWindData_BUF_SIZE=$(WIND_MEM_BUF) -DWindData_LOAD_SIZE=$(WIND_MEM_LOAD) -DWindComp_BUF_SIZE=$(WIND_MEM_COMP)
CC_FLAGS := -c -Wall -I$(INC_DIR) $(MEM_FLAGS)

# Cleans old and rebuilds all object files
build:
	make clean
	make all

clean:
	rm -rf bin
	rm -rf lib

all: bin/Wind

bin/Wind: $(OBJ_FILES) ; $(CC) $(LD_FLAGS) -o $@ $^ | mkdir -p bin

lib/%.o: src/%.c
	    mkdir -p $(dir $@)
	    $(CC) $(CC_FLAGS) -c -o $@ $<
