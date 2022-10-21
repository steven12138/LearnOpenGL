cmake_minimum_required(VERSION 3.22)

project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 20)


# GLFW Configuration
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(external/glfw-3.3.8)
include_directories(external/glfw-3.3.8/include)
LIST(APPEND LIBS glfw ${GLFW_LIBRARIES})

#Glad
set(CODE_SOURCES external/glad/src/glad.c)
include_directories(external/glad/include)
if (NOT WIN32)
    LIST(APPEND LIBS dl)
endif ()

#GLM
add_subdirectory(external/glm)
include_directories(external/glm/glm)
LIST(APPEND LIBS glm)

# stbImage
include_directories(external/stbImage)

# Code Sources
set(CODE_SOURCES ${CODE_SOURCES}
        src/main.cpp
        src/shader/shader.cpp)

# Code Headers
set(CODE_HEADER ${CODE_HEADER}
        src/shader/shader.hpp
        src/texture/texture2D.hpp)

# Static Files
#file(GLOB_RECURSE STATICS static/*)
#
#foreach (FILE ${STATICS})
#    string(REPLACE "/Users/twt/CLionProjects/LearningOpenGL/static/" "" PATH "${FILE}")
#    set(FINAL_PATH ${CMAKE_CURRENT_BINARY_DIR}/static/${PATH})
#    message("Move to Path: " ${FINAL_PATH})
#    configure_file(${FILE} ${FINAL_PATH})
#endforeach ()

set(STATIC_FILE_PATH \"${PROJECT_SOURCE_DIR}\")
add_compile_definitions(STATIC_FILE_PATH=${STATIC_FILE_PATH})

function(printDIR NAME VAR)
    message(\n${NAME}:)
    foreach (ITEM ${VAR})
        message(${ITEM})
    endforeach ()
endfunction()

printDIR(CODE_SOURCES "${CODE_SOURCES}")
printDIR(CODE_SOURCES "${CODE_HEADERS}")

add_executable(${PROJECT_NAME} ${CODE_SOURCES} ${CODE_HEADER})

target_link_libraries(${PROJECT_NAME} ${LIBS})