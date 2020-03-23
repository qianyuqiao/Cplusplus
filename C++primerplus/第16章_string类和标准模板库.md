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
```

```
