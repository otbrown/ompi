#include <stdarg.h>
#include <stdio.h>

/* the debug level */
#define PNBC_OSC_DLEVEL 10
#define PNBC_OSC_TIMING
#undef PNBC_OSC_TIMING

static inline void PNBC_OSC_DEBUG(int level, const char *fmt, ...) {
#if PNBC_OSC_DLEVEL > 0
    va_list ap;

    if(PNBC_OSC_DLEVEL >= level) {
        //int rank;
        //MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        //printf("[LibPNBC_OSC - %i] ", rank);

        printf(" [LibPNBC_OSC_DEBUG] ");
        va_start(ap, fmt);
        vprintf(fmt, ap);
        va_end (ap);
    }
#endif
}

#ifdef PNBC_OSC_TIMING
extern double Iput_time,Iget_time,Isend_time, Irecv_time, Wait_time, Test_time,Iwfree_time;
static inline void PNBC_OSC_Reset_times(void);
static inline void PNBC_OSC_Print_times(double div);
#endif


