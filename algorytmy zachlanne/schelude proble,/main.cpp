#include <iostream>
#include <algorithm>

#define ULL unsigned long long
#define LL long long
#define LD long double

struct Event
{
    ULL event_start{};
    ULL event_end{};
};

int main()
{
    Event *events_arr;
    Event *end_res_arr;
    ULL eventsCount{};
    ULL curren_end_index{1};
    ULL last_end_time{};
    std::cin >> eventsCount;

    events_arr = new Event[eventsCount];

    for (size_t i = 0; i < eventsCount; i++)
        std::cin >> events_arr[i].event_start >> events_arr[i].event_end;

    std::stable_sort(events_arr, events_arr + eventsCount, [](const Event &element1, const Event &element2)
                     { return element1.event_end < element2.event_end; });

    last_end_time = events_arr[0].event_end;
    for (size_t i = 1; i < eventsCount; i++)
    {
        if (events_arr[i].event_start >= last_end_time)
            curren_end_index++;
    }

    std::cout << curren_end_index << std::endl;

    delete[] events_arr;

    return 0;
}