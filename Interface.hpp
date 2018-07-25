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

class ITechMsgBuilder : public IMsgBuilder
{};

class IPhyUlTechMsgBuilder : public ITechMsgBuilder
{};

class IPhyDlTechMsgBuilder : public ITechMsgBuilder
{};

class IMacTechMsgBuilder : public ITechMsgBuilder
{};

class IMsgBuilderFactory
{
public:
    virtual ~IMsgBuilderFactory() = default;
    virtual std::shared_ptr<IPhyUlMsgBuilder> createPhyUlBuilder(Tech) = 0;
    virtual std::shared_ptr<IPhyDlMsgBuilder> createPhyDlBuilder(Tech) = 0;
    virtual std::shared_ptr<IMacMsgBuilder> createMacBuilder(Tech) = 0;
};

class ITechMsgBuilderFactory
{
public:
    virtual ~ITechMsgBuilderFactory() = default;
    virtual std::shared_ptr<IPhyUlTechMsgBuilder> createPhyUlTechBuilder() = 0;
    virtual std::shared_ptr<IPhyDlTechMsgBuilder> createPhyDlTechBuilder() = 0;
    virtual std::shared_ptr<IMacTechMsgBuilder> createMacTechBuilder() = 0;
};

class ITechMsgBuilderFactoryFactory
{
public:
    virtual ~ITechMsgBuilderFactoryFactory() = default;
    virtual std::shared_ptr<ITechMsgBuilderFactory> createTechMsgBuilderFactory(Tech) = 0;
};