#ifndef THREADBASECLASS_H
#define THREADBASECLASS_H
#include <thread>
#include <iostream>
#include <future>
#include <Mutex>
//Author : Burak Dogancay
class ThreadBaseClass
{
public:
    ThreadBaseClass();
    virtual ~ThreadBaseClass();

    virtual void init();
    virtual void update();
    virtual void tickUpdate()=0; // pure virtual function that make it abstractclass, it should be used for safety,because it should be created in all derived class
    virtual void someOtherFunctions()=0;

    void setMainThread(std::future<void> *pThread);
    std::future<void>* getMainThread() const;

private:
    std::mutex mMutex;
    std::future<void> *mBaseThread;
    int mThreadMillisecond = 1000;
};

#endif