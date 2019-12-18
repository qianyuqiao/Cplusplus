#include<stdio.h>
#include<time.h>
#include<string.h>
int main()
{
    time_t timep;
    struct tm p;
    struct tm *dt;
    time(&timep);
    dt=localtime(&timep);
    memcpy(&p,dt,sizeof(struct tm));
    printf("%d-%d-%d %d-%d-%d\n", 1900+p.tm_year, 1+p.tm_mon, p.tm_mday, p.tm_hour, p.tm_min, p.tm_sec;
    return 0;
}
