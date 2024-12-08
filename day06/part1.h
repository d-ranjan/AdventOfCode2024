#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace part_one
{

enum class direction : char
{
    upward    = '^',
    downward  = 'v',
    leftward  = '<',
    rightward = '>'
};

struct position
{
    int       row;
    int       col;
    direction dir;
    char      ch;

    bool operator==(const position& other) const{
        return (row == other.row) && (col == other.col);
    };

    void print() { fmt::println("{}[{},{}]", std::to_underlying(dir), row, col); }
};

struct position_hash
{
    inline std::size_t operator()(const position& pos) const { return (pos.row) ^ (pos.col << 1); }
};

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> int

{
    std::vector<std::string_view> lines {};
    std::ranges::transform(document | std::views::split('\n'), std::back_inserter(lines),
                           [](auto&& line) { return std::string_view {line}; });
    const auto row_count = lines.size();
    const auto col_count = lines.at(0).size();

    const auto index     = document.find('^');
    const int  start_row = index / (row_count + 1);
    const int  start_col = index % (col_count + 1);

    const auto get_char = [&](int row, int col) -> char {
        if (row < 0 || col < 0 || row >= row_count || col >= col_count) {
            return 0;
        }
        return lines.at(row).at(col);
    };

    const auto get_next_position = [&](const position pos) -> position {
        auto next_pos = pos;
        switch (pos.dir) {
            case direction::upward: next_pos.row--; break;
            case direction::downward: next_pos.row++; break;
            case direction::leftward: next_pos.col--; break;
            case direction::rightward: next_pos.col++; break;
        }

        if (next_pos.ch = get_char(next_pos.row, next_pos.col); next_pos.ch != '#') {
            return next_pos;
        }

        switch (pos.dir) {
            case direction::upward:
                return position {pos.row, pos.col + 1, direction::rightward,
                                 get_char(pos.row, pos.col + 1)};
            case direction::downward:
                return position {pos.row, pos.col - 1, direction::leftward,
                                 get_char(pos.row, pos.col - 1)};
            case direction::leftward:
                return position {pos.row - 1, pos.col, direction::upward,
                                 get_char(pos.row - 1, pos.col)};
            case direction::rightward:
                return position {pos.row + 1, pos.col, direction::downward,
                                 get_char(pos.row + 1, pos.col)};
        }
    };

    std::unordered_set<position, position_hash> visited_positions {};

    position pos {start_row, start_col, direction::upward, get_char(start_row, start_col)};

    while (pos.ch != 0) {
        visited_positions.insert(pos);
        // pos.print();
        pos = get_next_position(pos);
    }

    return visited_positions.size();
}

} // namespace part_one
