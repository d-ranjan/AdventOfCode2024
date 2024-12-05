add_executable(day03
    input.h
    part1.h
    part2.h
    main.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day03 PRIVATE fmt::fmt)
