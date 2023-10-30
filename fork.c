#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main() {
   int id;
   id=fork();
   if(id>0) {
      wait(NULL);
      printf("Parent:");
      printf("%d",getpid());
   }
   else if(id==0) {
      printf("Child\n");
      printf("Child id:%d\nParent id:%d\n",getpid(),getppid());
   }
   else {
      printf("Error\n");
   }
   return 0;
}
