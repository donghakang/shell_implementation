#include<stdio.h>
#include "util.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(int argc, char* argv[])
{
  int count = 0;
  off_t size;
  if (argc < 2 ){
    printf("Wrong number of argument, expected 1, given %d", argc -1);
    exit(1);
  }
  if(argc == 3){
    struct stat fstat;
    if (stat(argv[2],&fstat) == -1){
      perror("Failed to get file status\n");
      return 1;
    }
    int fsize = fstat.st_size;
    char buffer[fsize];
    int fd = open(argv[2],O_RDONLY);
    if(fd == -1){
      perror("Failed to open file. It does not exist\n");
      return 1;
    }
    while(read(fd,buffer,sizeof(buffer)));
    if(close(fd) == -1){
      perror("Failed to close the file\n");
      return 1;
    }
    FILE *f = fopen(argv[2], "r");
    while(fgets(buffer,sizeof(buffer),f)){
      if(strstr(buffer,argv[1]) != NULL){
        printf("%s",buffer);
        count++;
      }
    }
    fclose(f);
    if(count  == 0){
      printf("There is no %s in the file\n", argv[1]);
      return 1;
    }
  }
  else {
    char buffer[5000];
    while(fgets(buffer,sizeof(buffer),stdin)){
      if(strstr(buffer,argv[1]) != NULL){
        printf("%s",buffer);
      }
    }
  }
  return 0;
}
