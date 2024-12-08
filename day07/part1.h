#pragma once

#include <algorithm>
#include <fmt/ranges.h>
#include <ranges>
#include <spanstream>
#include <string_view>
#include <tuple>
#include <vector>

namespace part_one
{

constexpr char add      = '+';
constexpr char multiply = '*';

constexpr std::array operaters {add, multiply};

[[nodiscard]] constexpr static auto calc_calibration(const std::vector<size_t>& values,
                                                     const size_t               result) -> size_t
{
    switch (values.size()) {
        case 2: {
            if (values.front() * values.back() == result
                || values.front() + values.back() == result) {
                return result;
            }
            break;
        }
        case 3: {
            for (auto&& operations_tie : std::views::cartesian_product(operaters, operaters)) {
                const auto [a, b] = operations_tie;
                std::array operations {a, b};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 4: {
            for (auto&& operations_tie :
                 std::views::cartesian_product(operaters, operaters, operaters)) {
                const auto [a, b, c] = operations_tie;
                std::array operations {a, b, c};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 5: {
            for (auto&& operations_tie :
                 std::views::cartesian_product(operaters, operaters, operaters, operaters)) {
                const auto [a, b, c, d] = operations_tie;
                std::array operations {a, b, c, d};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 6: {
            for (auto&& operations_tie : std::views::cartesian_product(
                     operaters, operaters, operaters, operaters, operaters)) {
                const auto [a, b, c, d, e] = operations_tie;
                std::array operations {a, b, c, d, e};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 7: {
            for (auto&& operations_tie : std::views::cartesian_product(
                     operaters, operaters, operaters, operaters, operaters, operaters)) {
                const auto [a, b, c, d, e, f] = operations_tie;
                std::array operations {a, b, c, d, e, f};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 8: {
            for (auto&& operations_tie : std::views::cartesian_product(
                     operaters, operaters, operaters, operaters, operaters, operaters, operaters)) {
                const auto [a, b, c, d, e, f, g] = operations_tie;
                std::array operations {a, b, c, d, e, f, g};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 9: {
            for (auto&& operations_tie :
                 std::views::cartesian_product(operaters, operaters, operaters, operaters,
                                               operaters, operaters, operaters, operaters)) {
                const auto [a, b, c, d, e, f, g, h] = operations_tie;
                std::array operations {a, b, c, d, e, f, g, h};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 10: {
            for (auto&& operations_tie : std::views::cartesian_product(
                     operaters, operaters, operaters, operaters, operaters, operaters, operaters,
                     operaters, operaters)) {
                const auto [a, b, c, d, e, f, g, h, j] = operations_tie;
                std::array operations {a, b, c, d, e, f, g, h, j};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 11: {
            for (auto&& operations_tie : std::views::cartesian_product(
                     operaters, operaters, operaters, operaters, operaters, operaters, operaters,
                     operaters, operaters, operaters)) {
                const auto [a, b, c, d, e, f, g, h, j, k] = operations_tie;
                std::array operations {a, b, c, d, e, f, g, h, j, k};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
        case 12: {
            for (auto&& operations_tie : std::views::cartesian_product(
                     operaters, operaters, operaters, operaters, operaters, operaters, operaters,
                     operaters, operaters, operaters, operaters)) {
                const auto [a, b, c, d, e, f, g, h, j, k,l] = operations_tie;
                std::array operations {a, b, c, d, e, f, g, h, j, k,l};

                size_t res = values.front();
                for (size_t i = 1; i < values.size(); ++i) {
                    res = operations.at(i - 1) == add ? res + values.at(i) : res * values.at(i);
                }
                if (res == result) {
                    return result;
                }
            }
            break;
        }
    }
    return 0;
}

[[nodiscard]] constexpr static auto get_result(const std::string_view document) -> size_t
{
    // Accumulate the values
    return std::ranges::fold_left(document | std::views::split('\n'), 0, [&](size_t sum, auto&& line) {
        std::vector<size_t> values;
        size_t              result {};

        std::ispanstream stream(line);
        stream >> result;
        stream.ignore(1);
        std::ranges::copy(std::views::istream<size_t>(stream), std::back_inserter(values));

        // fmt::println("{}", values);

        return sum + calc_calibration(values, result);
    });
}

} // namespace part_one
