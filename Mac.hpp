#include "Interface.hpp"

class MacBuilder : public IMacMsgBuilder
{
protected:
    void buildCommon()
    {
        std::cout << "MacBuilder.build begin\n";
        std::cout << "MacBuilder.build end\n";
    }
};

class FddMacBuilder : public MacBuilder
{
    void build() override
    {
        std::cout << "FddMacBuilder\n";
        buildCommon();
    }
};

class TddMacBuilder : public MacBuilder
{
    void build() override
    {
        std::cout << "TddMacBuilder\n";
        buildCommon();
    }
};
