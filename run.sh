#!/bin/sh
gcc game.c -o bin/game -lGL -lGLU -lglut && echo "Compiling done, starting..."
bin/game
