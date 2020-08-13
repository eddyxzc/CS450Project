
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int  main(int argn,char** argv)
 {

    hasPages(3);
    
     char* arry1=malloc(4096);
     hasPages(3);

      char* c = malloc(5*sizeof(char));

    
     hasPages(3);
     free(arry1);
     free(c);

      c = malloc(4096*8*sizeof(char));

     free(c);
     
     c = malloc(4096*8*sizeof(char));
     hasPages(3);
     char* c2=malloc(4096*8*sizeof(char));
     hasPages(3);
     free(c);

    free(c2);

     //test other pids
     hasPages(1);
     hasPages(2);
     int rt=hasPages(4);
     printf(1,"return of hasPages(4) is %d\n",rt);
    exit();
    return 0;
 }