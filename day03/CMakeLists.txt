add_executable(day03
    input.h
    part1.h
    part2.h
    main.cpp
)

if(WIN32)
    target_link_libraries(day03 PRIVATE stdc++exp) # for std::print
endif()

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day03 PRIVATE fmt::fmt)
