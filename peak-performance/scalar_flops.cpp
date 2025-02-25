/**
 * compiled by: g++ -O0 -o scalar_flops scalar_flops.cpp
 * Here as the value is just intially fetched by memory and rest
 * of the time is fetched from cache hence, OI = 4/0 ~ infinity
 */
#include <iostream>
#include <chrono>
#include <math.h>

int main() {
    const register size_t num_operations = pow(2,30); // 1 billion floating-point operations
    register float a = 1.1f, b = 2.2f, c = 3.3f, d = 4.4f, e = 5.5f, f = 6.6f, g = 7.7f, h = 8.8f; // Prevent optimization
    // volatile means my value might change anytime so dont optimize
    register float j;
    auto start = std::chrono::high_resolution_clock::now();

    for (register size_t i = 0; i < num_operations; ++i) {
        // a = (b * c + d / e - a) / (b + c / d - e * a)* 
        // (b - c + d + e / a) + (b / c * d + e - a) - 
        // (b * c * d + e - a) / (b * c / d * e - a) + 
        // (b * c * d - e - a) + (b + c + d - e - a) * 
        // (b + c * d * e - a) - (b + c + d * e - a) /
        // (b * c + d - e * a) * (b * c + d + e / a) - 
        // (b + c * d + e - a) / (b * c * d * e - a) * 
        // (b * c * d * e / a) - (b / c + d * e + a) - 
        // (b / c * d * e - a) / (b / c * d + e - a) + 
        // (b + c * d - e - a) + (b * c + d - e - a) +
        // (b + c * d / e - a) + (b / c + d * e - a) ;
        j = (a * a);
        j = (b * b);
        j = (c * c);
        j = (d * d);
        j = (e * e);
        j = (f * f);
        j = (g * g);
        j = (h * h);

    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    printf("%f", j);
    double time_seconds = elapsed.count();
    double flops = (4.0 * num_operations) / time_seconds; // 4 FLOPs per iteration

    std::cout << "Time taken: " << time_seconds << " seconds\n";
    std::cout << "Scalar FLOP Performance: " << flops/float(pow(10,9)) << " GFLOPS\n";
    return 0;
}
