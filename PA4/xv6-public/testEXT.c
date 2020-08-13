#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"


int filedump(int fd){

    printf(1,"\nFile dump using fstat with fd=%d\n",fd);
 struct stat extFileInfo;
  int rc = fstat(fd, &extFileInfo);
  if (rc != 0)
  {
    printf(2,"fstat error, retruned %d",rc);
    return rc;
  }

  printf(1, "File size %d bytes\n", extFileInfo.size);
  int i = 0;
  uint tot_blocks = 0;
  while (extFileInfo.extents[i].length){
    tot_blocks += extFileInfo.extents[i].length;
    printf(1,"Extent start:%d. Extent Length:%d\n", extFileInfo.extents[i].address, extFileInfo.extents[i].length);
    i++;
    if (i >= 12)
      break;
  }

  if (tot_blocks*512 != extFileInfo.size){
    printf(2, "Something wrong, total blocks don't match size.!!!");
  }
  return  rc;
}

/*
This program is used to test the extent based file

*/

 int main() {


  char buffer[1024];//  two blocks data with 'A'

    for (int i = 0; i < 1024; i++)
    {
        buffer[i]='A';
    }

  int exfd = open("extentfile8k.txt", O_CREATE|O_EXTENT|O_RDWR);
  if (exfd <= 0){
    printf(1, "File Extentfile8k.txt created failed return %d\n",exfd);
    exit();
  }
  
  int fd = open("normalfile.txt", O_CREATE|O_RDWR);
  
  if (fd <= 0){
    printf(1, "File normalfile.txt open failed\n");
    exit();
  }

 int size =0;
for (int i = 0; i < 80; i++){
       size = write(exfd, buffer, 1024);

      if (size < 1024)
      {
        printf(2,"Write failed. Return code %d\n", size);
        exit();
      }
      if (i==40)
      {
         int rc;
         if ((rc = write(fd, buffer, 1024)) != 1024){
          printf(1, "Normal File Write failed. Return code %d\n", rc);
          exit();
           } 
           filedump(exfd);
      }
      if (i==50)
      {
         int rc;
         if ((rc = write(fd, buffer, 1024)) != 1024){
          printf(1, "Normal File Write failed. Return code %d\n", rc);
          exit();
           } 
           filedump(exfd);
      }
      if (i==72)
      {
         int rc;
         if ((rc = write(fd, buffer, 1024)) != 1024){
          printf(1, "Normal File Write failed. Return code %d\n", rc);
          exit();
           } 
           filedump(exfd);
      }
      if (i==75)
      {
         int rc;
         if ((rc = write(fd, buffer, 1024)) != 1024){
          printf(1, "Normal File Write failed. Return code %d\n", rc);
          exit();
           } 
           filedump(exfd);
      }

  }
  filedump(exfd);
           
    close(fd);
    close(exfd);



///////////////test reading extent file//////////////////////
printf(1,"\nTesting  reading extent file \n");

exfd = open("extentfile8k.txt", O_EXTENT|O_RDWR);
  if (exfd <= 0){
    printf(1, "File Extentfile8k.txt opened failed return %d\n",exfd);
    exit();
  }
char readbuffer[1024];
readbuffer[0]='0';
for (int i = 0; i < 80; i++)
{
    size = read(exfd, readbuffer, 1024);

      if (size < 1024)
      {
        printf(2,"Read failed. Return code %d\n", size);
        exit();
      }


     for (int j = 0; j < 1024; j++)
     {
         if (readbuffer[j]!='A')
         {
             printf(1,"Read extent failed with read %d and buffer %d\n",i,j);
             exit();
             
         }
         
     } 
}

printf(1,"Reopen and Reading extent file succeed\n");

close(exfd);

//////////////////////////////////////

    exit();
    return 0;
}