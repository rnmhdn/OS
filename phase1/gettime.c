#include <linux/unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
 
int main()
{
  long time;
 
  time = syscall(201);
 int x = time % 1000;
time /= 1000;
int y = time % 60;
time /= 60;
int z = time % 60;
time /= 60;
int t = time % 24;
time /= 24;
  printf("Current jiffies is %d:%d:%d:%d\n", t , z , y ,x );
 
  return 0;
}
