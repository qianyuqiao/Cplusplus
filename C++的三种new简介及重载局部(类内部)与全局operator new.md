## 1.概念
### new操作符
```
a = new Class这种
new operator新建一个对象时，操作如下：
1.调用operator new 分配内存
2.调用构造函数生成类对象
3.返回对应类型的指针
```
### operator new
```
原型是 void* operator new(size_t size)
size指定分配内存的大小，函数内部调用malloc分配内存大小，返回指向内存的指针
```
### placement new
```
可以看到，placement的意思是“代替”，即，代替一块指向的用户空间。
```

## 2.用法：
### operator new的用法
1.
```
class A
{
public:
    void * operator new(size_t size)
    {
        cout << "hello, operator new" << endl;
        return ::operator new(size);
    }

};
int main()
{
    A* p = new A();// 此时会调用operator new
    return 0;
}
```
2.
```
class A
{
public:
    void * operator new(size_t size)
    {
        cout << "hello, operator new" << endl;
        return malloc(size);
    }

};
```
### replacement new
```
    char *buf = new char[sizeof(A)+sizeof(int)];// 注意这一行，如果不加sizeof(int)的话会报错
    A* p = new(buf) A;
    p->a = 1;
    cout << (p->a) << endl;
    p->~A();
    return 0;
```
