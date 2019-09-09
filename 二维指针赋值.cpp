#include<iostream>
using namespace std;
int **Matrix = NULL;
int main(){
	cout << sizeof(int) << endl;
    cout<<"现在我们将Matrix初始化为3*3的数组,请依次输入元素"<<endl;
    Matrix = new int*[3];
    for(int k=0;k<3;k++) //开辟内存空间
        Matrix[k] = new int[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>Matrix[i][j];
        }
    }
    
	for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "数组指针的地址" << endl;
    
    for (int i = 0; i < 3;i++)
    {
    	cout << Matrix+i << endl;
	}
	
	cout << "数组每个元素的地址" << endl;
	
	for (int i = 0; i < 3;i++)
    {
    	cout << "第" << i << "个数组" << endl; 
    	cout << Matrix[i] << endl;
    	cout << Matrix[i]+1 << endl;  	
    	cout << Matrix[i]+2 << endl; 
	}
    return 0;
}
