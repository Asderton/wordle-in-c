wordle: src/wordle.c src/grid.c src/validate.c
	@gcc src/wordle.c src/grid.c src/validate.c -o bin/wordle -lncurses
	@./bin/wordle



clean:
	@rm bin/wordle
	@clear
