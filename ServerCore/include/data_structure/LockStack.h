#pragma once
#include <mutex>

template<typename T>
class LockStack {
public:
    LockStack() {}
    LockStack(const LockStack&) = delete;
    LockStack& operator=(const LockStack&) = delete;

private:
    mutex _mutex;
    stack<T> _stack;
    condition_variable _cv;

    void Push(T value) {
        lock_guard<mutex> lock(_mutex);
        _stack.push(std::move(value));
        _cv.notify_one();
    }

    bool TryPop(T& value) {
        lock_guard<mutex> lock(_mutex);

        if (_stack.empty()) {
            return false;
        }

        value = std::move(_stack.top());
        _stack.pop();
        return true;
    }

    void WaitPop(T& value) {
        unique_lock<mutex> lock(_mutex);
        _cv.wait(lock, [this], { return _stack.empty() == false; });
        value = std::move(_stack.top());
        _stack.pop();
    }
};