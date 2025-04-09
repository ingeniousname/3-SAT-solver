# CMakeList.txt : CMake project for 3-SAT-solver, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (3-SAT-solver STATIC  "input.cpp" "verifier.cpp" "output.cpp" "solver.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3-SAT-solver PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(3-SAT-solver PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/3-SAT-solver
)

# TODO: Add tests and install targets if needed.

