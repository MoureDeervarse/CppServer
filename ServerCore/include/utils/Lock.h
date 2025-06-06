#include <atomic>

class SpinLock {
public:
    SpinLock(bool isWaitable = false);
    void lock();
    void unlock();
private:
    bool useYield = false;
    std::atomic<bool> is_locked = false;
};
