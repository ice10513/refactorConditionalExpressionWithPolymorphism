#include "Interface.hpp"
#include "Mac.hpp"
#include "PhyUl.hpp"
#include "PhyDl.hpp"

class TechMsgBuilderFactory : public ITechMsgBuilderFactory
{
public:
    std::shared_ptr<IPhyUlTechMsgBuilder> createPhyUlTechBuilder(Tech p_tech) override
    {
        if (p_tech == Tech::Fdd)
        {
            return std::make_shared<FddPhyUlBuilder>();
        }
        return std::make_shared<TddPhyUlBuilder>();
    }

    std::shared_ptr<IPhyDlTechMsgBuilder> createPhyDlTechBuilder(Tech p_tech) override
    {
        if (p_tech == Tech::Fdd)
        {
            return std::make_shared<FddPhyDlBuilder>();
        }
        return std::make_shared<TddPhyDlBuilder>();
    }

    std::shared_ptr<IMacTechMsgBuilder> createMacTechBuilder(Tech p_tech) override
    {
        if (p_tech == Tech::Fdd)
        {
            return std::make_shared<FddMacBuilder>();
        }
        return std::make_shared<TddMacBuilder>();
    }
};

class MsgBuilderFactory : public IMsgBuilderFactory
{
public:
    MsgBuilderFactory(const std::shared_ptr<ITechMsgBuilderFactory>& p_techMsgBuilderFactory) :
        m_techMsgBuilderFactory(p_techMsgBuilderFactory)
    {}

    std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder(Tech p_tech) override
    {
        return std::make_shared<PhyUlBuilder>(m_techMsgBuilderFactory->createPhyUlTechBuilder(p_tech));
    }

    std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder(Tech p_tech) override
    {
        return std::make_shared<PhyDlBuilder>(m_techMsgBuilderFactory->createPhyDlTechBuilder(p_tech));
    }

    std::shared_ptr<IMacMsgBuilder> createMacBuilder(Tech p_tech) override
    {
        return std::make_shared<MacBuilder>(m_techMsgBuilderFactory->createMacTechBuilder(p_tech));
    }

private:
    std::shared_ptr<ITechMsgBuilderFactory> m_techMsgBuilderFactory;
};
