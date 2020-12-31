add_executable(day5)

target_sources(day5
    PRIVATE main.cpp
    )

target_link_libraries(day5
    PRIVATE project_warnings
    )

set_property(TARGET day5
    PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:day3>
    )
