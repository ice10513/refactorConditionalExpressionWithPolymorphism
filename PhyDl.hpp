#include "Interface.hpp"

class PhyDlBuilder : public IPhyDlMsgBuilder
{
protected:
    void buildCommon()
    {
        std::cout << "PhyDlBuilder.build begin\n";
        std::cout << "PhyDlBuilder.build end\n";
    }
};

class FddPhyDlBuilder : public PhyDlBuilder
{
    void build() override
    {
        std::cout << "FddPhyDlBuilder\n";
        buildCommon();
    }
};

class TddPhyDlBuilder : public PhyDlBuilder
{
    void build() override
    {
        std::cout << "TddPhyDlBuilder\n";
        buildCommon();
    }
};
