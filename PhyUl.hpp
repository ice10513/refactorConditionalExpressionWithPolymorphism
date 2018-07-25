#include "Interface.hpp"

class PhyUlBuilder : public IPhyUlMsgBuilder
{
protected:
    void buildCommon()
    {
        std::cout << "PhyUlBuilder.build begin\n";
        std::cout << "PhyUlBuilder.build end\n";
    }
};

class FddPhyUlBuilder : public PhyUlBuilder
{
    void build() override
    {
        std::cout << "FddPhyUlBuilder\n";
        buildCommon();
    }
};

class TddPhyUlBuilder : public PhyUlBuilder
{
    void build() override
    {
        std::cout << "TddPhyUlBuilder\n";
        buildCommon();
    }
};

