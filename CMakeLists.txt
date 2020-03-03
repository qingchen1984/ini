cmake_minimum_required(VERSION 3.6)
project(ini)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive")



option(GS3101 "Build self test support" TRUE)
option(HG6201M "Build self test support" FALSE)

set(CFORMAT_SOURCE_FILES ./src/ini.cpp
        ./test/test.cpp
        )


set(CPLUSPLUSFORMAT_SOURCE_FILES ./src/IniFile.cpp
        ./test/TestIniFile.cpp
        )

#add_executable(ini ${CFORMAT_SOURCE_FILES})

#add_executable(ini ${CPLUSPLUSFORMAT_SOURCE_FILES})


if(GS3101)
    SET(CMAKE_C_COMPILER /usr/bin/mips-linux-gnu-gcc)
    SET(CMAKE_CXX_COMPILER /usr/bin/mips-linux-gnu-g++)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    SET(CMAKE_INSTALL_RPATH "/usr/lib/gcc-cross/mips-linux-gnu/5")
    add_executable(ini ${CPLUSPLUSFORMAT_SOURCE_FILES})
    include_directories("/usr/mips-linux-gnu/include")
    link_directories("/usr/lib/gcc-cross/mips-linux-gnu/5")
    TARGET_LINK_LIBRARIES(ini pthread /usr/lib/gcc-cross/mips-linux-gnu/5/libcurl.so.4)
elseif(HG6201M)
    SET(CMAKE_C_COMPILER /usr/bin/mips-linux-gnu-gcc)
    SET(CMAKE_CXX_COMPILER /usr/bin/mips-linux-gnu-g++)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    SET(CMAKE_INSTALL_RPATH "/usr/lib/gcc-cross/mips-linux-gnu/5")
    add_executable(ini ${CPLUSPLUSFORMAT_SOURCE_FILES})
    include_directories("/usr/mips-linux-gnu/include")
    link_directories("/usr/lib/gcc-cross/mips-linux-gnu/5")
    TARGET_LINK_LIBRARIES(ini pthread /usr/lib/gcc-cross/mips-linux-gnu/5/libcurl.so.4)
else()
    TARGET_LINK_LIBRARIES(ini pthread curl)
    add_executable(ini ${CPLUSPLUSFORMAT_SOURCE_FILES})
endif()


INSTALL(TARGETS ini RUNTIME DESTINATION bin)
