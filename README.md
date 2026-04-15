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
std::isalnum(c) 是 C++ 库函数，用于判断字符 c 是否是字母或数字。
- 倒排索引
```
正排：一个文件里有什么词
倒排：一个词出现在哪些文件里
```

#### 每日任务
- Day5
1. 写 Tokenizer
2. 输入一段字符串
3. 输出一个 vector<string>
4. 统一转小写 std::tolower
5. 去掉标点干扰

- Day6
1. 掌握unordered_map
2. 为每个文件分配 file_id
3. 记录文件路径
4. 统计每个文件里每个词出现的次数
5. 建立倒排索引