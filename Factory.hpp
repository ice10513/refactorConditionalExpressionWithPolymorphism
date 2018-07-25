#include "Interface.hpp"
#include "Mac.hpp"
#include "PhyUl.hpp"
#include "PhyDl.hpp"

class MsgBuilderFactory : public IMsgBuilderFactory
{
public:
    std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder(Tech p_tech) override
    {
        if (p_tech == Tech::Fdd)
        {
            return std::make_shared<PhyUlBuilder>(std::make_shared<FddPhyUlBuilder>());
        }
        return std::make_shared<PhyUlBuilder>(std::make_shared<TddPhyUlBuilder>());
    }

    std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder(Tech p_tech) override
    {
        if (p_tech == Tech::Fdd)
        {
            return std::make_shared<PhyDlBuilder>(std::make_shared<FddPhyDlBuilder>());
        }
        return std::make_shared<PhyDlBuilder>(std::make_shared<TddPhyDlBuilder>());
    }

    std::shared_ptr<IMacMsgBuilder> createMacBuilder(Tech p_tech) override
    {
        if (p_tech == Tech::Fdd)
        {
            return std::make_shared<MacBuilder>(std::make_shared<FddMacBuilder>());
        }
        return std::make_shared<MacBuilder>(std::make_shared<TddMacBuilder>());
    }
};
