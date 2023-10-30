#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
char *args[]={"./filesecond",NULL};
execvp(args[0],args);
printf("Empty");
return 0;
}
