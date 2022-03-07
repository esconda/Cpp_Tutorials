#include "Multithread.h"
MultiThread::MultiThread() :
 mincrement(0),
 increment(0)
{

}

MultiThread::~MultiThread()
{
    
}

void MultiThread::threadManagement1()
{
    std::cout << "Thread hardware concurrency : " << std::thread::hardware_concurrency << std::endl;
    std::thread t1(&MultiThread::incrementFunc1, this);
    std::thread t2(&MultiThread::incrementFunc2, this);

    t1.join();
    t2.join();
}

void MultiThread::threadManagement2()
{
    std::cout << "Thread hardware concurrency : " << std::thread::hardware_concurrency << std::endl;
    std::thread t1(&MultiThread::incrementAtomic1, this);
    std::thread t2(&MultiThread::incrementAtomic2, this);

    t1.join();
    t2.join();
}

void MultiThread::threadLambda()
{
    //Assign lambda to std::function
    std::function<void()> func = [=](){
        while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        increment++;
        std::cout << "Increment function Lambda :" << increment << std::endl;
        }
    };
    
    //initialize thread
    std::thread t1(func);
    t1.join();
}

void MultiThread::incrementFunc1()
{

    while (true)
    {
        //std::this_thread::sleep_for(std::chrono::milliseconds(300));
        const std::lock_guard<std::mutex> lock(mMutex);
        //std::unique_lock<std::mutex> lock(mMutex);//safe incremenet no data races
        mincrement++;
        std::cout << "Increment function 1 :" << mincrement << std::endl;
        if (mincrement >= 50)
        {
            mincrement = 0;
        }
        //lock.unlock();
    }
}

void MultiThread::incrementFunc2()
{

    while (true)
    {
        //std::this_thread::sleep_for(std::chrono::milliseconds(300));
        const std::lock_guard<std::mutex> lock(mMutex);
        //std::unique_lock<std::mutex> lock(mMutex);
        mincrement++; //safe incremenet no data races
        std::cout << "Increment function 2 :" << mincrement << std::endl;
        if (mincrement >= 50)
        {
            mincrement = 0;
        }
        //lock.unlock();
    }
}

void MultiThread::incrementAtomic1()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        increment++;
        std::cout << "Increment atomic function 1: " << increment << std::endl;

        if (increment >= 50)
        {
            increment = 0;
        }
    }
}

void MultiThread::incrementAtomic2()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        increment++;
        std::cout << "Increment atomic function 2: " << increment << std::endl;

        if (increment >= 50)
        {
            increment = 0;
        }
    }
}