#include <iostream>
#include <memory>
#include "Factory.hpp"

int main()
{
    MsgBuilderFactory l_msgBuilderFacotry;

    l_msgBuilderFacotry.createPhyUlBuilder()->build(Tech::Fdd);
    l_msgBuilderFacotry.createPhyDlBuilder()->build(Tech::Tdd);
    l_msgBuilderFacotry.createMacBuilder()->build(Tech::Fdd);

    return 0;
}