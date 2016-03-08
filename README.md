Lutin Language Interperter
===========================

LutinLangInterperter is an interpreter for a basic homemade language named lutin.
This interpreter is focused on code analysis, simplification and errors handling.

Lutin code example:
-------------------
```
var x ;
const n=10, n2=1000 ;
ecrire n+n2;
x := n+n2;
ecrire x+2 ;
lire x ;
ecrire x;
```

Installation
------------

```
git clone git@github.com:HexanomeBeurreTwo/LutinLangInterperter.git
cd LutinLangInterperter
make
make test # test your code
```

How to run
----------

```
//Running code
  -o # Optimizing code
  -p # Print transformed code
  -a # Basic analysis
  -e # Execution
```

Language expressions
--------------------

 + `var x` : variable declaration //initialization is not possible
 + `const n=10` : constant declaration and affectation //affectation is needed
 + `x := n+2` : affect a value to a variable
 + `ecrire x+n` : write on the standard output the value of the expression
 + `read x` : Read standard input stream and affects it to a variable

Terminal symbols
-------

 + `var` : var
 + `const` : const
 + `affect` : :=
 + `equal` : =
 + `sep` : ,
 + `write` : ecrire
 + `read` : lire
 + `end` : ;
 + `id` : id is a composed by alphanumerical character starting with a letter, case sensitive
 + `val` : numerical value


Non terminal symbols
------

 + `P` : Program
 + `PD` : DeclarationBlock
 + `LD` : Declaration line (const or var), recursive
 + `LV` : List of variable ids, recursive
 + `LC` : List of constant declaration, recursive
 + `D` : Constant declaration
 + `PI` : List of instructions, recursive
 + `LI` : Instruction command (affect, read, write)
 + `E` : Operation expression (+ - * /) or value, recursive

Grammar Rules
-------

 + 1: `P -> PD PI`
 + 2: `PD -> PD LD end`
 + 3: `PD -> ε`
 + 4: `LD -> var LV`
 + 5: `LD -> const LC`
 + 6: `PI -> PI LI end`
 + 7: `PI -> ε`
 + 8: `LI -> id affect E`
 + 9: `LI -> write E`
 + 10: `LI -> read id`
 + 11: `LV -> LV sep id`
 + 12: `LV -> id`
 + 13: `LC -> LC sep D`
 + 14: `LC -> D`
 + 15: `D -> id equal val`
 + 16: `E -> E + E`
 + 17: `E -> E - E`
 + 18: `E -> E / E`
 + 19: `E -> E * E`
 + 20: `E -> ( E )`
 + 21: `E -> id`
 + 22: `E -> val`
