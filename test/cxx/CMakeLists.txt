INCLUDE(FetchContent)
FETCHCONTENT_DECLARE(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FETCHCONTENT_MAKEAVAILABLE(googletest)
include(${CMAKE_SOURCE_DIR}/test/cmake/YamlFortran_Test_functions.cmake)

set(YamlFortran_Test_SOURCES
        test_YamlFortran.cc
        fixture/YamlFortranFixture.cc
)
list(TRANSFORM YamlFortran_Test_SOURCES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)
set(YamlFortran_Test_INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/fixture
)
set(YamlFortran_Test_LINK_LIBRARIES
         yaml-cpp::yaml-cpp GTest::gtest_main yaml-fortran_cxx
)
add_cxx_ctest(
        YamlFortran_Test
        "${YamlFortran_Test_SOURCES}"
        "${YamlFortran_Test_INCLUDE_DIRECTORIES}"
        "${YamlFortran_Test_LINK_LIBRARIES}"
)




