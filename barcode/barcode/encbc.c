#include <assert.h>
#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv) {
	int line[BC_WIDTH+1]; /* buffer for reading and writing */
  	int i=0;
  	/* encode */	
	for(i=1; i!=argc; ++i) 
	    
		line = bc_char2bits(argv[i],line);
	
	// 
	
}


