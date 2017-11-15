#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long double before[4], after[4], used_clock;
    FILE *fp;
    char dump[50];//allocate memory
    fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&before[0],&before[1],&before[2],&before[3]);//read the first 4 numbers which are user, nice, system, and idle clocks since boot
    fclose(fp);
    sleep(1);//pass some time to see how many clocks are used during this time.
    fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&after[0],&after[1],&after[2],&after[3]);//read the numbers again to compare
    fclose(fp);
    used_clock = ((before[0]+before[1]+before[2]) - (after[0]+after[1]+after[2])) / ((before[0]+before[1]+before[2]+before[3]) - (after[0]+after[1]+after[2]+after[3]));//the fraction of clocks cpu was actually busy in.
    printf("The current CPU usage is : %Lf\n", used_clock);
    return(0);
}
