# Dreamcast Emulator Skeleton (C++)

This project is a minimalist skeleton of a Sega Dreamcast emulator written in C++. It simulates CPU cycle execution and basic memory management to illustrate emulator architecture.

## Features

- RAM memory map (8 MB)
- Dummy ROM loader
- CPU cycle loop with HALT and NOP instructions

## Build

- g++ -std=c++17 -o dreamcast_emulator dreamcast_emulator.cpp
- ./dreamcast_emulator
