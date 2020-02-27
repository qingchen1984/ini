cmake_minimum_required(VERSION 3.6)
project(ini)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive")

set(CFORMAT_SOURCE_FILES ./src/ini.cpp
                 ./test/test.cpp
    )


set(CPLUSPLUSFORMAT_SOURCE_FILES ./src/IniFile.cpp
        ./test/TestIniFile.cpp
        )

#add_executable(ini ${CFORMAT_SOURCE_FILES})

add_executable(ini ${CPLUSPLUSFORMAT_SOURCE_FILES})