cmake_minimum_required(VERSION 3.24)
project(ReglaFalsa)

set(CMAKE_CXX_STANDARD 17)

add_executable(ReglaFalsa main.cpp biseccion.h Expression.h raices.h reglafalsa.h)
