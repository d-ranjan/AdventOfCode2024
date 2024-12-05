add_executable(day01
    input.h
    part1.h
    part2.h
    main.cpp
)

if(WIN32)
    target_link_libraries(day01 PRIVATE stdc++exp) # for std::print
endif()

find_package(fmt CONFIG REQUIRED)
target_link_libraries(day01 PRIVATE fmt::fmt)
