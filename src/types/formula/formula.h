/* Author: Jichao Sun <jichaos@andrew.cmu.edu>
 * Copyright 2014 Jichao Sun
 */

#pragma once
#include <string>
#include "types/formula/term.h"

namespace shell{

enum class formula_kind { Predicate, Equality, Negation, Connective, Quantifier, Custom };

/* Abstract base class for formulas */
class fmla_cell {
protected:
    formula_kind    m_kind;
public:
    virtual bool val() const =0;
    formula_kind kind() const { return m_kind; }
    virtual ~fmla_cell() { }
};

/* Forward declare enums for term interface*/
enum class equality_op;
enum class cnct_type;
enum class quant_type;

class fmla {
private:
    fmla_cell*      m_ptr;
public:
    // ~fmla() { delete m_ptr; }
    bool val() const { return m_ptr->val(); }
    bool is_empty() const { return m_ptr == NULL; }

    friend fmla mk_fmla(fmla_cell *ptr);
};

fmla fmla_lookup(const std::string &name);
fmla mk_fmla_eq(equality_op const op, const term lhs, const term rhs);
fmla mk_fmla_cnct(cnct_type const op, const fmla lhs, const fmla rhs);
fmla mk_fmla_neg(const fmla f1);
fmla mk_fmla_quant(quant_type const op, const std::string &name, const fmla formula);
void set_fmla(const std::string &name);
void set_fmla(const std::string &name, const fmla formula);
}
