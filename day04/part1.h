#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <string_view>
#include <vector>

namespace part_one
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

    const auto possible_xmas_count = [&](int row, int col) -> int {
        int xmas_count {};
        if (get_char(row - 1, col - 1) == 'M' && get_char(row - 2, col - 2) == 'A'
            && get_char(row - 3, col - 3) == 'S') {
            xmas_count++;
        }
        if (get_char(row - 1, col) == 'M' && get_char(row - 2, col) == 'A'
            && get_char(row - 3, col) == 'S') {
            xmas_count++;
        }
        if (get_char(row - 1, col + 1) == 'M' && get_char(row - 2, col + 2) == 'A'
            && get_char(row - 3, col + 3) == 'S') {
            xmas_count++;
        }
        if (get_char(row, col - 1) == 'M' && get_char(row, col - 2) == 'A'
            && get_char(row, col - 3) == 'S') {
            xmas_count++;
        }
        if (get_char(row, col + 1) == 'M' && get_char(row, col + 2) == 'A'
            && get_char(row, col + 3) == 'S') {
            xmas_count++;
        }
        if (get_char(row + 1, col - 1) == 'M' && get_char(row + 2, col - 2) == 'A'
            && get_char(row + 3, col - 3) == 'S') {
            xmas_count++;
        }
        if (get_char(row + 1, col) == 'M' && get_char(row + 2, col) == 'A'
            && get_char(row + 3, col) == 'S') {
            xmas_count++;
        }
        if (get_char(row + 1, col + 1) == 'M' && get_char(row + 2, col + 2) == 'A'
            && get_char(row + 3, col + 3) == 'S') {
            xmas_count++;
        }
        return xmas_count;
    };

    int total_xmas_count {};
    for (const auto& [row, line] : lines | std::views::enumerate) {
        // fmt::println("{}", line);
        for (const auto& [col, ch] : line | std::views::enumerate) {
            if (ch == 'X') {
                total_xmas_count += possible_xmas_count(row, col);
            }
        }
    }

    return total_xmas_count;
}

} // namespace part_one
