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

### 类型转换函数
```
class Value
{
public:
	Value(){}
	explicit Value(Q & q){}
};
class Q
{
public:
	int val;
	operator Value()
	{
		Value val;
		cout << "??" << endl;
 		return val;
	}
};
int main(void)
{
	Q q;
	Value v = q;
	return 0;
}
```
Value v = q这一句既可以理解为参数是q的转换构造函数，也可以理解为把q转化为Value的类型转换函数<br>
所以需要显式声明

### 隐式类型转换规则
!(image)[https://github.com/qianyuqiao/Cplusplus/blob/master/img/leixing.png]
```
	short s = 'a';
	unsigned int ui = 1000;
	int i = -2000;
	double d = i;

	//自己先想一下输出结果，会是什么
	cout << "d = " << d << endl; 
	cout << "ui + i = " << ui + i << endl;
	cout << "sizeof(s + 'b') = " << sizeof(s + 'b') << endl;
```
结果
```
d = -2000
ui + i = 4294966296
sizeof(s + 'b') = 4 //扩展位数。。。
```

