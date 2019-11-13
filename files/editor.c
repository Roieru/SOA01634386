#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void replace(char* word, char* pattern, int fd2, int n, char* newword){
            if(strcmp(word, pattern)){
                write(fd2, word, n);
                write(fd2, " ", 1);
            }
            else{
                write(fd2, newword, strlen(newword));
                write(fd2, " ", 1);
            }
}

int main(int argc, char **argv){

    char *pattern = argv[1];
    char *newword = argv[2];
    char *filename = argv[3];
    char c;
    char word[100];

    int n;
    int fd = open(filename, O_RDONLY);
    int fd2 = open("tmp.txt", O_WRONLY|O_CREAT,0666);

    while(read(fd, &c, 1)){
        if(c != ' '){
            word[n++] = c;
        }
        else{
            word[n] = '\0';
            replace(word, pattern, fd2, n, newword);
            n= 0;
        }
    }

    replace(word, newword, fd2, n, filename);
    close(fd);
    close(fd2);
    word[n] = '\0';
    //printf("Última palabra: %s\n",word);
    unlink(filename);
    link("tmp.txt", filename);
    unlink("tmp.txt");
    return 0;

}