## 转换构造函数
定义
```
（1）首先是一个类的构造函数
（2）有且仅有一个参数
（3）参数类型是基本类型或其他类类型 
```
用法
```
class T
{
public:
    int val;
    T(int a) {val = a} // 转换构造函数
    T operator +(const T & p)
    {
        T t(val+p.val);
        return t;
    }
    void show()
    {
    cout << val << endl;
    }
};
```
显式声明：
```
class Q
{
public:
	int val;
	explicit Q(int a) {
		val = a;
	}
};
int main(void)
{
	Q q = 1;//报错
```

