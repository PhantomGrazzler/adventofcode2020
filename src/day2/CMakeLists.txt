add_executable(day2)

target_sources(day2
    PRIVATE main.cpp
    )

target_link_libraries(day2
    PRIVATE project_warnings
    )

set_property(TARGET day2
    PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:day2>
    )
