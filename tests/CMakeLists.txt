set(GMOCK_DIR "gmock"
    CACHE PATH "The path to the GoogleMock test framework.")

set(SRC_DIR "../src"
    CACHE PATH "The path to the source files.")

add_subdirectory(${GMOCK_DIR} ${CMAKE_BINARY_DIR}/gmock)

include_directories(SYSTEM 
					${SRC_DIR}
					${GMOCK_DIR}/gtest/include
                    ${GMOCK_DIR}/include)

file(GLOB TESTS
"testCases/*.cpp"
)

add_executable(UnitTests ${SRC} ${TESTS})
target_link_libraries(UnitTests gmock_main src)

add_test(Tests UnitTests)