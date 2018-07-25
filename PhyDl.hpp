#include "Interface.hpp"

class PhyDlBuilder : public IPhyDlMsgBuilder
{
public:
    void build(Tech p_tech) override
    {
        std::cout << "PhyDlBuilder.build begin\n";
        if (p_tech == Tech::Fdd)
        {
            std::cout << "Fdd builder\n";
        }
        else
        {
            std::cout << "Tdd builder\n";
        }
        std::cout << "PhyDlBuilder.build end\n";
    }
};