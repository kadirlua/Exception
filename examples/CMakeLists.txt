set(PROJECT_EXAMPLES_DIR ${PROJECT_DIR}/examples)

set(PROJECT_EXAMPLES_DIR
	${PROJECT_GENERAL_DIR}exception.cpp
)

add_executable(ExceptionExample ${PROJECT_EXAMPLES_DIR})

include_directories(${PROJECT_DIR})
target_link_libraries(ExceptionExample PRIVATE BaseException)