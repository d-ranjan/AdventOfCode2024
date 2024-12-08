add_executable(day08
    input.h
    part1.h
    part2.h
    main.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day08 PRIVATE fmt::fmt)
