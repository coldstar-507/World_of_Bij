//
// Created by scott on 4/1/2021.
//

#ifndef WOB_TIMER_H
#define WOB_TIMER_H

#include <ctime>
#include <cstdio>
#include "SDL.h"

constexpr Sint32 CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;

class Timer
{
public:
    Timer() = default;
    explicit Timer(unsigned short p_wantedExecTimeMS) : m_wantedExecTimeMS(p_wantedExecTimeMS), m_timeBank(0) {}
    void SetWantedExecTimeMS(unsigned short p_wantedExecTime) { m_wantedExecTimeMS = p_wantedExecTime; }
    Sint32 GetWantedExecTimeMS() { return m_wantedExecTimeMS; }
    void Start() { m_t = clock(); }
    Sint32 ElapsedTimeMS() { return (clock() - m_t) / CLOCKS_PER_MS; }
    void Delay()
    {
        m_delayedTime = m_wantedExecTimeMS - ElapsedTimeMS();
        m_timeBank = m_timeBank + m_delayedTime + ElapsedTimeMS();
        if (m_delayedTime > 0)
            SDL_Delay(m_delayedTime);
    }
    Sint32 GetTimeBank() const { return m_timeBank; }
    void ResetTimeBank() { m_timeBank = 0; }
    void PrintInfo() { printf("Elapsed time : %d, Wanted time : %d, Delayed time : %d\n", ElapsedTimeMS(), m_wantedExecTimeMS, m_delayedTime); }
private:
    clock_t m_t;
    Sint32 m_wantedExecTimeMS;
    Sint32 m_delayedTime;
    Sint32 m_timeBank;
};



#endif //WOB_TIMER_H
