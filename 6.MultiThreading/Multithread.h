#include <thread>
#include <iostream>
#include <vector>
#include <atomic>
#include <Mutex>
#include <functional>
//Author : Burak Dogancay
class MultiThread
{
public:
    MultiThread();
    ~MultiThread();
    void threadManagement1();
    void threadManagement2();
    void threadLambda();

    void incrementFunc1();
    void incrementFunc2();
    void incrementAtomic1();
    void incrementAtomic2();
    

private:
    std::mutex mMutex;
    int mincrement;
    std::atomic<int> increment;
};