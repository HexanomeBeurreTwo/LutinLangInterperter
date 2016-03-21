#Variables
CC=g++
SRC=src
OBJ=obj
MAIN=TestLexer
STATES=StatesInProgress
STATECLASS=$(wildcard  $(SRC)/$(STATES)/*.h)
INT=$(SRC)/Affectation.h \
$(SRC)/DeclarationConst.h \
$(SRC)/DeclarationVariable.h \
$(SRC)/Ecrire.h \
$(SRC)/Expression.h \
$(SRC)/Lexer.h \
$(SRC)/Lire.h \
$(SRC)/PartieDeclarative.h \
$(SRC)/PartieInstruction.h \
$(SRC)/Programme.h \
$(SRC)/Automaton.h \
$(SRC)/Tokens.h \
$(STATECLASS)
SOURCE= $(INT:.h=.cpp) $(SRC)/$(MAIN).cpp
HEADER= $(INT) $(SRC)/Instruction.h $(SRC)/Symbol.h $(SRC)/State.h $(SRC)/Declaration.h
OBJECT=$(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SOURCE)) 
FLAGS=-Wall -fexceptions -std=c++11 -Isrc
CLEAN=clean
ECHO=@echo 
OBJ_DIR=$(OBJ)/$(STATES) 
BIN_DIR=bin 
DLL=bin/boost_regex.dll
PROG=bin/LUT
CREP=*~ */*~ */*/*~
#LIB=lib/libboost_regex.a

DEBUGMAKE=dbg

#Directive
.PHONY: $(CLEAN) # decrit les regles SANS  dependances


#Dependances
all: $(DEBUGMAKE) $(OBJ_DIR) $(BIN_DIR) $(DLL) $(PROG)

#Regles
$(PROG): $(OBJECT)
	$(ECHO) "             Edition des liens < $(PROG) >"
	$(CC) -o $@ $(FLAGS)  $+ $(LIB) -L./lib -lboost_regex
	$(ECHO) "<$@> Ok ..."


$(OBJ)/$(STATES)/%.o : $(SRC)/$(STATES)/%.o
$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -c $< $(FLAGS) -o $@ 
	$(ECHO) "<$<> OK .."
	
#$(OBJ)/$(STATES)/%.o : $(SRC)/$(STATES)/%.o
#	$(CC) -c $< $(FLAGS) -o $@ 
#	$(ECHO) "<$<> OK .."


$(DEBUGMAKE):
#	$(ECHO) $(STATECLASS)
#	$(ECHO) $(SOURCE) 
#	$(ECHO) $(OBJECT)
#	$(ECHO) $(HEADER) 

$(OBJ_DIR):
	mkdir -p $(OBJ)/$(STATES)
	
$(BIN_DIR):
	mkdir -p bin
	
$(DLL):
	cp lib/boost_regex.dll bin/

$(CLEAN):
	$(ECHO) "             Nettoyage .."
	rm -f $(OBJECT) $(PROG) $(CREP) corc 

$(OBJ)/$(MAIN).o: $(SRC)/Programme.h $(SRC)/Lexer.h $(SRC)/Automaton.h
$(OBJ)/Affectation.o: $(SRC)/Affectation.h $(SRC)/Declaration.h $(SRC)/DeclarationConst.h $(SRC)/DeclarationVariable.h $(SRC)/Symbol.h $(SRC)/Expression.h
$(OBJ)/DeclarationConst.o: 
$(OBJ)/DeclarationVariable.o: $(SRC)/Declaration.h
$(OBJ)/Ecrire.o : $(SRC)/DeclarationVariable.h $(SRC)/Expression.h $(SRC)/Symbol.h $(SRC)/Instruction.h
$(OBJ)/Expression.o: $(SRC)/Declaration.h $(SRC)/Instruction.h $(SRC)/DeclarationConst.h $(SRC)/DeclarationVariable.h $(SRC)/Symbol.h
$(OBJ)/Lexer.o: $(SRC)/Tokens.h
$(OBJ)/Lire.o: $(SRC)/Instruction.h $(SRC)/Expression.h
$(OBJ)/PartieDeclarative.o: $(SRC)/Declaration.h $(SRC)/Symbol.h
$(OBJ)/PartieInstruction.o: $(SRC)/Instruction.h $(SRC)/Symbol.h
$(OBJ)/Programme.o: $(SRC)/Expression.h $(SRC)/PartieDeclarative.h $(SRC)/PartieInstruction.h $(SRC)/Tokens.h $(SRC)/DeclarationConst.h \
$(SRC)/DeclarationVariable.h $(SRC)/Affectation.h $(SRC)/Ecrire.h $(SRC)/Lire.h $(SRC)/Symbol.h
$(OBJ)/Automaton.o: $(SRC)/$(STATES)/E0.h $(SRC)/State.h $(SRC)/Tokens.h $(SRC)/Lexer.h $(SRC)/Programme.h
$(OBJ)/$(STATES)/E0.o: $(SRC)/State.h $(SRC)/Automaton.h $(SRC)/Tokens.h $(SRC)/$(STATES)/E1.h $(SRC)/State.h $(SRC)/Tokens.h $(SRC)/Automaton.h
$(OBJ)/$(STATES)/E1.o: $(SRC)/State.h $(SRC)/Symbol.h $(SRC)/Automaton.h $(SRC)/State.h $(SRC)/Automaton.h $(SRC)/Tokens.h



