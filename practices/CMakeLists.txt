set(PRACTICE_NAME practice0001)
source_group("Shader Files" FILES ${SHADER_PATH})
add_executable(${PRACTICE_NAME} practice0001.cpp ${SHADER_PATH})
target_link_libraries(${PRACTICE_NAME} ${BINARY_FILES})
add_dependencies(${PRACTICE_NAME} GLEW glfw)

