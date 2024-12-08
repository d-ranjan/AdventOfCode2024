#pragma once

#include <fmt/ranges.h>
#include <ranges>
#include <unordered_set>
#include <string_view>
#include <vector>

namespace part_two
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

    const auto insert_antinodes = [&](const Antinode node) -> bool{
        if((node.row < 0 || node.col < 0) || (node.row >= row_count || node.col >= col_count)){
            return false;
        }
        antinodes.insert(node);
        return true;
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

            int harmonics = 0;
            while(true){
                if(not insert_antinodes(Antinode{antenna.row - row_diff*harmonics, antenna.col - col_diff*harmonics})){
                    break;
                }
                harmonics++;
            }

            harmonics = 0;
            while(true){
                if(not insert_antinodes(Antinode{ant.row + row_diff*harmonics, ant.col + col_diff*harmonics})){
                    break;
                }
                harmonics++;
            }

        }
    }
    return antinodes.size();
}

} // namespace part_one
