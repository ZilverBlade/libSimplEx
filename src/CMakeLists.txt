cmake_minimum_required(VERSION 3.14)

set(ZB_SIMPLEX_SOURCE_FILES "")
list(APPEND ZB_SIMPLEX_SOURCE_FILES
   "SimplEx.cpp"
)

if (BUILD_SHARED_LIBS)
add_library(libSimplEx SHARED
    ${ZB_SIMPLEX_SOURCE_FILES} 
)
target_compile_definitions(libSimplEx PUBLIC ZB_SIMPLEX_SHARED)
else()
add_library(libSimplEx STATIC
    ${ZB_SIMPLEX_SOURCE_FILES} 
)
endif()

target_include_directories(libSimplEx PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/../include
)