#include "vector_tasks.hpp"
#include <vector>
using namespace std;

// TODO: Implement the two functions below.
// The current stubs compile but are intentionally incorrect so tests will fail
// until you provide a correct implementation.

int sum_at_even_indices(const vector<int>& v) {
    // TODO: sum v[0] + v[2] + v[4] + ...
    // Replace this incorrect placeholder:
    int sum = 0;
    for (size_t i = 1; i < v.size(); i += 2) { // <-- wrong on purpose
        sum += v[i];
    }
    return sum;
}

vector<int> doubled(const vector<int>& v) {
    // TODO: return a vector of the same size where each element is 2*x
    // Replace this incorrect placeholder:
    vector<int> out; // no reserve, no push -> wrong size
    return out;
}
