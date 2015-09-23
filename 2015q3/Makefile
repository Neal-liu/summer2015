CFLAGS = -Wall -Werror -std=gnu99 -O0 -g -mavx
LDFLAGS = `pkg-config --libs --cflags libpng`
PNGLIBS := $(shell pkg-config libpng --libs)

hw1:
	gcc $(CFLAGS) -o hw1 hw1.c
	./hw1

clean:
	rm hw1
