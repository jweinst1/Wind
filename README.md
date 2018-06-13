# Wind

The Flow-based Programming Language

## Intro

`Wind` is a fast, portable programming language based on the concept of flows, or specifically Flow-based programming . `Wind` is designed to make it easy to filter, map, reduce, through large amounts of dynamic data. Wind is built in a highly unique way that allows data to flow from one container to another. `Wind` views code as a continuous flow of information, not singular programs. `Wind` uses no virtual machine, but a method of transporting and transforming data from one place to another.

Wind filters data with simple, straight forward syntax:

```
wind> push 5 6 77 44 -> out -> filter > 10 -> out -> filter -> out
[ 5 6 77 44 ]
[ 77 44 ]
[ 77 44 ]
wind> out
[ 77 44 ]
```

To optimize both speed and memory usage, `Wind` does not use dynamic memory allocation. It relies on static memory. The advantages of this is to allow the amount of memory Wind uses to be highly customizable at compile time, and to make `Wind` a truly scalable language, one that fits in embedded systems, or much larger, heavy systems.

Wind, although not a *natively* compiled language, also is not a true interpreted language. It does not use it's own byte code instruction set, nor does it form abstract syntax trees from source code. It reads code as data and executes it directly.

## Installation

To build `Wind` from source, run the following command in your terminal

```
$ make all
```

To clean excess build files, run

```
$ make clean
```

### Memory Customization

In `Wind`, you can fully customize and scale the amount of memory wind uses. To do this, there are a few vars in `Makefile` that control the memory used by various buffers in the language.

#### `WIND_MEM_BUF`:

This variable determines the sizes of the active and inactive buffers, where the current data of the running wind program lives. This size correlates to an amount of bytes.

#### `WIND_MEM_LOAD`:

Controls the amount of memory used by the loading buffer. Generally limits the amount of arguments that can "flow" over a command.

#### `WIND_MEM_COMP`:

Controls the amount of memory used by the computation buffer. This limits the size of individual values `Wind` can handle.

However, you can just leave these as is and use their default values.

## Usage

Once you build `Wind`, you will have an executable under the `bin/` directory. You can run it with several commands.

Running the executable with no commands opens the repl, which allows you to interactively execute Wind code. Here's an example:

```
Wind - Version (0.0.1)
The Wind Programming Language REPL
To exit, simply enter 'exit'.
wind> push 7 7 7 8
wind> out
[ 7 7 7 8 ]
wind> map + 5 | / 3
wind> out
[ 4 4 4 4.333 ]
wind> filter > 4 -> out
[ 4.333 ]
wind> exit
```
At any time in the repl, typing `exit`, will close the program.

#### `-c`:

The `-c` flag allows you to run a string of `Wind` code, like this

```
$ Wind -c "push 5 -> out -> clr"
[ ]
```

#### `-d`:

The `-d` flag allows you to run a string of `Wind` code and also get debug information

```
$ Wind -d "push 5 6 77 44 -> out -> filter > 10 -> out -> filter < 76 -> out"
[ 5 6 77 44 ]
[ 77 44 ]
[ 44 ]
_____Wind___Debug_______
..........State.........
Has Error: false
Mode: Command
Command: null
..........Data.........
Load Buffer: -> [ ]
Active Buffer: -> [ 44 ]
Inactive Buffer: -> [ 77 44 ]
________________________
```

#### `-t`:

The `-t` flag allows for a string of `Wind` code to be run and timed:

```
Wind -t "push 5 3 4 -> reduce + -> out -> push 6 6 6 6 6 6 6 -> reduce + -> out -> push 6 5 -> map * 7 -> reduce + -> out"
[ 12 ]
[ 54 ]
[ 455 ]
Time: 0.000081
```


## Stage

`Wind` is currently in the alpha development stage, the first release version is still in progress.
