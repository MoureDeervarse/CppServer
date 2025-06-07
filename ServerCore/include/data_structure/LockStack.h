#pragma once
#include <mutex>

template<typename T>
class LockStack {
public:
    LockStack();
    LockStack(const LockStack&) = delete;
    LockStack& operator=(const LockStack&) = delete;

private:
    mutex _mutex;
    stack<T> _stack;
    condition_variable _cv;

    void Push(T value);
    bool TryPop(T& value);
    void WaitPop(T& value);
};