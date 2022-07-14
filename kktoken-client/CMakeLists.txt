target_sources(run-client
    PRIVATE
    core.cpp)

add_subdirectory(data-objects)
add_subdirectory(networking)