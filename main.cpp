#include <iostream>
#include <memory>
#include "Factory.hpp"

int main()
{
    TechMsgBuilderFactory l_techMsgBuilderFacotry;

    l_techMsgBuilderFacotry.createMsgBuilderFactory(Tech::Fdd)->createPhyUlBuilder()->build();
    l_techMsgBuilderFacotry.createMsgBuilderFactory(Tech::Tdd)->createPhyDlBuilder()->build();
    l_techMsgBuilderFacotry.createMsgBuilderFactory(Tech::Fdd)->createMacBuilder()->build();

    return 0;
}