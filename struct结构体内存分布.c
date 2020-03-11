#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{	
	struct s1
	{
		short a;//2 bytes and 2 padding bytes
		int i;//4 bytes
		char c; //1 byte and 3 padding bytes
	}; 
 
	struct s2
	{
		int i;//4 bytes
		char c;//1 byte and 1 padding byte
ã€€		short a;//2 bytes 
	}; 
 
	struct s3
	{
    int i;//4 bytes 
		char c;// 1 byte and 1 padding byte
		short a;//2 bytes
		double d;//8 bytes
	}; 
	cout<<sizeof(s1)<<endl; // 12
	cout<<sizeof(s2)<<endl; // 8
	cout<<sizeof(s3)<<endl;//16
	return 0;
}
/*
s1内存分布
a
11**
i
1111
c
1***
s2内存分布
i
1111
c   a
1*  11
s3内存分布
i        c   a
1111     1*  11
d
11111111
*/
