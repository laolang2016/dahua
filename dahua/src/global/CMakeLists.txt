# src/global
aux_source_directory(. srcs)

include_directories(${PROJECT_SOURCE_DIR}/include  )

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 之前的添加动态库/静态库的方法
# 缺点：动态库与静态库的名字不能重名
# add_library(global SHARED ${srcs})
 
# 生成动态库目标
add_library(global SHARED ${srcs})
# 生成静态库目标
add_library(global_static STATIC ${srcs})
 
# 指定静态库的输出名称
set_target_properties(global_static PROPERTIES OUTPUT_NAME "global")
# 使动态库和静态库同时存在
set_target_properties(global PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(global_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
 
# 指定动态库版本
# VERSION 动态库版本
# SOVERSION API版本
set_target_properties(global PROPERTIES VERSION 1.0 SOVERSION 1)
