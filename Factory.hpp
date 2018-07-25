#include "Interface.hpp"
#include "Mac.hpp"
#include "PhyUl.hpp"
#include "PhyDl.hpp"

class FddMsgBuilderFactory : public IMsgBuilderFactory
{
public:
    std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder() override
    {
        return std::make_shared<PhyUlBuilder>(std::make_shared<FddPhyUlBuilder>());
    }

    std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder() override
    {
        return std::make_shared<PhyDlBuilder>(std::make_shared<FddPhyDlBuilder>());
    }

    std::shared_ptr<IMacMsgBuilder> createMacBuilder() override
    {
        return std::make_shared<MacBuilder>(std::make_shared<FddMacBuilder>());
    }''
};


class TddMsgBuilderFactory : public IMsgBuilderFactory
{
public:
    std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder() override
    {
        return std::make_shared<PhyUlBuilder>(std::make_shared<TddPhyUlBuilder>());
    }

    std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder() override
    {
        return std::make_shared<PhyDlBuilder>(std::make_shared<TddPhyDlBuilder>());
    }

    std::shared_ptr<IMacMsgBuilder> createMacBuilder() override
    {
        return std::make_shared<MacBuilder>(std::make_shared<TddMacBuilder>());
    }
};

class TechMsgBuilderFactory : public ITechMsgBuilderFactory
{
public:
    std::shared_ptr<IMsgBuilderFactory> createMsgBuilderFactory(Tech p_tech) override
    {
        if (p_tech == Tech::Fdd)
        {
            return std::make_shared<FddMsgBuilderFactory>();
        }
        return std::make_shared<TddMsgBuilderFactory>();
    }
};