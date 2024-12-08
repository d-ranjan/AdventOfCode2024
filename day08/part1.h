#pragma once

#include <fmt/ranges.h>
#include <ranges>
#include <unordered_set>
#include <string_view>
#include <vector>

namespace part_one
{

struct Antenna
{
    int  row;
    int  col;
    char freq;
};

struct Antinode
{
    int row;
    int col;

    bool operator==(const Antinode& other) const = default;
};

struct Antinode_hash
{
    inline std::size_t operator()(const Antinode& antinode) const
    {
        return (antinode.row) ^ (antinode.col << 1);
    }
};

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> int
{
    std::vector<Antenna> antennas {};

    int row_count{};
    int col_count{};
    for (const auto& line : document | std::views::split('\n')) {
        col_count=0;
        for (const auto& ch : line) {
            if (ch != '.') {
                antennas.emplace_back(row_count, col_count, ch);
            }
            col_count++;
        }
        row_count++;
    }

    std::unordered_set<Antinode, Antinode_hash> antinodes;

    const auto insert_antinodes = [&](const Antinode node){
        if((node.row < 0 || node.col < 0) || (node.row >= row_count || node.col >= col_count)){
            return;
        }
        antinodes.insert(node);
    };

    for (const auto& antenna : antennas) {
        for (const auto& ant : antennas | std::views::filter([&](Antenna ant) {
            if(ant.freq != antenna.freq){
                return false;
            }
            return ant.row > antenna.row || (ant.row == antenna.row && ant.col > antenna.col);
        })) {
            const int row_diff = ant.row - antenna.row;
            const int col_diff = ant.col - antenna.col;
            insert_antinodes(Antinode{antenna.row - row_diff, antenna.col - col_diff});
            insert_antinodes(Antinode{ant.row + row_diff, ant.col + col_diff});
        }
    }
    return antinodes.size();
}

} // namespace part_one
