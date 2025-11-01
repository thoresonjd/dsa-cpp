# Data Structures & Algorithms Using C++

Implementing various data structures and algorithms in C++ just for fun.

## Data Structures

| Data Structure     | Documentation                                         |
|--------------------|-------------------------------------------------------|
| Binary Search Tree | [binary-search-tree.md](./docs/binary-search-tree.md) |
| Circular Queue     | [circular-queue.md](./docs/circular-queue.md)         |
| Queue              | [queue.md](./docs/queue.md)                           |
| Singly Linked List | [linked-list.md](./docs/linked-list.md)               |
| Stack              | [stack.md](./docs/stack.md)                           |

## Algorithms

| Algorithm   | Documentation                           |
|-------------|-----------------------------------------|
| Bubble Sort | [bubble-sort.md](./docs/bubble-sort.md) |

## Repository Structure

The repository is arranged into the following directories

- `bin` - Contains compiled executables (excluded from repository)
- `docs` - Contains documentation for the data structures and algorithms
- `external` - Contains external, third-party submodules
- `include` - Contains header files for the data structures and algorithms and other utilities
- `make` - Contains Makefiles for the test programs contained in the `test` directory
- `obj` - Contains intermediate object files (excluded from repository)
- `src` - Contains implementation files for the data structures and algorithms and other utilities
- `test` - Contains unit tests that demonstrate the data structures and algorithms

Implementation files within `src` may have the `.tpp` file extension. The `.tpp` extension indicates that the file is an implementation of a templated entity. Template implementations are still kept separate from their headers to follow the typical convention of non-templated implementations. However, since templates cannot be compiled into their own translation units, as templates are not concrete types, these `.tpp` implementation files are included at the bottom of their respective header files in `include`.

## Usage

The data structures and algorithms implemented in this repository are demonstrated through test programs. This repository utilizes the [GoogleTest](https://github.com/google/googletest) framework to perform unit testing on the data structures and algorithms.

This codebase was written in a Linux environment.

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
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./<name>
```

The [`Makefile`](./Makefile) has a rule equivalent to the above command that allows Valgrind to run with any of the test programs (assuming they are already compiled)
```
make vg-<name>
```

