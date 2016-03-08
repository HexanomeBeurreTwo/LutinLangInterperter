
//
//  LutinLangInterperter
//  Symbol.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//


#ifndef TOKEN_SYMBOL_H
#define TOKEN_SYMBOL_H

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
	E
} TokenSymbol;

#endif  // TOKEN_SYMBOL_H




