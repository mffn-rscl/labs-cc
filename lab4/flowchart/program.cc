#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

// Version 1
std::string version1(int n) {
    std::string result;
    for (int i = 1; i <= n; ++i) {
        result += std::to_string(i) + " ";
    }
    result.pop_back(); // Remove the trailing space
    return result;
}

// Version 2
std::string version2(int n) {
    std::string result;
    for (int i = n; i >= 1; --i) {
        result = result + std::to_string(i) + " ";
    }
    result.pop_back(); // Remove the trailing space
    return result;
}

// Version 3
std::string version3(int n) {
    std::stringstream result;
    for (int i = 1; i <= n; ++i) {
        result << i << " ";
    }
    result.seekp(-1, result.cur); // Move the position back to remove the trailing space
    return result.str();
}

// Version 4
std::string version4(int n) {
    std::stringstream result;
    for (int i = n; i >= 1; --i) {
        result << i << " ";
    }
    result.seekp(-1, result.cur); // Move the position back to remove the trailing space
    return result.str();
}

int main() {
    int n1 = 10000, n2 = 20000, n3 = 50000, n4 = 100000, n5 = 200000;

    // Version 1
    auto start1 = std::chrono::high_resolution_clock::now();
    std::string result1 = version1(n1);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Result for n1=" << n1 << " (Version 1): " << result1 << std::endl;
    std::cout << "Time taken for n1=" << n1 << ": " << duration1.count() << " seconds" << std::endl;

    // Version 2
    auto start2 = std::chrono::high_resolution_clock::now();
    std::string result2 = version2(n2);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    std::cout << "Result for n2=" << n2 << " (Version 2): " << result2 << std::endl;
    std::cout << "Time taken for n2=" << n2 << ": " << duration2.count() << " seconds" << std::endl;

    // Version 3
    auto start3 = std::chrono::high_resolution_clock::now();
    std::string result3 = version3(n3);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration3 = end3 - start3;
    std::cout << "Result for n3=" << n3 << " (Version 3): " << result3 << std::endl;
    std::cout << "Time taken for n3=" << n3 << ": " << duration3.count() << " seconds" << std::endl;

    // Version 4
    auto start4 = std::chrono::high_resolution_clock::now();
    std::string result4 = version4(n4);
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration4 = end4 - start4;
    std::cout << "Result for n4=" << n4 << " (Version 4): " << result4 << std::endl;
    std::cout << "Time taken for n4=" << n4 << ": " << duration4.count() << " seconds" << std::endl;

    // Similar code for n5

    return 0;
}