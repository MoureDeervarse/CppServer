#include "Lock.h"

void SpinLock::lock() {
    bool expected= false;
    while (is_locked.compare_exchange_strong(expected, true) == false) {
        expected = false;
    }
}

void SpinLock::unlock() {
    is_locked.store(false);
}