### 关于迭代器？
```
vector<int> a = {1,2,3,4,5};
vector<int>::iterator it = a.begin();
++it;
```
下面是可以的，
```
vector<int>:: const_interator it = a.begin(); // 常指针
++it;
```

下面的不行，因为相当于一个指针常量
```
const vector<int>::iterator it = a.begin();
++it;  // 报错
```
### const可以用于函数重载
```
class A
{
public:
	void print() const{cout << "const" << endl;}
	void print() { cout << "non-const" << endl; }
};
int main()
{
	A a;
	const A a1;
	a.print();
	a1.print();
	return 0;
}
```
结果:
```
non-const
const
```

### const可以修饰成员函数
这时候成员函数内部不能修改成员变量
```
	string val = "'12345";
	void print() const { val[0] = '0'; }  //报错
```

### const修饰函数的返回值
```
class A
{
public:
	string a = "'12345";
	const char& operator[](size_t pos) const { return a[pos]; } // 把这一行改成char operator[] (size_t pos)同样报错
	char& operator[](size_t pos)  { return a[pos]; }
};
int main()
{
	A a;
	const A a1;
	a[0] = '0';
	a1[0] = '0'; // 报错，表达式必须是可修改的左值
	return 0;
}
```

### mutable:
```
mutable int a = 0;
void print() const { a = 1; }//正确
```
