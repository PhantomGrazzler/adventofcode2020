add_executable(day4)

target_sources(day4
    PRIVATE main.cpp
    )

target_link_libraries(day4
    PRIVATE project_warnings
    )

set_property(TARGET day4
    PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:day3>
    )
