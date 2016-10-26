#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void randInt(){
  int table[10];

  int i=0;
  int random = open("/dev/random", O_RDONLY);
  for(i; i<10; i++){
    read(random, &table[i], 4);
    printf("index %d: %d\n", i, table[i]);
  }
}

int main(){
  randInt();
  return 0;
}
