#include <iostream>
#include <vector>
#include <cstdlib>
#include "../src/vector_tasks.hpp"

static int failures = 0;
#define CHECK(cond) do { if(!(cond)){ ++failures; std::cerr << "CHECK failed: " #cond << " at " << __FILE__ << ":" << __LINE__ << "\n"; } } while(0)

static bool eq(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) if (a[i] != b[i]) return false;
    return true;
}

int main() {
    // sum_at_even_indices
    CHECK(sum_at_even_indices({}) == 0);
    CHECK(sum_at_even_indices({5}) == 5);
    CHECK(sum_at_even_indices({5, 9}) == 5);
    CHECK(sum_at_even_indices({1, 2, 3}) == 1 + 3);
    CHECK(sum_at_even_indices({-1, 10, -2, 20, -3}) == (-1) + (-2) + (-3));
    CHECK(sum_at_even_indices({0,0,0,0}) == 0);

    // doubled
    CHECK(eq(doubled({}), {}));
    CHECK(eq(doubled({1}), {2}));
    CHECK(eq(doubled({1, -3, 4}), {2, -6, 8}));
    CHECK(eq(doubled({0, 0, 0}), {0, 0, 0}));

    if (failures == 0) {
        std::cout << "All tests passed.\n";
        return 0;
    } else {
        std::cerr << failures << " test(s) failed.\n";
        return 1;
    }
}
