#Variables
CC=g++
INT=AffectSymb.h 
SOURCE= $(INT:.h=.cpp) Main.cpp
HEADER= TokenSymbol.h Symbol.h Instruction.h 
OBJ=$(patsubst %.cpp,%.o,$(SOURCE)) 
PROG=Prog.out
FLAGS=-Wall
CLEAN=clean
ECHO=@echo 
TRACE= #faire < make TRACE=-DMAP > pour le definir 
EMACS_CACH= *~ \\\#*

#Directive
.PHONY:$(CLEAN) # decrit les regles SANS  dependances


#Dependances
all: $(PROG)
Main.o: AffectSymb.h Main.cpp
AffectSymb.o : AffectSymb.h

#Regles
$(PROG): $(OBJ)
	$(ECHO) "             Edition des liens < $(PROG) >"
	$(CC) -o $@ $(FLAGS)  $+


%.o: %.cpp
	$(ECHO) "             Compilation de < $< >"
	$(CC) -c $< -o $@ $(TRACE) $(FLAGS)



$(CLEAN):
	$(ECHO) "             Nettoyage .."
	rm -f $(OBJ) $(PROG) $(EMACS_CACH) corc 



