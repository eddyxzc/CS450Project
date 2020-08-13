#include <stdio.h>

#include <stdlib.h>

int main(int argc, char *argv[]) {
    char* arry=malloc(sizeof(char)*1024);

    for (int i = 0; i <1024 ; ++i) {
        arry[i]=i/255;
    }
    //free(arry);

    arry=malloc(sizeof(char)*2048);

    for (int i = 0; i <2048 ; ++i) {
        arry[i]=i/255;
    }
    free(arry);
    printf("exit normally\n");
    return 0;
}
