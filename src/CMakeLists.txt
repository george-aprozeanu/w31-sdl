# Add the executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cxx)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)