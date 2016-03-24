#ifndef PARTIEDECLARATIVE_H
#define PARTIEDECLARATIVE_H

#include "Symbol.h"
#include "Declaration.h"


class PartieDeclarative : public Symbol
{
    public:
        PartieDeclarative(): Symbol(PD){};
        virtual ~PartieDeclarative();
        bool add_declaration(Declaration *inst);
        void print(ostream& os) const ;
        Declrs& get_variables();
        void clone_vars(const PartieDeclarative& src);
		void optimize();
		void check_uninitialized_var();
		void check_unused_vars();

    protected:
        Declrs variables;
    private:
};

#endif // PARTIEDECLARATIVE_H
