cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

add_subdirectory(dojo2D)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dojo2D/dojo")

project("dojogame")

include(dojo2D/dojo/AddDojoIncludes.cmake)
include(dojo2D/dojo/MSVCSetup.cmake)
include(dojo2D/dojo/ClangGCCSetup.cmake)

include_directories("dependencies/include")
include_directories("dojo2D/Box2D/liquidfun/Box2D")
include_directories("dojo2D/include/")
include_directories("src")

set(COMPILE_DEFINITIONS_RELEASE "${COMPILE_DEFINITIONS_RELEASE} -DPUBLISH")

file(GLOB common_src    
    "src/*.h"
    "src/*.cpp"
)

set(project_SRC ${common_src} ${platform_src})
add_executable(${PROJECT_NAME} ${project_SRC})

find_package (Threads)
target_link_libraries(${PROJECT_NAME} Dojo2D ${CMAKE_THREAD_LIBS_INIT})

#various fancy VS things
if(MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/DEBUG:FASTLINK")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/LTCG:incremental")

    #setup the working directory
    configure_file(dojo2d/dojo/project.vcxproj.user.in ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.vcxproj.user @ONLY) 
endif()

include(cotire)

set_target_properties(${PROJECT_NAME} PROPERTIES
    COTIRE_PREFIX_HEADER_IGNORE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src;${CMAKE_CURRENT_SOURCE_DIR}/include;"
    COTIRE_ADD_UNITY_BUILD FALSE
)

cotire(${PROJECT_NAME})
