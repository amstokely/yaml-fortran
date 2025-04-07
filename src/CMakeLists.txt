set(yaml-fortran_cxx_SOURCES yaml_fortran.cc)
list(TRANSFORM yaml-fortran_cxx_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")
set(yaml-fortran_cxx_INCLUDE_DIRECTORIES "include")
list(TRANSFORM yaml-fortran_cxx_INCLUDE_DIRECTORIES PREPEND "${CMAKE_SOURCE_DIR}/")
set(yaml-fortran_cxx_PUBLIC_LINK_LIBRARIES yaml-cpp)

add_library(yaml-fortran_cxx ${yaml-fortran_cxx_SOURCES})
yaml_fortran_cxx_library(yaml-fortran_cxx "${yaml-fortran_cxx_INCLUDE_DIRECTORIES}" "${yaml-fortran_cxx_PUBLIC_LINK_LIBRARIES}")
