<<<<<<< HEAD
#include <stdio.h>

int main(){
    printf("Hola mundo\n");
=======
#include "./libhello.h"

int main(int argc, char **argv){
    int i = 0;
    for(i = 1; i < argc; i++){
        printHello(argv[i]);
    }
>>>>>>> 68e98ff4e3388bd6b65730dab6d6d3fb4d6a607b
    return 0;
}