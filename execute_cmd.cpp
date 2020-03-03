#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    FILE* fp;
    const char* sysCommand = NULL;
    string cmd = "docker ps -a | grep 'pause' | grep 'sk' | awk {'print $1'} > file1.txt";
    sysCommand = cmd.data();
    if ((fp = popen(sysCommand, "r")) == NULL) {
        cout << "error" << endl;
        return 0;
    }

    pclose(fp);
    return 0;
}
