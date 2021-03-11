#CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 是否使用自己的 Std 库
option (USE_STD
       "Use provided std implementation" ON)

       
# 加入一个配置头文件，用于处理 CMake 对源码的设置，生成一个config.h文件，这个文件由config.h.in产生。
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )


# 是否加入 Submodule库文件作为EXTRA_LIBS, 命名为 MY_LIBS
if (USE_STD)
  include_directories ("${PROJECT_SOURCE_DIR}/submodule")
  add_subdirectory (submodule)
  set (EXTRA_LIBS ${EXTRA_LIBS} Submodule)
endif (USE_STD)


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable (Demo ${DIR_SRCS})

# 添加库文件
target_link_libraries (Demo  ${EXTRA_LIBS})