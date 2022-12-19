add_executable(day6)

target_sources(day6
    PRIVATE main.cpp
    )

target_link_libraries(day6
    PRIVATE project_warnings
    )

set_property(TARGET day6
    PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:day6>
    )
