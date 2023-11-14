cmake_minimum_required(VERSION 3.26)
project(CWorks C CXX)

# 使用此CMakeList时，若要新建C语言文件，请按照以下步骤：
# 1. 右键根目录——新建——C/C++源文件
# 2. 在弹出的对话框中，输入文件名(英文小写及下划线)，后缀为 ".c"，不要勾选“添加到目标”，点击确定。
# 3. 点击 左上角横线——文件——重新加载CMake项目 。

# 按照书本要求设定C语言和C++版本
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

# 设定构建运行路径，避免污染根目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/.path)

# 遍历项目根目录下所有的 .c 文件，自动添加
file(GLOB_RECURSE files *.c **/*.c *.cpp **/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ \[${exe}.c\]\ will\ be\ compiled\ to\ \'.runtime/${exe}.exe\')
endforeach ()