INCLUDE(FetchContent)
FETCHCONTENT_DECLARE(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FETCHCONTENT_MAKEAVAILABLE(googletest)
include(${CMAKE_SOURCE_DIR}/test/cmake/YamlFortran_Test_functions.cmake)

set(YamlNode_Test_SOURCES
        test_YamlNode.cc
        fixture/YamlNodeFixture.cc
)
list(TRANSFORM YamlNode_Test_SOURCES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)
set(YamlNode_Test_INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/fixture
)
set(YamlNode_Test_LINK_LIBRARIES
         yaml-cpp::yaml-cpp GTest::gtest_main yaml-fortran_cxx
)
add_cxx_ctest(
        YamlNode_Test
        "${YamlNode_Test_SOURCES}"
        "${YamlNode_Test_INCLUDE_DIRECTORIES}"
        "${YamlNode_Test_LINK_LIBRARIES}"
)




