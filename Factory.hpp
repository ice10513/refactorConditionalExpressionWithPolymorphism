#include "Interface.hpp"
#include "Mac.hpp"
#include "PhyUl.hpp"
#include "PhyDl.hpp"

class MsgBuilderFactory : public IMsgBuilderFactory
{
public:
    std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder() override
    {
        return std::make_shared<PhyUlBuilder>();
    }

    std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder() override
    {
        return std::make_shared<PhyDlBuilder>();
    }

    std::shared_ptr<IMacMsgBuilder> createMacBuilder() override
    {
        return std::make_shared<MacBuilder>();
    }
};
