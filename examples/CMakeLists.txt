cmake_minimum_required(VERSION 3.14)

add_executable(InteractiveMathExample
    main.cpp
)

target_link_directories(InteractiveMathExample PRIVATE
	libSimplEx
)
