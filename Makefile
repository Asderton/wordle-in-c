prueba: src/prueba.c src/grid.c
	@gcc src/prueba.c src/grid.c -o bin/prueba
	@./bin/prueba


grid: src/grid.c 
	@gcc  src/grid.c -o bin/grid -lncurses
	@./bin/grid



clean:
	@if [ $(shell find ./bin -name prueba) ]; then rm ./bin/prueba; else echo "No hay archivo"; fi
