wordle: src/main.c src/grid.c src/validate.c src/menu.c
	@gcc src/main.c src/grid.c src/validate.c src/menu.c -o bin/wordle -lncurses
	@./bin/wordle



clean:
	@rm bin/wordle
	@clear
