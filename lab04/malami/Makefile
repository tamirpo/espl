%.o: %.asm
	nasm -g -f elf -o $@ $<

.PHONY: clean all

all: malami main

main: main.o malami.o
	$(CC) $(CFLAGS) -o $@ $^

malami: malami.o
	ld -melf_i386 -g -o $@ $^

main.o: main.c
malami.o: malami.asm

clean:
	rm *.o malami main
