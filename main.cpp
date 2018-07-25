#include <iostream>
#include <memory>
#include "Factory.hpp"

int main()
{
    MsgBuilderFactory l_msgBuilderFacotry;

    l_msgBuilderFacotry.createPhyUlBuilder(Tech::Fdd)->build();
    l_msgBuilderFacotry.createPhyDlBuilder(Tech::Tdd)->build();
    l_msgBuilderFacotry.createMacBuilder(Tech::Fdd)->build();

    return 0;
}