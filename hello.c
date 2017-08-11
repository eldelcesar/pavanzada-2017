#include <stdio.h>

/*
// VERSION 1
int main (){
  printf("Hello World\n");
  return 0;
}*/

// VERSION 2
int main (int argn, char **argv){
  for(int i = 1; i < argn; i++){
    printf("Hello %s\n", argv[i]);
  }
  return 0;
}
