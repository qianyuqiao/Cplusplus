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
