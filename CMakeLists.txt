cmake_minimum_required(VERSION 3.26)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(bayan VERSION ${PROJECT_VESRION})
configure_file(version.h.in version.h) 

find_package( Boost COMPONENTS chrono filesystem program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

include_directories(include)

set(LIB_NAME ${CMAKE_PROJECT_NAME}_lib)
add_library(${LIB_NAME} src/bayan.cpp)
target_link_libraries(${LIB_NAME}  ${Boost_LIBRARIES})

add_executable(bayan src/main.cpp)
set_target_properties(bayan ${LIB_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


target_link_libraries(bayan PRIVATE ${LIB_NAME})

add_definitions(-D_SCL_SECURE_NO_WARNINGS)

install(TARGETS bayan RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)
include (CPack)