# Wind

[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](https://github.com/jweinst1/Wind/blob/master/LICENSE.md)

The Flow-based Programming Language

![Main Md Gif](images/intro_wind.gif)`

# Table of Contents

- [Intro](#intro)
- [Installation](#installation)
  - [Memory Customization](#memory-customization)
     - [wind mem buf](#wind_mem_buf)
     - [wind mem load](#wind_mem_load)
     - [wind mem comp](#wind_mem_comp)
- [Usage](#usage)
- [Guide](#guide)
  - [Syntax](#syntax)
     - [Syntax Errors](#syntax-errors)
  - [Types](#types)
     - [None](#none)
  - [Commands](#commands)
     - [out](#out)
     - [push](#push)
     - [clr](#clr)
     - [map](#map)
     - [filter](#filter)
     - [reduce](#reduce)
     - [save](#save)
     - [load](#load)
- [Stage](#stage)

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

It can also seamlessly reduce and transform data

```
wind> push 5 5 5 -> out
[ 5 5 5 ]
wind> map ** 4 | - 1 -> reduce +
wind> out
[ 1872 ]
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

#### `-h`:

The `-h` flag prints the `Wind` help manual to stdout. You can find more detailed guides in the wiki for this repo. A website in the near future will have a full fledged documentation.

## Guide

The following details the language components, features, and syntax.

### Syntax

The `Wind` language uses a continuous, stream-like syntax. It is meant to be read in a linear, straight fashion that emphasizes fixed units of commands and computation.

The general format of `Wind` is the following:

```
(command) (arguments ...) -> (command) (arguments ...)
```

Comments are denoted by bounded semicolons, between `;`, such as

```
push 5 -> ;this is a comment; out
```
where anything between the semicolons is ignored.

The `->` symbol indicates the end of one command-argument sequence and the transition of `Wind` to execute that command with the read arguments. More information about the low level architecture of `Wind` will be available in the wiki.

#### Syntax Errors

Commands and arguments to commands, (values), share separate namespaces. Any incorrect command or value picked up by `Wind` will result in a syntax error. Here is an example:

```
wind> push l -> out
Error: Expected argument or value, found 'l'
```
`l` does not correspond to any recognizable value.

### Types

The `Wind` language uses several types, all of which are immutable. `Wind` formats data in a marked, binary format. The language does not use heap-allocated types or objects. All types are kept on various `static` arrays. This enables very simple copying and flowing of data.

#### None

The `None` type in Wind signifies a singular state value of being nothing. It is similar to `nil` or `null` in other languages. There isn't a whole lot to do with None, but None corresponds to a false boolean value. 

In certain boolean operations, like the not operator, `!`, it will evaluate to `False`.

```
wind> push None None None -> out
[ None None None ]
wind> map ! -> out
[ False False False ]
``` 

### Commands

The `Wind` language uses an effecient set of commands to manipualte and process a flow of data. Commands are named words that appear before an arbitrary sequence of arguments.

#### out

The `out` command prints the currently active data into stdout.

*Example*

```
wind> push 5 -> out
[ 5 ]
wind> clr -> out
[ ]
```

#### push

The `push` command appends new data to the end of the active data. It can take an arbitrary number of arguments.

*Example*

```
wind> push None True False 0 1 2 3
wind> out
[ None True False 0 1 2 3 ]
```

#### clr

The `clr` command clears all the data from the active buffer. This doesn't incur the cost of erasing data, it simply sets the end of the active buffer back to the beginning, and allows overwriting of the old data. It takes no arguments.

*Example*

```
wind> push 3 3 3 3 -> out
[ 3 3 3 3 ]
wind> clr -> out
[ ]
```

#### map

The `map` command transforms data over a flow of operations. Mapping can take place with a variety of operations, such as adding, subtracting, assigning, and much more. Besides for the `Del` op, mapping never erases data.

```
wind> push 6 7 8 9 10 12 14
wind> out -> map + 1 | * 3 -> out
[ 6 7 8 9 10 12 14 ]
[ 21 24 27 30 33 39 45 ]
wind> map / 55 | ** 3 -> out
[ 0.056 0.083 0.118 0.162 0.216 0.357 0.548 ]
```
Within the arguments read after a `map` command, each oper symbol can have only specific values that are valid after it. The pipe `|` is used to transition to the mapping of another symbol and it's sub-arguments. Attempting to map unmappable types results in an error:

```
wind> push 5 5 5
wind> map + 5 3 2
wind> out
[ 15 15 15 ]
wind> map + 4 - 3
Error: Attempted to use + operator on arg with type: 'Minus'
```
Some types in `Wind` can be treated as having number values. In this case, they can be used in mapping operations that involve typically number operations such as `+`:

```
wind> push 7 -> out
[ 7 ]
wind> push 5 -> map + True False 1 -> out
[ 9 7 ]
```

#### filter

The `filter` command allows the limitation and restriction of a data flow. It permits the passing or failing of flowing from the one buffer to another based on a boolean condition. The `filter` command can be used with operators like `>` and `<`.

```
wind> push 6 7 8 9 15.04 -> out
[ 6 7 8 9 15.040 ]
wind> filter > 8 -> out
[ 9 15.040 ]
wind> filter > 15.02 -> out
[ 15.040 ]
```

#### reduce

The `reduce` command fuses and squashes data together into smaller data, or in many cases a single value. For now, `reduce` only works with one operator, `+`, but many more will be added in the future.

```
wind> push 666 777 888 -> out
[ 666 777 888 ]
wind> map ** 3 -> out -> reduce +
[ 295408296 469097433 700227072 ]
wind> out
[ 1464732801 ]
```

#### save

The `save` command allows the current, active data inside Wind to be saved to an file on disk with the `.bwind` file extension. More info on the binary specification can be found in the wiki. The idea behind this command, and the `load` command is it allows `Wind` to process and emit data in an instantly available format. Internally, `save` is just a write of the active buffer bytes to a file.

```
wind> push True False 3 2 -> out
[ True False 3 2 ]
wind> save "samplefile"
Saved at: samplefile.bwind
```

The argument to save is always a string that indicates a path, without the extension. The newly created file will have a sequence of bytes formatted like this:

```
[bool mark][bool body = 1]
[bool mark][bool body = 0]
[number mark][number body = 3 <double>]
[number mark][number body = 2 <double>]
```
Where the bool body is a single byte, and the number body is a 64-bit floating point number. The pattern of the `Wind` binary format is using typed sequences of bytes. A large advantage of this is internally, it makes data easily copyable and immutable.

#### load

The `load` command is used to load `.bwind` files into the active buffer. This command permits direct, instant access to `Wind` typed data stored on disk. As explained previously, the loading and saving components of `Wind` allows the processing of data across a broader, vaster set of data than what can be stored inside the active buffer.

```
wind> push None 5 5 -> out
[ None 5 5 ]
wind> save "test"
Saved at: test.bwind
wind> clr -> out
[ ]
wind> load "test" -> out
Loaded data from: test.bwind
[ None 5 5 ]
```
If the file path attempting to be loaded from cannot be read or does not exist, you will get an error like this:

```
wind> load "test1"
Error: File path 'test1' cannot be read from.
```

## Stage

`Wind` is currently in the alpha development stage, the first production release version is still in progress. The language format and overall scheme will not change, but many components and values will be added to it in the near future. When an initial release is made, a specification for the language will also be published.
