#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

/*
This program is used to test the Lseek based file

*/

int main() {

    char buffer[1024];// fill two block with 'A'

    for (int i = 0; i < 1024; i++)
    {
        buffer[i]='A';
    }

    char mbuffer[]={'_','*','*','*','_'};


    //Extent file////////////////////////////////////////////////////////////////////
    int fd_ex = open("lseekextend.txt", O_CREATE|O_EXTENT|O_RDWR);// for extent-based file

    if (fd_ex<0)
    {
       printf(1,"open extent file failed in lseek test\n");
       close(fd_ex);
       exit();
    }

    int wrc=write(fd_ex,buffer,1024);


    if (wrc<0)
    {
       printf(1,"write extent file failed in lseek test\n");
    }

    int lsrc=lseek(fd_ex,5);
    if (lsrc<0)
    {
        printf(1,"lseek in extent file failed in lseek test, return code %d\n",lsrc);
    }
    


    wrc=write(fd_ex,mbuffer,5);
    if (wrc<0)
    {
       printf(1,"write extent file failed in lseek test\n");
    }


    lsrc=lseek(fd_ex,512);
    if (lsrc<0)
    {
        printf(1,"lseek in extent file failed in lseek test, return code %d\n",lsrc);
    }

    wrc=write(fd_ex,mbuffer,5);//////////////////write again
    if (wrc<0)
    {
       printf(1,"write extent file failed in lseek test\n");
    }

    


    // test reading

    char readbuffer[]={'0','0','0','0','0'};

     lsrc=lseek(fd_ex,5);
    if (lsrc<0)
    {
        printf(1,"lseek in extent file failed in lseek test, return code %d\n",lsrc);
    }
    int rrc=read(fd_ex,readbuffer,5);
    //printf(1,"read byte %d %s\n",rrc,readbuffer);
    if (rrc<0)
    {
       printf(1,"read extent file failed in lseek test\n");
    }
    
    for (int j = 0; j < 5; j++)
    {
        if (mbuffer[j]!=readbuffer[j])
    {
        printf(1,"read extent file testing failed, two str are not equal  \n");
        exit();
    }
    }
    
    printf(1,"test lseek reading for extent file finished\n");
    //reading testing succeed

    printf(1,"test lseek error code for extent file\n");
    ////////////////////////////////////test lseek error code now
    ////// -1, offset shoulg bigger than 0
    /////  -2;// file invalid
    ///// -3;//offset not in file
    lsrc=lseek(fd_ex,-1);
    if (lsrc<0)
    {
        printf(1,"lseek in extent file with offset -1, return code %d\n",lsrc);
    }

    lsrc=lseek(7,10);
    if (lsrc<0)
    {
        printf(1,"lseek in extent file with file 7, return code %d\n",lsrc);
    }

    lsrc=lseek(fd_ex,1025);
    if (lsrc<0)
    {
        printf(1,"lseek in extent file with offset 1025, return code %d\n",lsrc);
    }
    printf(1,"test lseek finished for extent file\n");
   

    ///////////////////////normal file/////////////////////////////////
    int fd = open("lseekfile.txt", O_CREATE|O_RDWR);// for normal file

    if (fd<0)
    {
       printf(1,"open normal file failed in lseek test\n");
       close(fd);
       exit();
    }
    
    wrc=write(fd,buffer,1024);// fill two block with 'A'

    if (wrc<0)
    {
       printf(1,"write normal file failed in lseek test\n");
    }

    lsrc=lseek(fd,5);
    if (lsrc<0)
    {
        printf(1,"lseek in normal file failed in lseek test, return code %d\n",lsrc);
    }
    


    wrc=write(fd,mbuffer,5);
    if (wrc<0)
    {
       printf(1,"write normal file failed in lseek test\n");
    }


    lsrc=lseek(fd,512);
    if (lsrc<0)
    {
        printf(1,"lseek in normal file failed in lseek test, return code %d\n",lsrc);
    }
    wrc=write(fd,mbuffer,5);//////////////////write again
    if (wrc<0)
    {
       printf(1,"write normal file failed in lseek test\n");
    }

// test reading



     lsrc=lseek(fd,5);
    if (lsrc<0)
    {
        printf(1,"lseek in normal file failed in lseek test, return code %d\n",lsrc);
    }
     rrc=read(fd,readbuffer,5);
    //printf(1,"read byte %d %s\n",rrc,readbuffer);
    if (rrc<0)
    {
       printf(1,"read normal file failed in lseek test\n");
    }
    
    for (int j = 0; j < 5; j++)
    {
        if (mbuffer[j]!=readbuffer[j])
    {
        printf(1,"read normal file testing failed, two str are not equal  \n");
        exit();
    }
    }
    
    printf(1,"test lseek reading for normal file finished\n");
    //reading testing succeed











    ////////////////test error code


    printf(1,"test lseek error code for normal file\n");
    ////////////////////////////////////test lseek error code now
    ////// -1, offset shoulg bigger than 0
    /////  -2;// file invalid
    ///// -3;//offset not in file
    lsrc=lseek(fd,-1);
    if (lsrc<0)
    {
        printf(1,"lseek in normal file with offset -1, return code %d\n",lsrc);
    }

    lsrc=lseek(7,10);
    if (lsrc<0)
    {
        printf(1,"lseek in normal file with file 7, return code %d\n",lsrc);
    }

    lsrc=lseek(fd,1025);
    if (lsrc<0)
    {
        printf(1,"lseek in normal file with offset 1025, return code %d\n",lsrc);
    }
    printf(1,"test lseek finished for normal file\n");


    close(fd);
    close(fd_ex);
    exit();
    


    return 0;
}