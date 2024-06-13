#include <iostream>
#include <algorithm>

#define ULL unsigned long long
#define LL long long
#define LD long double

struct Task
{
    ULL deadline{};
    ULL duration{};
};

int main()
{
    ULL tasks_count{}, recent_time{};

    LL max_points_count{};
    std::cin >> tasks_count;

    Task *tasks_arr{nullptr};
    tasks_arr = new Task[tasks_count];

    for (size_t i = 0; i < tasks_count; i++)
        std::cin >> tasks_arr[i].duration >> tasks_arr[i].deadline;

    std::sort(tasks_arr, tasks_arr + tasks_count, [](const Task &taskOne, const Task &taskTwo)
              { return taskOne.duration < taskTwo.duration; });

    for (size_t i = 0; i < tasks_count; i++)
    {
        recent_time += tasks_arr[i].duration;
        max_points_count += tasks_arr[i].deadline - recent_time;
    }

    std::cout << max_points_count << std::endl;

    delete[] tasks_arr;

    return 0;
}