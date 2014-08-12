/* Author: Jichao Sun <jichaos@andrew.cmu.edu>
 * Copyright 2014 Jichao Sun
 */

#pragma once
#include <string>
#include <vector>
#include "types/formula/term.h"

namespace shell{

/* Function class for unary and binary operations */
enum class func_op { Add, Sub, Mult, Div, Neg, Pow };

class term_func : public term_cell {
private:
    func_op             m_op;
    std::vector<term>   m_trm;

public:
    term_func(const func_op op, term t1);
    term_func(const func_op op, term t1, term t2);
    term_func(const func_op op, term t1, term t2, term t3);
    ~term_func();
    double val() const;
    func_op op() const { return m_op; }
};
}
