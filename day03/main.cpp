#include "input.h"
#include "part1.h"
#include "part2.h"

#include <chrono>
#include <print>

static void test_equal(const auto result, const auto exp_value)
{
    if (result != exp_value) {
        std::println("FAIL: result({}) != exp_value({})", result, exp_value);
        return;
    }
    std::println("result = {}", result);
}

int main()
{
    const auto start {std::chrono::steady_clock::now()};

    // test_equal(part_one::get_result(input::test), 161);
    // test_equal(part_one::get_result(input::data), 183669043);
    // test_equal(part_two::get_result(input::test2), 48);
    test_equal(part_two::get_result(input::data), 59097164);

    const auto end {std::chrono::steady_clock::now()};
    const auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::println("elapsed_time: {}", elapsed_time);
}
