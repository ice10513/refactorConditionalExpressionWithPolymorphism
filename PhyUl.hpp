#include "Interface.hpp"

class PhyUlBuilder : public IPhyUlMsgBuilder
{
public:
    void build(Tech p_tech) override
    {
        std::cout << "PhyUlBuilder.build begin\n";
        if (p_tech == Tech::Fdd)
        {
            std::cout << "Fdd builder\n";
        }
        else
        {
            std::cout << "Tdd builder\n";
        }
        std::cout << "PhyUlBuilder.build end\n";
    }
};
