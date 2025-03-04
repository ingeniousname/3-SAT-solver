# CMakeList.txt : CMake project for 3-SAT-solver, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (3-SAT-solver "3-SAT-solver.cpp"  "input.cpp" "verifier.cpp" "output.cpp" "solver.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3-SAT-solver PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

add_custom_command(TARGET 3-SAT-solver POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/input $<TARGET_FILE_DIR:3-SAT-solver>/input
)
