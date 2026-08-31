CC := gcc
CFLAGS := -std=c23 -Wall -Werror -Wextra


all: spike

spike: spike_game1.o display_spike.o
	$(CC) $^ -o $@ -lncurses

play: spike
	./spike

clean:
	rm -f spike_game1.o display.o spike

.PHONY: all clean play

c:
	echo 'yo' >c

b: c
	cat c c >b

a: b
	cat b b >a

CAT = cat
toto: toto.src toto.footer
	$(CAT) $^ >$@

	
S = echo
E = grep ' '
tata: toto.src toto.footer
	$(E) toto.src toto.footer
	$(S) toto.src toto.footer