add_executable(day04
    input.h
    part1.h
    part2.h
    main.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day04 PRIVATE fmt::fmt)
