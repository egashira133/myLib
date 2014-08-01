/*
 * ugutil.hpp: file header
 * Name: Y.Egashira
 * Data 18 SE
 *
 */


#ifndef UGUTIL_HPP
#define UGUTIL_HPP


#include <cstdio>
#include <iostream>
#include <string>
#include <stdarg.h>
#include <assert.h>
#include <cmath>

namespace ug {


#define debug(n) std::cerr<<"#"<<#n<<"= "<<(n)<<" (L"<<__LINE<<") "<<__FILE__<<std::endl


std::string format(const std::string& fmt, ...);

// log2(x) : Returns the binary (base-2) lo9garithm of x.
template<typename T> T log2(T x);

}

#endif	// for UGUTIL_HPP
