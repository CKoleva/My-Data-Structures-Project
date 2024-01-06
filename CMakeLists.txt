cmake_minimum_required(VERSION 3.13.0)

project(My-Data_structures-Project VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTING "Specifies whether to enable unit testing for the project" ON)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

include(CTest)


# Make Catch2 available
if(BUILD_TESTING)

  message(STATUS "Make Catch2 available...")

  if(EXISTS ${CMAKE_SOURCE_DIR}/lib/Catch2)
   
    add_subdirectory(${CMAKE_SOURCE_DIR}/lib/Catch2)
  
  else()
    
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0
        FIND_PACKAGE_ARGS
    )

    FetchContent_MakeAvailable(Catch2)

  endif()


  include(Catch)

  cmake_print_variables(Catch2_DIR)
  cmake_print_variables(catch2_SOURCE_DIR)
  cmake_print_variables(Catch2_SOURCE_DIR)
  cmake_print_variables(CMAKE_MODULE_PATH)

endif()

include_directories("src")
include_directories("include")
include_directories("tests")

# Executable and library targets
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)
# Unit testing
if(BUILD_TESTING)
  add_subdirectory(test)
endif()
