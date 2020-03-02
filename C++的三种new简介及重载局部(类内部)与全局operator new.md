参考文档：[C++的三种new简介及重载局部（类内部）与全局operator new](https://blog.csdn.net/qq_29227939/article/details/51638241)
[深入new/delete：Operator new的全局重载](https://www.cnblogs.com/dragon2012/p/3571838.html)
## 1.概念
### new操作符
```
a = new Class这种
new operator新建一个对象时，操作如下：
1.调用operator new 分配内存
2.调用构造函数生成类对象
3.返回对应类型的指针
```
### operator new是一个库函数
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
3. 可重载性？
operator new既可以被全局重载也可以被局部重载,有以下几点要求
```
1.void* operator new(size_t size, 后面随便啦)第一个参数必须是size_t
2.返回类型必须是void*
```
placement new只能被局部重载，比如使用如下的重载形式
```
void *operator new(std::size_t count, void *ptr) throw();  //placement 版本
如果replacement重载，必须返回一个void*，<br>
这个地址是执行构造函数后新对象存放的地址，如
void* operator new(size_t size, void* p)
{
    cout << "replacement new" << endl;
    return p;
}
可以检测这个时候新对象覆盖在了原来的地址上：
    void* buf = malloc(sizeof(A)+sizeof(int));
    cout << "addr of buf " << buf << endl;
    A* p = new(buf) A;
    cout << "addr of p " << p << endl;
    p->~A();
    free(buf);
结果：
addr of buf 0xaf0030
addr of p 0xaf0030
当然，很有意思的一点是，如果重载replacement new后的返回的地址不是p,那么对象会新建在这个新地址上
void* operator new(size_t size, void* p)
{
    cout << "replacement new" << endl;
    return malloc(size);
}
结果：
addr of buf 0x195f030
addr of p 0x195f050//对象新建在新地址上
```
4.使用replacement new时不能使用delete,否则会直接释放这块内存
```
    A *a = new A;
    a->c = 'x';
    A *p = new(a) A;
    cout << (p->c) << endl;
    delete(p);
    cout <<(p->c) << endl;
    return 0;
```
结果：
```
x


```
内存被清空了。。。
5.C++11的新特性allocator也能实现开辟内存和调用构造函数的分离。
