1.include头文件在cpp中是按顺序展开的 前面的头文件里面的变量可以给后面的头文件用，比如
a.h:
#include <stdio.h>
typedef int  int1;


b.h:
typedef int int1;


b.c:
#include "a.h"
#include "b.h"
int main()
{
   printf("1\n");
   return 0;
}


此时b.c可以正常编译运行
