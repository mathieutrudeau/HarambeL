cmake_minimum_required(VERSION 3.0.0)
project(HarambeL VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(HarambeL main.cpp 
src/Tokenizer/TokenizerDriver.h 
src/Tokenizer/TokenizerDriver.cpp 
src/Tokenizer/Tokenizer.h 
src/Tokenizer/Tokenizer.cpp 
src/Tokenizer/Token.h 
src/Tokenizer/Token.cpp
src/Logger/Logger.h
src/Logger/Logger.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
