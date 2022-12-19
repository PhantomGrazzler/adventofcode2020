add_executable(day8)

target_sources(day8
    PRIVATE main.cpp
    )

target_link_libraries(day8
    PRIVATE project_warnings
    )

set_property(TARGET day8
    PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:day8>
    )

add_custom_command(TARGET day8 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/day8_input.txt
    $<TARGET_FILE_DIR:day8>
    )
