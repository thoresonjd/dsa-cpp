# Data Structures & Algorithms Using C++

Implementing various data structures and algorithms in C++ just for fun.

## Repository Structure
- `bin` - Contains compiled executables (excluded from repo)
- `examples` - Contains programs that demonstrate the data structures and algorithms (DSAs)
- `include` - Contains header files for the DSAs and other utilities
- `make` - Contains Makefiles for the programs in `examples`
- `obj` - Contains intermediate object files (excluded from repo)
- `src` - Contains implementation files for the DSAs and other utilities

## Usage

### Compilation

To compile an example program, run
```
make <name>
```
where \<name\> is the name of the example program. The name of an example program is the same as it's main file name minus the extension.

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

To remove the `obj/` and `bin/` directories, as well as the `log` file, run
```
make clean
```

### Execution

To run an example program, find the compiled executable in the `bin/` directory and run it via
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
        <th>Example</th>
    </tr>
    <tr>
        <td>Linked List</td>
        <td><a href="./include/linked-list.h">include/linked-list.h</a></td>
        <td><a href="./src/linked-list.tpp">src/linked-list.tpp</a></td>
        <td><a href="./examples/linked-list.cpp">examples/linked-list.cpp</a></td>
    </tr>
</table>

## Algorithms

TODO

## Utilities

<table>
    <tr>
        <th>Name</th>
        <th>Header</th>
        <th>Implementation</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>Logger</td>
        <td><a href="./include/logger.h">logger.h</a></td>
        <td><a href="./src/logger.cpp">include/logger.cpp</a></td>
        <td><a href="./examples/logger.cpp">src/logger.cpp</a></td>
    </tr>
</table>