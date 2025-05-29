#include <atomic>

class SpinLock {
public:
    void lock();
    void unlock();
private:
    std::atomic<bool> is_locked = false;
};
