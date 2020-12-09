add_executable(day1)

target_sources(day1
    PRIVATE main.cpp
    )

target_link_libraries(day1
    PRIVATE project_warnings
    )

set_property(TARGET day1
    PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:day1>
    )

add_custom_command(TARGET day1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/day1_input.txt
    $<TARGET_FILE_DIR:day1>
    )
