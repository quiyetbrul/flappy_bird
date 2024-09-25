# Flappy Bird

This is a C++ implementation of the classic Flappy Bird game, developed using the SFML (Simple and Fast Multimedia Library) for rendering and game mechanics. The project leverages modern development workflows, including CMake for builds, SonarCloud for code quality, and Itch.io for game deployment.

I also have it in Go [here](https://github.com/quiyetbrul/birdie-go)

## Features

- Classic Flappy Bird gameplay with smooth controls
- Endless scrolling environment with increasing difficulty
- Simple yet polished graphics, using SFML for fast rendering
- Real-time score tracking to keep challenging yourself
- Continuous integration setup to ensure stability across new code changes

## Workflow

- Itch.io Deployment: After each successful merge into the main branch, the game is automatically uploaded to Itch.io.
- CMake: Ensures new code pushes can be compiled and built correctly across different environments.
- SonarCloud: Used to catch code smells and improve overall code quality by detecting potential bugs and issues.

## Prerequisites

- C++ compiler that supports C++17 or higher
- CMake for building the project
- SFML (Simple and Fast Multimedia Library), version 2.5 or higher. You can download SFML from [here](https://www.sfml-dev.org/).

## Installation

- run the `makerun.sh` script to build and run the game
