brick: brick.c
	gcc brick.c -o brick `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`

run: brick
	./brick
