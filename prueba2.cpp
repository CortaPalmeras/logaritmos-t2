
#include <iostream>
#include <vector>

class Logger {
public:
    int val;
    // Default constructor
    Logger() {
        val = 0;
        std::cout << "Logger initialized." << std::endl;
    }

    // Alternative Constructor
    Logger(int n) {
        val = n;
        std::cout << "Logger initialized (" << val << ")." << std::endl;
    }

    // Copy constructor
    Logger(const Logger& o) {
        val = o.val;
        std::cout << "Logger copied (" << val << ")." << std::endl;
    }

    // Move constructor
    Logger(Logger&& o) noexcept {
        val = o.val;
        std::cout << "Logger moved (" << val << ")." << std::endl;
    }

    // Copy assignment operator
    Logger& operator=(const Logger& other) {
        val = other.val;
        std::cout << "Logger copied (" << val << ")." << std::endl;
        return *this;
    }

    // Move assignment operator
    Logger& operator=(Logger&& other) noexcept {
        val = other.val;
        std::cout << "Logger moved (" << val << ")." << std::endl;
        return *this;
    }

    // Destructor
    ~Logger() {
        std::cout << "Logger destroyed (" << val << ")." << std::endl;
    }
};

using std::vector, std::pair, std::cout, std::endl;

pair<vector<Logger>, vector<Logger>> func() {
    cout << "primer vec" << endl;
    vector<Logger> v1(5);

    cout << "segundo vec" << endl;
    vector<Logger> v2;
    v2.reserve(5);

    cout << "llenado segundo vec" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "añadir item " << i << endl;
        v2.emplace_back(i);
    }

    cout << "fin func" << endl;
    return {std::move(v1), std::move(v2)};
}

int main() {
    cout << "ini func" << endl;
    pair<vector<Logger>, vector<Logger>> p = func();
    cout << "fin func" << endl;
    return 0;
}
