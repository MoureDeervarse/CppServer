#include <thread>

#include "Lock.h"

SpinLock::SpinLock(bool isWaitable) {
    useYield = isWaitable;
}

void SpinLock::lock() {
    bool expected= false;
    while (is_locked.compare_exchange_strong(expected, true) == false) {
        expected = false;
        if (useYield) {
            // std::chrono::milliseconds(100)
            std::this_thread::yield();
        }
    }
}

void SpinLock::unlock() {
    is_locked.store(false);
}