#include <iostream>

int main(int argc, const char * argv[]) {
    int people [] { 200, 0, -10, 1, 0, -50, 25 };
    for (int pos = 0; pos < ((sizeof(people) / sizeof(people[0])) - 1); ++pos){
        if (people[pos] == 0) continue;
        for (int i = pos + 1; i < (sizeof(people) / sizeof(people[0])); ++i) {
            if (people[i] < people [pos] and people[i] != 0)
                std::swap(people[i], people [pos]);
        }
    }
    
    for (int pos = 0; pos < (sizeof(people) / sizeof(people[0])); ++pos) {
        std::cout << people[pos] << ' ';
    }
    std::cout << '\n';
        return 0;
}
