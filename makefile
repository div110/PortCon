all:
	gcc portcon.c -o bin/portcon
clean:
	rm bin/portcon
debug: 
	gcc portcon.c -g -o bin/portcon
