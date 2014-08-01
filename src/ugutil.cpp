/*
 * ugutil.cpp
 * Name: Y.Egashira
 * Data 18 SE
 *
 */

#include "../include/ugutil.hpp"

namespace ug {


#ifdef __unix__
int _vscprintf(const char* fmt, va_list ap)
{
	return (vsnprintf(0, 0, fmt, ap));
}
#endif


std::string format(const std::string& fmt, ...)
{
		//  I really want to use the constants as such MAX_PATH, _MAX_PATH,
		// and FILENAME_MAX. However, it's machine- and compiler-dependent.
		static const size_t BUFSIZE = 1024;
        //static char buf[BUFSIZE];
        char buf[BUFSIZE];
        va_list ap;

#ifndef NDEBUG
        va_start(ap, fmt);
        int len = _vscprintf(fmt.c_str(), ap);
        va_end(ap);
        if (len >= BUFSIZE) {
                assert(0);
        }
#endif

        va_start(ap, fmt);
        //vsprintf(buf, fmt, ap);
        vsnprintf(buf, BUFSIZE, fmt.c_str(), ap);
        va_end(ap);


        return std::string(buf);
}


template<typename T> T log2(T x)
{
	static const T inv_ln_2 = T(1.0) / std::log(T(2.0));
	return inv_ln_2 * std::log(x);
}


template float log2<float>(float x);
template double log2<double>(double x);
template long double log2<long double>(long double x);

}

