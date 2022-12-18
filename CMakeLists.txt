cmake_minimum_required(VERSION 3.0.0)
project(ProjetoLP1 VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ProjetoLP1 facedetect_extra.cpp DetectarRosto.cpp Frutas.cpp Pontuacao.cpp Timer.cpp)

target_include_directories(ProjetoLP1 PUBLIC .)


target_link_libraries(ProjetoLP1 ${OpenCV_LIBS})

target_link_libraries(ProjetoLP1 winmm.lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
