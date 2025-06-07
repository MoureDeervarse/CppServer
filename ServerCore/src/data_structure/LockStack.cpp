#pragma once
#include <mutex>
#include <stack>
#include <condition_variable>

#include "LockStack.h"

using namespace std;

template<typename T>
LockStack<T>::LockStack() {}

template<typename T>
void LockStack<T>::Push(T value) {
    lock_guard<mutex> lock(_mutex);
    _stack.push(move(value));
    _cv.notify_one();
}

template<typename T>
bool LockStack<T>::TryPop(T& value) {
    lock_guard<mutex> lock(_mutex);

    if (_stack.empty()) {
        return false;
    }

    value = std::move(_stack.top());
    _stack.pop();
    return true;
}

template<typename T>
void LockStack<T>::WaitPop(T& value) {
    unique_lock<mutex> lock(_mutex);
    _cv.wait(lock, [this] { return !_stack.empty(); });
    value = std::move(_stack.top());
    _stack.pop();
}
