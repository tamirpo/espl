%.o: %.c
	gcc -c -o $@ $<
 
all: canalyze

canalyze: canalyze.o fgetname.o namelist.o
	cc -o $@ $^

fgetname.o: fgetname.c fgetname.h
namelist.o: namelist.c namelist.h
canalyze.o: canalyze.c fgetname.h

clean:
	rm -f *.o