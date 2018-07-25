#include "Interface.hpp"

class PhyDlBuilder : public IPhyDlMsgBuilder
{
public:
    PhyDlBuilder(const std::shared_ptr<IPhyDlTechMsgBuilder>& p_phyDlTechMsgBuilder) :
        m_phyDlTechMsgBuilder(p_phyDlTechMsgBuilder)
    {}

    void build() override
    {
        std::cout << "PhyDlBuilder.build begin\n";
        m_phyDlTechMsgBuilder->build();
        std::cout << "PhyDlBuilder.build end\n";
    }
private:
    std::shared_ptr<IPhyDlTechMsgBuilder> m_phyDlTechMsgBuilder;
};

class FddPhyDlBuilder : public IPhyDlTechMsgBuilder
{
public:
    void build() override
    {
        std::cout << "FddPhyDlBuilder.build\n";
    }
};

class TddPhyDlBuilder : public IPhyDlTechMsgBuilder
{
public:
    void build() override
    {
        std::cout << "TddPhyDlBuilder.build\n";
    }
};