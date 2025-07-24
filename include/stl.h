#ifndef STL_H
#define STL_H
void initial_vector_with_3_mutiplies(std::vector<int>& v, size_t size) {
    v.clear();
    for (size_t i = 0; i < size; i++) {
        v.push_back((i+1)*3);
    }
}

int count_unique_above(std::vector<int> v, int n) {
    std::set<int> s(v.begin(), v.end());
    return std::count_if(s.begin(), s.end(),
                         [n](int x) { return x > n; });
}
std::string vector_to_string(std::vector<int> v, char separator) {
    auto dash_fold = [separator](std::string a, int b)
    {
        return std::move(a) + separator + std::to_string(b);
    };
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
                                   std::to_string(v.back()),
                                   dash_fold);
    return rs;
}

void square_elements(std::vector<int>& v) {
    std::transform(v.begin(), v.end(), v.begin(),[](int x) {
        return x*x;
    });
}

void copy_if_even(const std::vector<int>& source, std::vector<int>& destination) {
    destination.clear();std::copy_if(source.begin(), source.end(),
        std::back_inserter(destination),
                        [](int x) { return x % 2 == 0; });

}
#endif //STL_H