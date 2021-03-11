# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库,让根目录的CMakeLists.txt使用
add_library (Submodule ${DIR_LIB_SRCS})
