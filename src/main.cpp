#include "vector_tasks.hpp"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    vector<int> v;
    for (int i = 1; i < argc; ++i) {
        v.push_back(stoi(argv[i]));
    }
    cout << "sum_at_even_indices: " << sum_at_even_indices(v) << "\n";
    auto d = doubled(v);
    cout << "doubled: ";
    for (size_t i = 0; i < d.size(); ++i) {
        if (i) cout << " ";
        cout << d[i];
    }
    cout << "\n";
    return 0;
}
