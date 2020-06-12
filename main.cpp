#include <iostream>
#include <map>
#include <algorithm>

template<typename K, typename V>
std::map<V, K> inverted_map(const std::map<K, V> &in) {
    std::map<V, K> ret;
    auto it = std::transform(in.begin(), in.end(), std::inserter(ret, ret.begin()), [](auto &&item) {
        return std::pair<V, std::remove_cv_t<K>>(item.second, item.first);
    });
    return ret;
}

int main() {
    std::map<uint8_t, uint16_t> m;
    m[48] = 84;
    m[64] = 84;
    auto res = inverted_map(m);
    for(auto &&item:res) {
        std::cout << std::to_string(item.first) << ": " << std::to_string(item.second) << std::endl;
    }
    return 0;
}
