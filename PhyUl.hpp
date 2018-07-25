#include "Interface.hpp"

class PhyUlBuilder : public IPhyUlMsgBuilder
{
public:
    PhyUlBuilder(const std::shared_ptr<IPhyUlTechMsgBuilder>& p_phyUlTechMsgBuilder) :
        m_phyUlTechMsgBuilder(p_phyUlTechMsgBuilder)
    {}

    void build() override
    {
        std::cout << "PhyUlBuilder.build begin\n";
        m_phyUlTechMsgBuilder->build();
        std::cout << "PhyUlBuilder.build end\n";
    }
private:
    std::shared_ptr<IPhyUlTechMsgBuilder> m_phyUlTechMsgBuilder;
};

class FddPhyUlBuilder : public IPhyUlTechMsgBuilder
{
public:
    void build() override
    {
        std::cout << "FddPhyUlBuilder.build\n";
    }
};

class TddPhyUlBuilder : public IPhyUlTechMsgBuilder
{
public:
    void build() override
    {
        std::cout << "TddPhyUlBuilder.build\n";
    }
};
