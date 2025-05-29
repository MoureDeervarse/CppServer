#include <thread>

#include "Utils/CorePch.h"
#include "Utils/Lock.h"

int staticNum = 0;
SpinLock spinLock;

void AddStaticNum()
{
    for (int32 idx = 0; idx < 10000; idx++) {
        spinLock.lock();
        staticNum++;
        spinLock.unlock();
    }
}

void MinStaticNum()
{
    for (int32 idx = 0; idx < 10000; idx++) {
        spinLock.lock();
        staticNum--;
        spinLock.unlock();
    }
}

int main() {
    std::thread first_thread = std::thread(MinStaticNum);

    std::thread second_thread = std::thread(AddStaticNum);

    first_thread.join();
    second_thread.join();

    cout << staticNum << endl;

    return 0;
}
