# B-OOP-400-MPL-4-1-arcade-sacha.dessaint

# Arcade Project Documentation

## Introduction

The Arcade project is a program that enables users to switch between different graphics and game libraries. To add new libraries to the system, certain guidelines and conventions must be followed to ensure compatibility and ease of use. This document outlines these guidelines and conventions.
Implementing a New Graphics Library

To implement a new graphics library in the Arcade project, follow these steps:

    Create a new .so in the lib directory and a new folder in the src/Graphics directory.
    Implement the necessary functions and classes for your graphics library using the same function signatures and conventions as the existing libraries.
    Add your library to the Arcade project's build system by modifying the existing Makefile in the core directory.

Once you have implemented your library and added it to the build system, it will be available for use in the Arcade project.

## Here is how you can launch the program:

    Run make re in the terminal to compile the project.
    Run ./arcade lib/arcade_sfml.so to start the program.

Once the program is launched, you can switch to another library by pressing the left and right arrows. You can exit the program by pressing suppr.
You can also write your name by pressing any letter and select the game you want to play by pressing F2 for the Nibbler and F4 to launch the Snake.


## Below is a diagram of the Arcade project's structure:

Diagram :

![beggining of diagram](https://user-images.githubusercontent.com/91196399/229443168-d8d54295-5504-4716-9b7f-80bd69392c71.png)
![Alt Text](https://user-images.githubusercontent.com/91196399/229444082-86dd2f62-77dc-4754-9f62-8e35dc91ba9b.png)
