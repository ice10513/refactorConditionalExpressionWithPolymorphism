#pragma once

enum class Tech
{
    Tdd,
    Fdd
};

class IMsgBuilder
{
public:
    virtual ~IMsgBuilder() = default;
    virtual void build(Tech) = 0;
};

class IPhyUlMsgBuilder : public IMsgBuilder
{};

class IPhyDlMsgBuilder : public IMsgBuilder
{};

class IMacMsgBuilder : public IMsgBuilder
{};

class IMsgBuilderFactory
{
public:
    virtual ~IMsgBuilderFactory() = default;
    virtual std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder() = 0;
    virtual std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder() = 0;
    virtual std::shared_ptr<IMacMsgBuilder> createMacBuilder() = 0;
};
