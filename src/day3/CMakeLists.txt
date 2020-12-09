add_executable(day3)

target_sources(day3
    PRIVATE main.cpp
    )

target_link_libraries(day3
    PRIVATE project_warnings
    )

set_property(TARGET day3
    PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:day3>
    )
