### 智能指针不能作用于非堆内存
```
string vacation("Havana"); // .text
shared_ptr<string> pvac(&vacation); // 运行时报错
```

### string类的构造函数
```
string():
	string s1;

string(const char*)
	string s0("123");

string(size_t, char)
	string s2(2, '1');

string(const char*, size_t)
	string s3("123", 2);

string(const string&)
	string s4(s2);
  
string(const char*)
	char buf[20] = "12345";
	string s5(buf);

string(const char*, size_t)
	string s6(buf, 3);
  
template<class Iter>  string(Iter begin, Iter end);
	string s7(buf, buf + 3);
	string s8(&buf[0], &buf[3]);
  
string(const string&, size_t pos = 0, size_t n=npos)
	string s9(s4, 0, 2);
```

### string类的运算符重载
+= 被重载
```
string one("1");
one += "Oops"
one += '1'
```
=被重载
```
one = "1";
one = two + three;
```

### string类的输入
c风格的字符串
```
char info[100];
cin >> info; // read a word
cin.getline(info, 100); // read a line, discard \n
cin.get(info, 100);
```
string对象
```
string buf;
cin >> buf; // read a word
getline(cin, buf); // read a line, discard \n 
```
string版本的getline能够自动调整string对象的大小，使得刚好存储输入的字符

### string的比较
```
两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇'\0'为止
s1 = "a";
s2 = "aa";
s1 < s2 // s1的最后是'\0';
```

### 智能指针模板类
普通指针与智能指针的区别，先看看普通指针
```
void demo1
{
    double* pd = new double; // 申请内存
    *pd = 1.0; // 将值分配到动态内存中
    return; // 释放指针pd;
}
```
再看看智能指针
```
#include <memory>
void demo2()
{
    auto_ptr<double> ap(new double); // 申请内存
    *ap = 1.0; // 赋值
    return; // 释放动态内存
}
```
智能指针的模板
```
template<class X> class auto_ptr
{
public:
    explicit auto_ptr(X* p = 0) throw();
}
```
 ### 其他两种智能指针
```
unique_ptr<double> pdu(new double);
shared_ptr<string> pss(new string);
```

### 下面的函数可能导致内存泄漏
```
void remode1(string& str)
{
   string* ps = new string(str);
   if (...) throw exception(); // 如果分配内存出错，会导致刚刚分配的内存泄漏
   str = *ps;
   delete ps;
   return;
}
```

### 利用auto_ptr修改改函数
```
#include <memory>
void remode1(std::string& str)
{
    auto_ptr<std::string> ps (new std::string(str));
    .....
    if (weird_thing()) throw exception(); // 即使离开代码块，内存也会被释放
    str = *ps;
    return;
}
```

### 智能指针类都是有explicit构造函数，不能隐式构造
```
shared_ptr<double> pd;
double* p_reg = new double;
pd = p_reg; // 错误
pd = shared_ptr<double>(p_reg); // OK
shared_ptr<double> pshared = p_reg; // 错误，必须隐式转换
shared_ptr<double> pshare(p_reg); // 正确
```

### 智能指针使用过程中的问题
1.运行时报错
```
auto_ptr<int> ptr(new int(1));
auto_ptr<int> ptr1;
ptr1 = ptr; // 转移了控制权，现在ptr = NULL;
cout << *ptr << endl; // 运行段错误
```
解决方法
```
1.定义赋值运算符，执行深拷贝
2.建立所有权的概念，特定对象只有一个智能指针拥有它，
这样构造函数可以删除它，之后赋值操作符转让所有权（这个也是unique_ptr的策略）
3.引用计数，赋值时，计数加1,过期时计数减1，仅仅当最后一个指针过期时删除堆内存。（shared_ptr）
```

### 编译时报错
```
unique_ptr<string> ptr(new string("123"));
unique_ptr<string> ptr1;
ptr1 = ptr; // 编译报错
```

### unique_ptr优于auto_ptr
```
1.所有权剥夺问题可以在编译过程中报错
auto_ptr<string> p1(new string("auto"));
auto_ptr<string> p2;
p2 = p1; // 运行报错

unique_ptr<string> p1(new string("auto"));
unique_ptr<string> p2;
p2 = p1; // 编译报错

2.unique_ptr支持数组,new[]和delete[]操作
unique_ptr<double[]> pda(new double[5]); // will use delete[]
```

### new[]不能用shared_ptr和auto_ptr

### 多个指针： shared_ptr
### 不需要多个指针： unique_ptr
