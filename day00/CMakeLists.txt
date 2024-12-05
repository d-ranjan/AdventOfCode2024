add_executable(day00
    input.h
    part1.h
    part2.h
    main.cpp
)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day00 PRIVATE fmt::fmt)
