add_executable(
    app
)

target_link_libraries(
    app
    PUBLIC
    engine
)

target_sources(
    app
    PUBLIC
    main.cpp
)