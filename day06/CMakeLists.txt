add_executable(day06
    input.h
    part1.h
    part2.h
    main.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day06 PRIVATE fmt::fmt)
