#include <thread>

#include "Utils/CorePch.h"

int staticNum = 0;

void AddStaticNum()
{
    for (int32 idx = 0; idx < 10000; idx++) {
        staticNum++;
    }
}

void MinStaticNum()
{
    for (int32 idx = 0; idx < 10000; idx++) {
        staticNum--;
    }
}

int main() {
    std::thread first_thread = std::thread(MinStaticNum);
    first_thread.join();

    std::thread second_thread = std::thread(AddStaticNum);

    second_thread.join();

    cout << staticNum << endl;

    return 0;
}
