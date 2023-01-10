#include "ThreadBaseClass.h"
ThreadBaseClass::ThreadBaseClass()
{

}

ThreadBaseClass::~ThreadBaseClass(){
}

void ThreadBaseClass::init(){
    //thread implementation will be here to call update function
    static std::future<void> tBaseThread;
    tBaseThread = std::async(std::launch::async,&ThreadBaseClass::update,this);
    setMainThread(&tBaseThread);
}

void ThreadBaseClass::update() {
    while(true){
        const std::lock_guard<std::mutex> tMainMutex(mMutex);
        someOtherFunctions();
        tickUpdate();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void ThreadBaseClass::setMainThread(std::future<void> *pThread){
    
    if(mBaseThread==pThread)
        return;
    mBaseThread = pThread;
}

std::future<void>*ThreadBaseClass::getMainThread() const{
    return mBaseThread;
}
