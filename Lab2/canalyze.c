#include <stdio.h>
#include <string.h>
#include "fgetname.h"
#include "namelist.h"

int compare (const void * a, const void * b)
{
  struct namestat* namestatA = (struct namestat*)a;
  struct namestat* namestatB = (struct namestat*)b;
  return (strcmp(namestatA->name,namestatB->name));
}

int main(int argc, char **argv) {
  
	static char* reservedWords[] = {"auto","else","long","switch","break","enum","register","typedef","case","extern","return","union","char","float",
	"short","unsigned","const","for","signed","void","continue","goto","sizeof","volatile","default","if","static","while","do","int","struct","double","NULL"};
	
	FILE *file;
	file = fopen(argv[1],"r");
	
	if (file != NULL){
	  char name[64];
	  namelist nl = make_namelist();
	  int flag = 1;
	  while(fgetname(name, sizeof(name), file)){
	    int j;
	    flag = 1;
	    for(j = 0; j<sizeof(reservedWords)/sizeof(char*); ++j) {
	      if (strcmp(name,reservedWords[j])==0){
		flag = 0;
		break;
	      }
	    }
	    
	    if (flag==1)
	      add_name(nl, name);
	  }
	  
	  int i=0;
	  qsort (nl->names, nl->size, sizeof(struct namestat), compare);
	 
	  for(i = 0; i!=nl->size; ++i) {
	    printf("%s: ",nl->names[i].name);
	    printf("%d\n",nl->names[i].count);
	  }
	}
	
	
	
	return 0;
} 
