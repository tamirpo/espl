# generic rule for compiling C files

CFLAGS=-g -O -Wall

%.o: %.c
	gcc -c $(CFLAGS) -o $@ $<

%: %.o
	gcc $(CFLAGS) -o $@ $<

all: secret-elf-d secret-elf-e

secret-elf-d: secret-elf-b secret-elf-c
		gcc -o secret_elf_d secret_elf_b secret_elf_c 

secret-elf-e: secret-elf-a secret-elf-c
		gcc -o secret_elf_e secret_elf_a secret_elf_c

clean:
	rm -f *.o