# Fetch GoogleTest (if not already included in your project)
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Create test executable
add_executable(
  SATtest
  3SATtest.cc
)

# Link to GTest and your code
target_link_libraries(SATtest
    GTest::gtest_main
    3-SAT-solver
)

# Include the top-level include/ directory
target_include_directories(SATtest PRIVATE
    ${CMAKE_SOURCE_DIR}/3-SAT-solver
)

# Add test to CTest
include(GoogleTest)
gtest_discover_tests(SATtest)
