#Arcade Project Documentation

##Introduction

The Arcade project is a program that enables users to switch between different graphics and game libraries. To add new libraries to the system, certain guidelines and conventions must be followed to ensure compatibility and ease of use. This document outlines these guidelines and conventions.
Implementing a New Graphics Library

To implement a new graphics library in the Arcade project, follow these steps:

    Create a new .so in the lib directory and a new folder in the src/Graphics directory.
    Implement the necessary functions and classes for your graphics library using the same function signatures and conventions as the existing libraries.
    Add your library to the Arcade project's build system by modifying the existing Makefile in the core directory.

Once you have implemented your library and added it to the build system, it will be available for use in the Arcade project.

#Here is how you can launch the program:

    Run make re in the terminal to compile the project.
    Run ./arcade lib/arcade_sfml.so to start the program.

Once the program is launched, you can switch to another library by pressing the left and right arrows. You can exit the program by pressing suppr.
You can also write your name by pressing any letter and select the game you want to play by pressing F2 for Pac-Man and F4 to launch the snake.


#Below is a diagram of the Arcade project's structure:

Diagram :


+-----------------------+          +-----------------------+
|        Main           |          |      Graphics         |
|-----------------------|          |-----------------------|
|                       |          | + Graphics()           |
| + startGameLoop()     |          | + ~Graphics()          |
| + switchLibrary()     |          | + init()               |
|                       |          | + displayWindow()      |
|                       |          | + drawBackground()     |
+-----------------------+          | + drawEntities()       |
                                   | + refreshWindow()      |
                                   | + closeWindow()        |
                                   +-----------------------+

+-----------------------+          +-----------------------+
|       GameFactory     |          |         Games         |
|-----------------------|          |-----------------------|
|                       |          | + Game()               |
| + createGame()        |          | + ~Game()              |
|                       |          | + play()               |
+-----------------------+          +-----------------------+

+-----------------------+          +-----------------------+
|       Game            |          |      Core             |
|-----------------------|          |-----------------------|
|                       |          | + AEntity()            |
| + play()              |          | + ~AEntity()           |
| + handleEvents()      |          | + setPos()             |
| + update()            |          | + getPos()             |
| + draw()              |          +-----------------------|
|                       |
+-----------------------+

+-----------------------+          +-----------------------+
|       Home            |          |      MyDlLib          |
|-----------------------|          |-----------------------|
|                       |          | + MyDlLib()            |
| + play()              |          | + ~MyDlLib()           |
| + handleEvents()      |          | + openLib()            |
| + update()            |          | + closeLib()           |
| + draw()              |          | + getFunction()        |
|                       |          +-----------------------|
+-----------------------+

+-----------------------+          +-----------------------+
|       Snake           |          |       Ncurses         |
|-----------------------|          |-----------------------|
|                       |          | + Ncurses()            |
| + play()              |          | + ~Ncurses()           |
| + handleEvents()      |          | + init()               |
| + update()            |          |                        |
| + draw()              |          +-----------------------|
|                       |
+-----------------------+

+-----------------------+          +-----------------------+
|       Nibbler         |          |         Sdl2          |
|-----------------------|          |-----------------------|
|                       |          | + Sdl2()               |
| + play()              |          | + ~Sdl2()              |
| + handleEvents()      |          | + init()               |
| + update()            |          +------------------------+
| + draw()              |
+-----------------------+

+-----------------------+          +-----------------------+
|     Scoreboard        |          |         Sfml          |
|-----------------------|          |-----------------------|
|                       |          | + Sfml()               |
|-----------------------|          | + ~Sfml()              |
| + addScore()          |          | + init()               |
| + displayScores()     |          +------------------------+
+-----------------------+
