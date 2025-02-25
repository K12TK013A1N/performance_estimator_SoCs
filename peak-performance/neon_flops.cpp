#include <iostream>
#include <chrono>
#include <arm_neon.h> // NEON Intrinsics for ARM

int main() {
    const size_t num_operations = 1e8;
    float32x4_t a = vdupq_n_f32(1.1f);
    float32x4_t b = vdupq_n_f32(2.2f);
    float32x4_t c = vdupq_n_f32(3.3f);
    float32x4_t d = vdupq_n_f32(4.4f);
    float32x4_t e = vdupq_n_f32(5.5f);

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < num_operations; ++i) {
        a = vmlaq_f32(a, b, c); // a = a + b * c (Fused Multiply-Add)
        d = vdivq_f32(d, e);     // d = d / e
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    double time_seconds = elapsed.count();
    double flops = (3.0 * num_operations * 4) / time_seconds; // 4 operations per NEON register

    std::cout << "Time taken: " << time_seconds << " seconds\n";
    std::cout << "Peak NEON FLOP Performance: " << flops / 1e9 << " GFLOPS\n";

    return 0;
}
