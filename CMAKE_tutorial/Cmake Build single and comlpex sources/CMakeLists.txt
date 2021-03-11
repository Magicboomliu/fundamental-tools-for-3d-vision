cmake_minimum_required( VERSION 2.8)

project(Demo1)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 submodule 子目录
add_subdirectory(submodule)

# 确定要执行的部分
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo Submodule)
