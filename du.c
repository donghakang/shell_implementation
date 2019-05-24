#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

long int findSize(char *file)//find the size of the file
{
  struct stat s;
  if(stat(file,&s)<0){
    return -1;//get stat for file
  }else{
    return (s.st_size);//return the size of the file
  }
}

long int d_u(char *arg,long int sum){//recursively go through files
  DIR *dir;
  struct dirent *file;

  if (!(dir = opendir(arg)))//if not a directory
    return 0;

  char p[1024];//to store path
  while ((file = readdir(dir)) != NULL) {//go through directory
    snprintf(p, sizeof(p), "%s/%s", arg, file->d_name);//append file name to path
    if (file->d_type == DT_DIR) {//if it is a directory
      if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)//make sure it isnt root or parent
        continue;
      sum+=d_u(p,0);//recurse and add to total
    }
    else{
      long int k=findSize(p);//find size of file
      if(k!=-1)
        sum+=k;//add to the total
    }
  }
  closedir(dir);//close the directory
  //free(p);
  return sum;//return sum
}

int main(int argc , char *argv[])
{
  long int i;
  if (argc > 1) {
    i = d_u(argv[1], 0);
  } else {
    i = d_u(".", 0);
  }
  printf("%ld\n",i);
  return i;
}
