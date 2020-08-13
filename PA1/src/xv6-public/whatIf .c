#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"



#define BUFFER_LEN 18


int whatIfImp(int readfile, int writefile,int rc);

int main(int argc, char* argv[]) {



    char *filename;
    int fr;// reading file
    if (argc == 1) {
        fr = 0;// standard input
    } else {
        filename = argv[1];
        fr = open(filename, O_RDONLY);
        if (fr == -1)
            printf(1,"open reading file failed\n");

    }


    int rc = fork();
    if (rc < 0) {
        // fork failed
        printf(1,"fork failed\n");
        exit();
    }

    int cfw,pfw;
    if (rc == 0) {
        // child (new process)
        printf(1,"child process start(pid:%d)\n", (int) getpid());
        char nameFWriteBackC[] = "child.txt";
         cfw = open(nameFWriteBackC, O_RDWR | O_CREATE );
        if (cfw == -1)
            printf(1,"creat write back file failed\n");
        whatIfImp(fr,cfw,rc);
        close(cfw);

    } else {
        // parent goes down this path (main)
        printf(1,"parent of %d (pid:%d)\n", rc, (int) getpid());


        char nameFWriteBackP[] = "parent.txt";
         pfw = open(nameFWriteBackP, O_RDWR | O_CREATE );
        if (pfw == -1)
            printf(1,"creat write back file failed\n");



        //Write1Line(fw,r_buffer,0,line_length);
        whatIfImp(fr,pfw,rc);
         close(pfw);
         wait();
         close(fr);
    }



        return 0;

}

int whatIfImp(int readfile, int writefile,int rc) {

    
        char buffer[BUFFER_LEN];
        int RTread, RTwrite;
        for (;;) {
            RTread = read(readfile, buffer, BUFFER_LEN);
            if (RTread == 0) {//reach the end of the file
                break;
            } else if (RTread == -1) {
                printf(1,"read file failed\n");
                break;
            } else {
                RTwrite = write(writefile, buffer, RTread);
                if (RTwrite == -1)
                    return -1;
            }
        }
    
    return 0;

}