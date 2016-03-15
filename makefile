#Variables
CC=g++
INT=src/Affectation.h \
src/DeclarationConst.h \
src/DeclarationVariable.h \
src/Ecrire.h \
src/Expression.h \
src/Lexer.h \
src/Lire.h \
src/PartieDeclarative.h \
src/PartieInstruction.h \
src/Programme.h \
src/Automaton.h \
src/States/E0.h \
src/States/E1.h
SOURCE= $(INT:.h=.cpp) src/main.cpp
HEADER= $(INT) src/Instruction.h src/Symbol.h src/Tokens.h src/State.h src/Declaration.h
OBJECT=$(patsubst src/%.cpp,obj/%.o,$(SOURCE)) 
PROG=bin\LUT
LIB=lib\libboost_regex.a
FLAGS=-Wall -fexceptions -std=c++11 -Isrc
CLEAN=clean
ECHO=@echo 
OBJ_DIR=obj/States 
BIN_DIR=bin 
DLL=bin/boost_regex.dll

#Directive
.PHONY: $(CLEAN) # decrit les regles SANS  dependances


#Dependances
all: $(OBJ_DIR) $(BIN_DIR) $(DLL) $(PROG)

#Regles
$(PROG): $(OBJECT)
	$(ECHO) "             Edition des liens < $(PROG) >"
	$(CC) -o $@ $(FLAGS)  $+ $(LIB)
	$(ECHO) "< $@  > Ok ..."


obj/%.o: src/%.cpp
	$(ECHO) "             Compilation de < $< >"
	$(CC) -c $< $(FLAGS) -o $@ 

$(OBJ_DIR):
	mkdir -p obj/States
	
$(BIN_DIR):
	mkdir -p bin
	
$(DLL):
	cp lib/boost_regex.dll bin/

$(CLEAN):
	$(ECHO) "             Nettoyage .."
	rm -f $(OBJECT) $(PROG) corc 

obj/main.o: src/Programme.h src/Lexer.h src/Automaton.h
obj/Affectation.o: src/Affectation.h src/Declaration.h src/DeclarationConst.h src/DeclarationVariable.h src/Symbol.h src/Expression.h
obj/DeclarationConst.o: 
obj/DeclarationVariable.o: src/Declaration.h
obj/Ecrire.o : src/DeclarationVariable.h src/Expression.h src/Symbol.h src/Instruction.h
obj/Expression.o: src/Declaration.h src/Instruction.h src/DeclarationConst.h src/DeclarationVariable.h src/Symbol.h
obj/Lexer.o: src/Tokens.h
obj/Lire.o: src/Instruction.h src/Expression.h
obj/PartieDeclarative.o: src/Declaration.h src/Symbol.h
obj/PartieInstruction.o: src/Instruction.h src/Symbol.h
obj/Programme.o: src/Expression.h src/PartieDeclarative.h src/PartieInstruction.h src/Tokens.h src/DeclarationConst.h \
src/DeclarationVariable.h src/Affectation.h src/Ecrire.h src/Lire.h src/Symbol.h
obj/Automaton.o: src/States/E0.h src/State.h src/Tokens.h src/Lexer.h src/Programme.h
obj/States/E1.o: src/State.h src/Symbol.h src/Automaton.h src/State.h src/Automaton.h src/Tokens.h
obj/States/E0.o: src/State.h src/Automaton.h src/Tokens.h src/States/E1.h src/State.h src/Tokens.h src/Automaton.h
	

