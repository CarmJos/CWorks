# 针对初学者使用CLion的注意事项——C语言

## 修改CMakeList.txt

默认情况下，Clion适用于单独的项目，即一个项目下的文件有且仅有一个main函数。

而针对初学者，我们的作业常常都是单独的一个小程序。如果每个作业都必须新建项目，则太过繁琐且没必要。
因此在使用时，需要修改CMakeList.txt文件，以适应我们的需求。

我们打开根目录下的CMakeList.txt文件，除了第一行、第二行以外，其余内容全部删除，替换为以下内容：

```cmake

# 按照书本要求设定C语言版本
set(CMAKE_C_STANDARD 99)

# 设定构建运行路径，避免污染根目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/.path)

# 遍历项目根目录下所有的 .c 文件，自动添加
file(GLOB_RECURSE files *.c **/*.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ \[${exe}.c\]\ will\ be\ compiled\ to\ \'.runtime/${exe}.exe\')
endforeach ()
```

使用此CMakeList时，若要新建C语言文件，请按照以下步骤：

1. 右键根目录——新建——C/C++源文件
2. 在弹出的对话框中，输入文件名(英文小写及下划线)，后缀为 `.c`，不要勾选“添加到目标”，点击确定。
3. 点击 左上角横线——文件——重新加载CMake项目 。