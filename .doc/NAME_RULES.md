# C语言命名规范——以UNIX风格为例

优秀的C语言代码通常遵循通用的代码规范原则，以确保代码的可读性和一致性。

虽然这些规则不是强制性的，但遵循它们可以大大帮助保持代码的逻辑可读性和一致性，特别是在团队协作或大型项目中。
不同的项目或团队可能有自己的命名约定，所以最重要的是在一个项目或团队内保持一致性。

## 基本规范

1. **避免使用保留字和标准库命名**:
   - 避免使用C语言的关键字（如 `int`, `return`, `struct` 等）作为变量名。
   - 同样，避免使用可能与标准库函数冲突的名称。

2. **使用简洁且具有描述性的名称**:
   - 选择简洁且具有描述性的名称，使其能够清晰地表达变量或函数的用途。例如，使用 `calculate_speed()` 而不是 `cs()`。
   - 避免使用无意义的名称，如 `a`、`qwq` 或 `foo`。
   - 选择单词时，首先要保障“**贴切**”，即词能达意，其次再去考虑长短。
   - 尽量避免使用缩写，除非它们是通用的或广泛使用的。例如，`str` 代表字符串，`len` 代表长度。见 [通用缩写](#通用缩写)。

3. **保持一致性**：在同一项目或团队中保持文件命名的一致性非常重要。个人或团队内部应该商定并遵守统一的命名规范。

> _注1:_ 也有一种命名函数名的风格是 首字母小写,后面单词首字母大写,中间不用连接符, 比如 `getMaxValue()`。
> 而类名单词首字母大写不用分隔符,如 `class MyDateClass`；
> 类的成员数据和方法的首单词首字母小写后面的单词首字母大写 如 `int superValue`。
> 
> JAVA的代码风格就是大致如此。

## 特定情况

### 1. 文件命名

在C语言项目中，文件命名的规范有助于帮助构建项目的整体结构。以下是一些常见的文件命名规范：

1. **使用小写字母**：文件名通常全部使用小写字母，以避免操作系统之间的兼容性问题（特别是在区分大小写的系统中）。
2. **使用下划线分隔**：单词之间使用下划线（_）分隔，以提高可读性。例如：`char_calc.c` 或 `data_processing.h`。
3. **简洁且具描述性**：文件名应简洁且能够清楚地描述文件内容。例如，如果文件包含一个实现链表功能的模块，则可以命名为 `linked_list.c`。
4. **区分头文件和源文件**：
    - 源文件（.c 文件）：包含C语言的实现代码。例如：`main.c`, `score_calc.c`。
    - 头文件（.h 文件）：包含函数声明、宏定义和类型定义等。与源文件相关联，通常名称相似。例如：`utils.h` 用于存放工具方法。
5. **避免使用空格和特殊字符**：避免在文件名中使用空格和特殊字符，如`%`, `&`, `*`等，因为它们可能导致在某些环境或命令行操作中出现问题。
6. **使用有意义的前缀或后缀**：对于大型项目，可以使用前缀或后缀来指示文件属于哪个模块或子系统。例如，使用`gui_button.c` 来表示该文件为图形用户界面模块中的按钮相关代码。
7. **避免过长的文件名**：虽然现代操作系统支持较长的文件名，但过长的文件名可能不便于管理、识别和调用。所以，尽量保持文件名长度合理。

### 2. 变量与常量

局部变量命名应当 **全部使用小写字母，单词之间用下划线分隔** 。
局部变量可以简短，因为它们的作用域有限。例如：

- `int my_variable;`
- `void calculate_total();`

全局变量应该更加谨慎命名，可以使用前缀以避免命名冲突，例如：
- `int g_some_value = 10;` 其中 `g_` 为前缀，代表 _GLOBAL_，即全局。

对于常量，可以使用 `const` 关键字来定义，并采用 **全大写下划线** 风格例如：
- `static const int DENOMINATIONS[] = { 2000, 1000 };` [[实例]](../src/calculator/change_calc.c)

而 `i, j, k, m, n, x, y, z` 等单字母变量普遍被用在索引、循环语句控制、数学函数等处。
这是一种约定俗成的习惯，但是在其他地方使用单字母变量是不被推荐的，且不应当滥用。


### 3. 方法与函数

针对于方法，我们一般采取 “`动词_名词`” 的命名方式，且应当 **全部使用小写字母，单词之间用下划线分隔** ，例如：
- `int get_file();`
- `int calculate_total();`
- `int get_max_value();`
- `int is_valid();`

其中“动词” 通常用于表示方法的操作，例如 `calculate_total()` 计算总数，
“名词” 通常用于表示方法的返回值类型，例如 `get_max_value()` 返回一个最大值。
该部分是可选的，比如 有些方法不需要返回值，或者返回的内容已经隐藏在动词方法名或模块名中。

### 4. 类型与结构体

自定义类型（如结构体和联合体）通常使用**大驼峰式**或**全大写下划线**风格。例如：
- `typedef struct { ... } MyStruct;`
- `typedef struct { ... } MY_STRUCT;`

### 5. 宏变量与枚举

宏常量和枚举通常全部使用大写字母，单词之间用下划线分隔。这样做是为了与普通变量和函数区分开。例如：
- `#define MAX_LENGTH 100`
- `enum { RED, GREEN, BLUE };`

## 常见操作单词

- add/remove
- begin/end
- create/destroy
- insert/delete
- first/size
- get/release
- increment/decrement
- put/get
- add/delete
- lock/unlock
- open/close
- min/max
- old/new
- start/stop
- next/previous
- source/target
- show/hide
- send/receiver
- source/destination
- copy/paste
- up/down


## 通用缩写

这里是一些通用的缩写，选择性使用。

```text
addition —> add
answer —> ans
array —> arr
average—>avg 
argument —> arg
buffer —> buff/buf
clock —> clk
calculate —> calc
column —> col
control —> ctrl
command —> cmd
compare —> cmp
configuration —> config/cfg
count —> cnt
define —> def
delete —> del
destination—>dst/dest
display—> disp
device —> dev
decode —> dec
division —> div
frequency—>freq
error —> err
environment —> env
encode —> enc
hexadecimal —> hex
header —> hdr
index —> idx
image —> img
initialize —> init
increment —> inc
length—>len
make —> mk
maximum —> max
message —> msg
minimum —> min
multiplication—>multi
memory—>mem
middle—>mid
number —> num
option—>opt
parameter —> para
previous —> prev
pointer —> ptr
register —> reg
receiver—>recv
return —> ret
result—>res
source —> src
stack—>stk
string—>str
subtraction—>sub
semaphore —> sem
statistic —> stat
synchronize —> sync
table —>tab
temp —> tmp
temporary—>tmp/temp
timestamp—>ts
value—>val
width—>wid
```