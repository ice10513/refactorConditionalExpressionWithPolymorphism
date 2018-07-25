#include "Interface.hpp"
#include "Mac.hpp"
#include "PhyUl.hpp"
#include "PhyDl.hpp"


class FddTechMsgBuilderFactory : public ITechMsgBuilderFactory
{
public:
    std::shared_ptr<IPhyUlTechMsgBuilder> createPhyUlTechBuilder() override
    {
        return std::make_shared<FddPhyUlBuilder>();
    }

    std::shared_ptr<IPhyDlTechMsgBuilder> createPhyDlTechBuilder() override
    {
        return std::make_shared<FddPhyDlBuilder>();
    }

    std::shared_ptr<IMacTechMsgBuilder> createMacTechBuilder() override
    {
        return std::make_shared<FddMacBuilder>();
    }
};

class TddTechMsgBuilderFactory : public ITechMsgBuilderFactory
{
public:
    std::shared_ptr<IPhyUlTechMsgBuilder> createPhyUlTechBuilder() override
    {
        return std::make_shared<TddPhyUlBuilder>();
    }

    std::shared_ptr<IPhyDlTechMsgBuilder> createPhyDlTechBuilder() override
    {
        return std::make_shared<TddPhyDlBuilder>();
    }

    std::shared_ptr<IMacTechMsgBuilder> createMacTechBuilder() override
    {
        return std::make_shared<TddMacBuilder>();
    }
};

class TechMsgBuilderFactoryFactory : public ITechMsgBuilderFactoryFactory
{
public:
    std::shared_ptr<ITechMsgBuilderFactory> createTechMsgBuilderFactory(Tech p_tech) override
    {
        if (p_tech == Tech::Fdd)
        {
            return std::make_shared<FddTechMsgBuilderFactory>();
        }
        return std::make_shared<TddTechMsgBuilderFactory>();
    }
};

class MsgBuilderFactory : public IMsgBuilderFactory
{
public:
    MsgBuilderFactory(const std::shared_ptr<ITechMsgBuilderFactoryFactory>& p_techMsgBuilderFactoryFactory) :
        m_techMsgBuilderFactoryFactory(p_techMsgBuilderFactoryFactory)
    {}

    std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder(Tech p_tech) override
    {
        return std::make_shared<PhyUlBuilder>(m_techMsgBuilderFactoryFactory->createTechMsgBuilderFactory(p_tech)->createPhyUlTechBuilder());
    }

    std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder(Tech p_tech) override
    {
        return std::make_shared<PhyDlBuilder>(m_techMsgBuilderFactoryFactory->createTechMsgBuilderFactory(p_tech)->createPhyDlTechBuilder());
    }

    std::shared_ptr<IMacMsgBuilder> createMacBuilder(Tech p_tech) override
    {
        return std::make_shared<MacBuilder>(m_techMsgBuilderFactoryFactory->createTechMsgBuilderFactory(p_tech)->createMacTechBuilder());
    }

private:
    std::shared_ptr<ITechMsgBuilderFactoryFactory> m_techMsgBuilderFactoryFactory;
};
