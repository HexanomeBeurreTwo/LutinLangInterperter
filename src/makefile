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
src/States/E1.h \
src/States/E1.cpp 
SOURCE= $(INT:.h=.cpp) src/main.cpp
HEADER= $(INT) src/Instruction.h src/Symbol.h src/Tokens.h src/State.h src/Declaration.h
OBJ=$(patsubst %.cpp,obj/%.o,$(SOURCE)) 
PROG=LUT
LIB=lib\libboost_regex.a
FLAGS=-Wall -fexceptions -std=c++11 -g -Isrc
CLEAN=clean
ECHO=@echo 

#Directive
.PHONY:$(CLEAN) # decrit les regles SANS  dependances


#Dependances
all: $(PROG)

#Regles
$(PROG): $(OBJ)
	$(ECHO) "             Edition des liens < $(PROG) >"
	$(CC) -o $@ $(FLAGS)  $+ $(LIB)


%.o: %.cpp
	$(ECHO) "             Compilation de < $< >"
	$(CC) -c $< -o obj/$@ $(TRACE) $(FLAGS)



$(CLEAN):
	$(ECHO) "             Nettoyage .."
	rm -f $(OBJ) $(PROG) corc 


obj/main.o: src/Programme.h src/Lexer.h src/Automaton.h
obj/Affectation.h:
obj/DeclarationConst.h:
obj/DeclarationVariable.h:
obj/Ecrire.h :
obj/Expression.h:
obj/Lexer.h:
obj/Lire.h:
obj/PartieDeclarative.h:
obj/PartieInstruction.h:
obj/Programme.h:
obj/Automaton.h:
obj/States/E0.h:
obj/States/E1.h:
obj/States/E1.cpp :
	

