/* Author: Jichao Sun <jichaos@andrew.cmu.edu>
 * Copyright 2014 Jichao Sun
 */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <utility>
#include "shell/driver.h"

using std::cout;
using std::cin;
using std::cerr;
using std::exception;
using std::make_pair;
using std::string;

shell::driver::~driver(){
    delete scanner;
    scanner = nullptr;
    delete parser;
    parser = nullptr;
}

void shell::driver::parse(std::istream& string_in){
    delete scanner;
    scanner = new shell::scanner(&string_in);
    delete parser;
    parser = new shell::parser(*scanner, *this);

    if (parser->parse() != 0){
        // Error message printed each time parse failed
    }
}

void shell::driver::error(const string &err){
    cerr << "Error: " << err << "\n";
}
