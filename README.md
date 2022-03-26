# 10x12chess

A mailbox chess engine written in c

![10x12chess preview](10x12chess-preview.png)

## Description

a chess engine with the [10x12 board representation](https://www.chessprogramming.org/10x12_Board) written in c with a raylib gui

## Getting Started

### Dependencies
  
* Linux or Windows 10 (for now not tested)
* gcc and cmake
* [raylib](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)

### compiling

* for linux:

    open terminal in the project folder and type:

    ``` bash
    mkdir build
    cd build
    cmake ..
    make
    ```
* for windows:
    open terminal in the project folder and type:

    ``` bash
    mkdir build
    cd build
    cmake ..
    ```
    (method i found, probably wrong)
    * open the project folder in **visual studio**
    * compile

### Executing program

* for linux:
    * got in the project folder
    * got in the `/build` folder
    * run `./10x12chess` in the terminal or double click with the mouse

* for windows:
    * executable is in `/out/build/`
    * create a folder 
    * put the executable like this:
        
        (this is to put the image in the correct path [`"../assets/Chess_Pieces_Sprite.png"`])
        ```
            folder
            ├───assets
            │       Chess_Pieces_Sprite.png
            │
            └───bin
                    10x12chess.exe
        ```
    *now go to `bin/` and run `10x12chess.exe`

## Help

sas

## Authors

Fabio Murer  

## Version History

* 0.0
    * work in progress


## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007 License - see the LICENSE.md file for details
