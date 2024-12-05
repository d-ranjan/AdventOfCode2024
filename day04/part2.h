#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <string_view>
#include <vector>

namespace part_two
{

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> int
{
    std::vector<std::string_view> lines {};
    std::ranges::transform(document | std::views::split('\n'), std::back_inserter(lines),
                           [](auto&& line) { return std::string_view {line}; });

    const auto row_count = lines.size();
    const auto col_count = lines.at(0).size();

    const auto get_char = [&](int row, int col) -> char {
        if (row < 0 || col < 0 || row >= row_count || col >= col_count) {
            return 0;
        }
        return lines.at(row).at(col);
    };

    const auto is_xmas = [&](int row, int col) -> bool {
        if (get_char(row - 1, col - 1) == 'M' && get_char(row + 1, col + 1) == 'S'
            && get_char(row - 1, col + 1) == 'M' && get_char(row + 1, col - 1) == 'S') {
            return true;
        }
        if (get_char(row - 1, col - 1) == 'S' && get_char(row + 1, col + 1) == 'M'
            && get_char(row - 1, col + 1) == 'M' && get_char(row + 1, col - 1) == 'S') {
            return true;
        }
        if (get_char(row - 1, col - 1) == 'M' && get_char(row + 1, col + 1) == 'S'
            && get_char(row - 1, col + 1) == 'S' && get_char(row + 1, col - 1) == 'M') {
            return true;
        }
        if (get_char(row - 1, col - 1) == 'S' && get_char(row + 1, col + 1) == 'M'
            && get_char(row - 1, col + 1) == 'S' && get_char(row + 1, col - 1) == 'M') {
            return true;
        }
        return false;
    };

    int total_xmas_count {};
    for (const auto& [row, line] : lines | std::views::enumerate) {
        // fmt::println("{}", line);
        for (const auto& [col, ch] : line | std::views::enumerate) {
            if (ch == 'A' && is_xmas(row, col)) {
                total_xmas_count ++;
            }
        }
    }

    return total_xmas_count;
}

} // namespace part_one
