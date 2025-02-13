cmake_minimum_required(VERSION 3.30)
project(cppSQL_exercise)

set(CMAKE_CXX_STANDARD 14)

message("ARCH ${ARCH}")

include_directories(${PROJECT_SOURCE_DIR})

find_package(gflags REQUIRED)
find_package(glog REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(fmt REQUIRED)
find_package(Poco REQUIRED)
find_package(xpack REQUIRED)

set(LIBS m pthread gflags::gflags glog::glog SQLite::SQLite3 fmt::fmt Poco::Poco xpack::xpack)

#cmake依赖
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
include(utility)
include(CPM)

##源文件列表相关
set(filtration_dirlist cmake-build-debug .idea .git conan cmake scripts test data)
SUBDIRLISTINCLUDE(SRC_DIRS ${CMAKE_SOURCE_DIR} 2 ${filtration_dirlist})
message(STATUS "SRC_DIRS:${SRC_DIRS}")
foreach (src_dir ${SRC_DIRS})
    aux_source_directory(${src_dir} SRC_FILES)
endforeach (src_dir)
list(REMOVE_ITEM SRC_FILES ./main.cpp)

add_executable(cppSQL_exercise main.cpp ${SRC_FILES})
target_link_libraries(cppSQL_exercise ${LIBS})
redefine_file_macro(cppSQL_exercise)

add_subdirectory(test)
