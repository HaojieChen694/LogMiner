## 基于C++11的文件扫描工具[学习项目]

- 编译项目
```
mkdir -p build
cd build
cmake ..
make
```

- 运行项目
```
./logminer ../data
```

#### 一些名词解释
explicit 是 C++ 关键字，意思是：禁止隐式类型转换，只允许显式调用。
RAII 资源的获取和释放，交给对象生命周期管理。
当一个对象只是装数据时，用 struct 很方便
std::size_t统计数量时优先使用它
#### 每日任务
- Day1
1. 写 FileScanner 类
2. 支持递归扫描
3. 只保留 .txt、.log、.md
4. 先打印出扫描到的文件路径

- Day2
1. 写 TextFile
2. 给定路径，读取文件全部内容
3. 先打印文件内容长度

- Day3
1. 写 TextStats
2. 写 TextAnalyzer
3. 统计每个文件的：行数、单词数、字符数

- Day4
1. 写 StatsReport
2. 让 App 不再自己做总统计
3. 打印汇总结果