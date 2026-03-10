if(NOT fsk4_sources)
    message(STATUS "No C++ sources... skipping python bindings")
    return()
endif()

find_package(pybind11 REQUIRED)

pybind11_add_module(fsk4_python python_bindings.cc)

target_include_directories(
    fsk4_python
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/lib
        ${PYTHON_INCLUDE_DIRS}
)

target_link_libraries(
    fsk4_python
    PRIVATE
        gnuradio-fsk4
        pybind11::module
        ${PYTHON_LIBRARIES}
)

add_custom_command(
    TARGET fsk4_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/python/gnuradio/fsk4
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:fsk4_python> ${CMAKE_BINARY_DIR}/python/gnuradio/fsk4/
)

install(TARGETS fsk4_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/fsk4 COMPONENT pythonapi)
