# Wind

The Flow-based Programming Language

## Intro

`Wind` is a fast, portable programming language based on the concept of flows, or specifically Flow-based programming . `Wind` is designed to make it easy to filter, map, reduce, through large amounts of dynamic data. Wind is built in a highly unique way that allows data to flow from one container to another. `Wind` views code as a continuous flow of information, not singular programs. `Wind` uses no virtual machine, but a method of transporting and transforming data from one place to another.

Wind filters data with simple, straight forward syntax:

```
> push 5 6 77 44 -> out -> filter > 10 -> out -> filter -> out
[ 5 6 77 44 ]
[ 77 44 ]
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



## Stage

`Wind` is currently in the alpha development stage, the first build is still in progress.
