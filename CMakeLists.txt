project( Progetto_finale )
 
cmake_minimum_required( VERSION 2.8)
cmake_policy( SET CMP0015 NEW )

SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set( SRCS src/project_app.cpp src/get_line.cpp src/pgm_file.cpp src/tools.cpp src/cell.cpp src/list.cpp)

include_directories( include )

add_executable ( Progetto_finale ${SRCS} )
set_target_properties (Progetto_finale PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
