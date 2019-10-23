#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  if(argc != 2||atoi(argv[1])<=0){
    printf(2,"Error. Must include how long the sleep will last and must be at least one second.\n");
    exit();
  }
  sleep(atoi(argv[1])*100);
  exit();
}