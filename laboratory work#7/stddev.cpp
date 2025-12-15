#include "pch.h"
#define STDMODULE_EXPORTS
#include "pch.h"
#include "stddev.h"
#include <cmath>
#include <chrono>

STDMODULE_API float calculate_std_dev(float* array, size_t size, double* elapsed_time_ms) {

    auto start = std::chrono::high_resolution_clock::now();

    float sum = 0.0f;
    for (size_t i = 0; i < size; ++i) {
        sum += array[i];
    }
    float mean = sum / static_cast<float>(size);

    float sum_of_squared_diff = 0.0f;
    for (size_t i = 0; i < size; ++i) {
        float diff = array[i] - mean;
        sum_of_squared_diff += diff * diff;
    }

    float variance = sum_of_squared_diff / static_cast<float>(size);
    float std_dev = std::sqrt(variance);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_ms = end - start;

    *elapsed_time_ms = duration_ms.count();

    return std_dev;
}