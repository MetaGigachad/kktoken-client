target_sources(client
    PRIVATE
    main.cpp)

add_subdirectory(core)
add_subdirectory(structs)
add_subdirectory(communication)
add_subdirectory(interface)
#add_subdirectory(utils) unused now