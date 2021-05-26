#ifndef WOB_LOGER_H
#define WOB_LOGER_H

#include <iostream>
#include <cstdio>

class Loger
{
private:
    Loger() = default;
    ~Loger() = default;
    static int i;
public:
    static void logi() { std::cout << "LOGER : " << i << std::endl; i++; }
    static void resetLogi() { i = 0; }
	
	static void logv(const Vector2& v, const char* msg) { printf("LOGER : (%.3f,%.3f), %s\n",v.x, v.y, msg); }
    static void logf(const char* format, ...) { printf(format); printf("\n"); }

    template <typename T2>
    static void log(T2 msg) { std::cout << "LOGER : " << msg << std::endl; }
};


#endif