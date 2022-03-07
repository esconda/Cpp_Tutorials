#ifndef FLOW_CONTROL_H
#define FLOW_CONTROL_H
#include <iostream>
#include <vector>
class Flow_Control{
    
    public:
        Flow_Control();
        ~Flow_Control();

        void flowControlSwitch();
        void flowControlTryCatch();
        void flowControlGoto();
        void flowControlForLoop();

        int getRet_Def();
        void setRet_Def(int pRet_Def);

    private:
    enum class SwitchControl{
            First,
            Second,
            Third,
            Forth
        };
    int mRet_Def;
    int mGoto_Def;
    SwitchControl mswitchcnt;

};

#endif 