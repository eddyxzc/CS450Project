#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int  main(int argn,char** argv)
 {

    
    //printf(1,"location of heap : %p\n", malloc(100e6));
     uint x = 3;  
     uint x2 = 3;
     printf(1,"location of main function\n");
     myV2p((int)main,0);
     

     printf(1,"location of stack var x:\n");
     myV2p((int)&x,1);

     printf(1,"location of stack var x2:\n");
     myV2p((int)&x2,1);
     
     int* arry1=(int*)malloc(2000*sizeof(int));
     printf(1,"location of heap var arry1[0]\n");
     myV2p((int)arry1,0);

     printf(1,"location of heap var arry1[1]\n");
     myV2p((int)arry1+1,0);

     printf(1,"location of heap var arry1[1999]\n");
     myV2p((int)arry1+1999,0);

     char* c = malloc(5*sizeof(char));

     printf(1,"location of heap var c[0]\n");
     myV2p((int)c,0);

     printf(1,"location of heap var c[4]\n");
     myV2p((int)c+4,0);

     printf(1,"location of stack var &c\n");
     myV2p((int)&c,0);
     
     free(arry1);
     free(c);

     c = malloc(10*sizeof(char));

     printf(1,"location of heap var c[0]\n");
     myV2p((int)c,0);

     printf(1,"location of heap var c[4]\n");
     myV2p((int)c+4,0);



     int x3=0;
     printf(1,"location of stack var x3:\n");
     myV2p((int)&x3,1);

     printf(1,"location of kernal address 0x80000001:\n");
     myV2p(0x80000001,0);//kernel address
     




     //test error code
     myV2p(0x7FFFFFFF,0);// invaild address, this address is not allocated,
     myV2p((int)&x2,3);// wrong operation input
     
     
    exit();
    return x;
 }