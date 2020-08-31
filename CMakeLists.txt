
cmake_minimum_required(VERSION 3.18.2)  

project(listdir)

set(CMAKE_CXX_STANDARD 11)

IF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
ENDIF()

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "boost_1_74_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "boost_1_74_0/stage/lib")

find_package(Boost)   
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR} )  
	
	add_executable(
	listdir
	listdir.cpp)
	
	target_link_libraries (listdir ${Boost_LIBRARIES})
    
ENDIF()
