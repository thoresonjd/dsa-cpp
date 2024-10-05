# Data Structures & Algorithms Using C++

Implementing various data structures and algorithms in C++ just for fun.

## Repository Structure

- `bin` - Contains compiled executables (excluded from repository)
- `include` - Contains header files for the data structures and algorithms and other utilities
- `external` - Contains external, third-party submodules
- `make` - Contains Makefiles for the programs in `test`
- `obj` - Contains intermediate object files (excluded from repository)
- `src` - Contains implementation files for the data structures and algorithms and other utilities
- `test` - Contains unit tests that demonstrate the data structures and algorithms

## Usage

The data structures and algorithms implemented in this repository are demonstrated through test programs. This repository utilizes the [GoogleTest](https://github.com/google/googletest) framework to perform unit testing on the data structures and algorithms.

### Compilation

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
make
```
or
```
make all
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
From the root of the repository, programs can be executed via
```
./bin/<name>
```

Valgrind is used to check for memory leaks.
```
valgrind --leak-check=full --show-leak-kinds=all ./<name>
```

## Data Structures

<table>
    <tr>
        <th>Data Structure</th>
        <th>Header</th>
        <th>Implementation</th>
    </tr>
    <tr>
        <td>Linked List</td>
        <td><a href="./include/linked-list.h">include/linked-list.h</a></td>
        <td><a href="./src/linked-list.tpp">src/linked-list.tpp</a></td>
    </tr>
</table>

## Algorithms

TODO
