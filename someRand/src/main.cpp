
#include <iostream>
#include <algorithm>

#include <random>
#include <array>

int main()
{
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::array<int, 6> results = {0};
    std::array<int, 6> results2 = {0};
    std::array<int, 12> resultsSum = {0};
    for (int i = 0; i < 100000; i++)
    {
        int result = (rng() % 6) + 1;
        int result2 = (rng() % 6) + 1;
        results[result - 1] += 1;
        results2[result2 - 1] += 1;
        int sum = result2 + result;
        resultsSum[sum - 1] += 1;
    }
    std::cout << std::endl;

    auto result1Sum = std::accumulate(results.begin(), results.end(), 0);
    auto result2Sum = std::accumulate(results2.begin(), results2.end(), 0);
    auto resultsSumSum = std::accumulate(resultsSum.begin(), resultsSum.end(), 0);
    auto avg1 = result1Sum / 6.0f;
    auto avg2 = result2Sum / 6.0f;
    auto avgSum = resultsSumSum / 12.0f;

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << i + 1 << ") " << results[i] << "( " << std::abs(results[i] - avg1) << " )" << std::endl;
        std::cout << i + 1 << "-2) " << results2[i] << "( " << std::abs(results2[i] - avg2) << " )" << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < resultsSum.size(); i++)
    {
        std::cout << i + 1 << ") " << resultsSum[i] << "( " << std::abs(resultsSum[i] - avgSum) << " )" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "1-avg) " << avg1 << std::endl;
    std::cout << "2-avg) " << avg2 << std::endl;
    std::cout << "sum-avg) " << avgSum << std::endl;

    return EXIT_SUCCESS;
}