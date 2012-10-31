#include <stdio.h>
 
/* Print a random line from the FILE on the standard output. */
int main(int argc, char **argv) {
  FILE 	*file;
  int lineCount = 0;
  int randomLineNumber = 0;
  char* randomLine;
  char buf[5000];
  file = fopen(argv[1],"r");
  if (file != NULL){
    //printf("%s",fgets(buf, 5000, file));

    while((fgets(buf, 120, file)) != 0) {
      lineCount++;
    }
    rewind(file);
    srand (time(NULL));
    randomLineNumber = rand()%(lineCount-1);

    int i;
    for (i=0;i<randomLineNumber;i++){
       fgets(buf,120,file);
    }
    
    printf("%d:  ",randomLineNumber);
    printf("%s\n",buf);
    
    fclose(file);
  }
  else{
    printf("%s","Error Opening the specified file.");
  }
  return 0;
} 
