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
    std::vector<std::pair<int, int>> page_ordering_rules {};

    return std::ranges::fold_left(document | std::views::split('\n'), 0, [&](int sum, auto&& line) {
        if (std::ranges::contains(line, '|')) {
            const auto str = line | std::ranges::to<std::string>();
            page_ordering_rules.emplace_back(std::stoi(str.substr(0,2)), std::stoi(str.substr(3,2)));
        } else if (std::ranges::contains(line, ',')) {
            auto update_page_numbers
                = line | std::views::split(',') | std::views::transform([](auto&& page) {
                return std::stoi(std::string(page.begin(), page.end()));
            }) | std::ranges::to<std::vector<int>>();

            bool is_sorted {true};
            std::ranges::stable_sort(update_page_numbers, [&](int left, int right) {
                const bool is_wrong_order
                    = std::ranges::none_of(page_ordering_rules, [&](auto&& page_order) {
                    return (right == page_order.first) && (left == page_order.second);
                });
                if (is_wrong_order) {
                    is_sorted = false;
                }
                return is_wrong_order;
            });

            // fmt::println("{}", update_page_numbers);

            if (not is_sorted) {
                sum += update_page_numbers.at(update_page_numbers.size() / 2);
            }
        }
        return sum;
    });
}

} // namespace part_two
