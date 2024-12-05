add_executable(day05
    input.h
    part1.h
    part2.h
    main.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day05 PRIVATE fmt::fmt)
