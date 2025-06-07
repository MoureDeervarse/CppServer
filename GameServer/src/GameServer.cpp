#include <thread>

#include "Core.h"
#include "utils/SpinLock.h"

int staticNum = 0;
SpinLock spinLock(true);

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

atomic<bool> ready;
int32 value;

void Producer() {
    value = 10;
    ready.store(true, memory_order_seq_cst);
}

void Consumer() {
    while (ready.load(memory_order_seq_cst) == false) {

    }
    cout << value << endl;
}

int main() {
    

    // std::thread first_thread = std::thread(MinStaticNum);
    // std::thread second_thread = std::thread(AddStaticNum);

    // first_thread.join();
    // second_thread.join();

    // cout << staticNum << endl;

    ready = false;
    value = 0;
    thread t1(Producer);
    thread t2(Consumer);

    t1.join();
    t2.join();

    return 0;
}
