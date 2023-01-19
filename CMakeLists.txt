cmake_minimum_required(VERSION 3.25)

project(LeetCode
	VERSION 1.0
	LANGUAGES CXX
	)

add_executable(problem
	string-to-integer.cpp
	)

set_property(TARGET problem PROPERTY CXX_STANDARD 17)
