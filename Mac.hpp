#include "Interface.hpp"

class MacBuilder : public IMacMsgBuilder
{
public:
    MacBuilder(const std::shared_ptr<IMacTechMsgBuilder>& p_macTechMsgBuilder) :
        m_macTechMsgBuilder(p_macTechMsgBuilder)
    {}

    void build() override
    {
        std::cout << "MacBuilder.build begin\n";
        m_macTechMsgBuilder->build();
        std::cout << "MacBuilder.build end\n";
    }
private:
    std::shared_ptr<IMacTechMsgBuilder> m_macTechMsgBuilder;
};

class FddMacBuilder : public IMacTechMsgBuilder
{
public:
    void build() override
    {
        std::cout << "FddMacBuilder.build\n";
    }
};

class TddMacBuilder : public IMacTechMsgBuilder
{
public:
    void build() override
    {
        std::cout << "TddMacBuilder.build\n";
    }
};