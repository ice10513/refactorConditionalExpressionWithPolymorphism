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
    virtual void build() = 0;
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
    virtual std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder(Tech) = 0;
    virtual std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder(Tech) = 0;
    virtual std::shared_ptr<IMacMsgBuilder> createMacBuilder(Tech) = 0;
};
