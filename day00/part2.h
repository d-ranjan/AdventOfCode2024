#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <spanstream>
#include <string_view>
#include <vector>

namespace part_two
{

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> int
{
    // Accumulate the values
    return std::ranges::fold_left(document | std::views::split('\n'), 0,
                                  [&](int sum, auto&& line) {
        fmt::println("{}", line);
        return sum;
    });
}
} // namespace part_two
