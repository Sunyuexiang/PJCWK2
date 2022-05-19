cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_C_STANDARD 99)

add_executable(untitled Game.c Users.c User_input.c Interface.c Game.h User_input.h Users.h Interface.h Main.c CreateForm.c CreateForm.h)
