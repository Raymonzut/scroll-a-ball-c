all: clean
	gcc game.c -o game -lGL -lGLU -lglut && echo "Compiling done, starting..."
clean:
	rm -f game
