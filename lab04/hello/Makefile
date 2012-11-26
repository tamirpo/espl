%.o: %.asm
	nasm -g -f elf -o $@ $<

.PHONY: clean all

all: main malami

main: main.o
	gcc -c main.c

malami: malami.o
	ld -melf_i386 -g -o $@ $^

clean:
	rm *.o malami
