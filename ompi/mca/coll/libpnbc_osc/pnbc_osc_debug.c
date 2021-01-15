#include "pnbc_osc_debug.h"

#ifdef PNBC_OSC_TIMING

double Iput_time=0,Iget_time=0,Isend_time=0, Irecv_time=0, Wait_time=0, Test_time=0;

void PNBC_OSC_Reset_times() {
  Iwfree_time=Iput_time=Iget_time=Isend_time=Irecv_time=Wait_time=Test_time=0;
}

void PNBC_OSC_Print_times(double div) {
  printf("*** PNBC_OSC_TIMES: Isend: %lf, Irecv: %lf, Wait: %lf, Test: %lf\n",
         Isend_time*1e6/div, Irecv_time*1e6/div,
         Wait_time*1e6/div, Test_time*1e6/div);
}

#endif
