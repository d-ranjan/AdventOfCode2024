#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <spanstream>
#include <string_view>
#include <vector>

namespace part_one
{

[[nodiscard]] constexpr static auto is_safe(auto&& levels) -> bool
{
    if (not std::ranges::is_sorted(levels)
        && not std::ranges::is_sorted(levels, std::ranges::greater {})) {
        return false;
    }

    constexpr auto calc_diff
        = [](const int first, const int second) { return std::abs(second - first); };
    constexpr auto is_level_safe = [](const int diff) { return (diff >= 1) && (diff <= 3); };

    return std::ranges::all_of(std::views::pairwise_transform(levels, calc_diff), is_level_safe);
}

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> int
{
    return std::ranges::count_if(document | std::views::split('\n'), [&](auto&& line) {
        std::vector<int> levels;

        std::ispanstream stream(line);
        std::ranges::copy(std::views::istream<int>(stream), std::back_inserter(levels));

        return is_safe(levels);
    });
}

} // namespace part_one
