# C++ Programming : Chess Game

## Structure
``` text
.
├── CMakeLists.txt
├── app
│   └── main.cpp
├── include
│   ├── example.h
│   └── exampleConfig.h.in
├── src
│   └── example.cpp
└── tests
    ├── dummy.cpp
    └── main.cpp
```

Sources go in [src/](src/), header files in [include/](include/), main programs in [app/](app), and
tests go in [tests/](tests/) (compiled to `unit_tests` by default).


## 24/02/2023:
- Choice of the container to store pieces' pointers
- Inheritance of piece 

## 03/03/2023:
- Pieces displacements and rules
- Permitted movements
- Checks and error management

## 10/03/2023
- Project structure
- Testbase
- Initialization of the board with a string
- Pawn displacement : diagonal
- Chessmate
- Pawn promotion
- hasmoved not an attribute of piece anymore (only board role). 
Hasmoved is stored in the board map, the value becomes a tuple of pointer piece and the boolean.
- Castling short & long

## 17/03/2023
- Code refactoring
- Potential moves & general tree
- the 'x' piece for debug

## 23/03/2023
- Change map to unordered_map with hash values for custom types
- Add score to tree nodes (heuristic function) in order to perform minimax

## 26/04/2023
- Add Model, Controller, View (MCV)
- Add board object
- Add bitboard
- Adapt move to bitboard
- Add piece factory  