 
//
//  LutinLangInterperter
//  Symbol.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//


#ifndef TOKENS
#define TOKENS

#include <iostream>
using namespace std;

typedef enum {
	//Terminal Symbols
	VAR,
	CONST,
	AFFECT,
	EQUAL,
	SEP,
	WRITE,
	READ,
	END,
	ID,
	VAL,
	MINUS,
	OPENBY,
	CLOSEBY,
	MULT,
	DIVIDE,
	PLUS,
	//Non terminal symbols
	P,
	PD,
	LD,
	LV,
	LC,
	D,
	PI,
	LI,
	E,
	//Other
	INVALID,
	END_OF_FILE
} Tokens;

typedef struct {
    Tokens token;
    void* value;
} ValuableToken;

typedef struct {
    int line;
    int column;
} cursor;

ostream& operator<< (ostream& os, const ValuableToken& t);
bool is_terminal_token(const ValuableToken& t);

#endif  // TOKENS




