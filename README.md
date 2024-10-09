# Data Structures & Algorithms Using C++

Implementing various data structures and algorithms in C++ just for fun.

## Repository Structure

- `bin` - Contains compiled executables (excluded from repository)
- `docs` - Contains documentation for the data structures and algorithms
- `external` - Contains external, third-party submodules
- `include` - Contains header files for the data structures and algorithms and other utilities
- `make` - Contains Makefiles for the test programs contained in the `test` directory
- `obj` - Contains intermediate object files (excluded from repository)
- `src` - Contains implementation files for the data structures and algorithms and other utilities
- `test` - Contains unit tests that demonstrate the data structures and algorithms

## Usage

The data structures and algorithms implemented in this repository are demonstrated through test programs. This repository utilizes the [GoogleTest](https://github.com/google/googletest) framework to perform unit testing on the data structures and algorithms.

### Compilation

Compilation can be done from the root directory of the repository.

To compile an test program, run
```
make <name>
```
where \<name\> is the name of the test program. The name of a test program is the same as it's main file name minus the extension.

When building a program, `obj/` and `bin/` directories will be created if they do not already exist. This is done automatically through the "setup" target in the [`Makefile`](./Makefile), but this can be done manually as well via
```
make setup
```

To compile all programs, simply run
```
make [all]
```

To remove the `obj/` and `bin/` directories, run
```
make clean
```

### Execution

To run a test program, find the compiled executable in the `bin/` directory and run it via
```
./<name>
```
From the root directory of the repository, programs can be executed via
```
./bin/<name>
```

Valgrind is used to check for memory leaks.
```
valgrind --leak-check=full --show-leak-kinds=all ./<name>
```

## Data Structures

| Data Structure        | Documentation                           |
|-----------------------|-----------------------------------------|
| Queue                 | [queue.md](./docs/queue.md)             |
| Singly Linked List    | [linked-list.md](./docs/linked-list.md) |
| Stack                 | [stack.md](./docs/stack.md)             |

## Algorithms

TODO
