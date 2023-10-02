#include <string>
#include <vector>

int FindStringInVector(const std::vector<std::string>& v, const std::string& s) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == s) return (int) i;
    }
    return -1;
}

int FindStringInVector(const std::vector<std::string>& v, const char c) {
    std::string s{c};
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == s) return (int) i;
    }
    return -1;
}