//
//  LutinLangInterperter
//  AffectSymbol.cpp
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include <iostream>
#include "AffectSymb.h"


using namespace std;


AffectSymb::~AffectSymb()
{
    delete expression;
}

void AffectSymb::print()
{
	variable.print();
	cout << " = ";
	expression -> print();

}