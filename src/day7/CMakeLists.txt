add_executable(day7)

target_sources(day7
    PRIVATE main.cpp
    )

target_link_libraries(day7
    PRIVATE project_warnings
    )

set_property(TARGET day7
    PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:day7>
    )
