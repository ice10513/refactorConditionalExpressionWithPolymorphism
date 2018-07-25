#include "Interface.hpp"

class MacBuilder : public IMacMsgBuilder
{
public:
    void build(Tech p_tech) override
    {
        std::cout << "MacBuilder.build begin\n";
        if (p_tech == Tech::Fdd)
        {
            std::cout << "Fdd builder\n";
        }
        else
        {
            std::cout << "Tdd builder\n";
        }
        std::cout << "MacBuilder.build end\n";
    }
};