add_executable(day07
    input.h
    part1.h
    part2.h
    main.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day07 PRIVATE fmt::fmt)
