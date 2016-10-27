#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int randInt(){
	int table;

	int i = 0;
	int random = open("/dev/random", O_RDONLY);
	read(random, &table,4);

	return table;
}


int main(){
	int i=0;
  	int table[10];

  //Populates Array w/ 10 random numbers
	printf("Populate Array w/ 10 random numbers: \n");
	for(i; i<10; i++){
		table[i] = randInt();
		printf("Array[%d]: %d\n",i, table[i]);
	}

  //Writes numbers to file
	printf("\nWriting Numbers to file... \n");
	int file = open("randomDEVised.txt", O_CREAT | O_WRONLY, 0666);
	write(file, table, sizeof(table));
  	close(file);

  //Reading numbers to array
	printf("Reading Numbers from file... \n");
	int new[10];
  	file = open("randomDEVised.txt", O_RDONLY, 066);
	read(file, new, 40);

  	printf("\nTesting if read successfully\n");
  	i=0;
  	for(i; i<10; i++){
      		printf("Array[%d]: %d\n",i, new[i]);
  	}

	return 0;
}
