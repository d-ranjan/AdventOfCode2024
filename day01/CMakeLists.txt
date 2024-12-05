add_executable(day01
    input.h
    part1.h
    part2.h
    main.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day01 PRIVATE fmt::fmt)
