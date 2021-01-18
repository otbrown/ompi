#ifndef PNBC_OSC_ACTION_COMMON_H
#define PNBC_OSC_ACTION_COMMON_H

#include "pnbc_osc_action_decrement.h"
#include "pnbc_osc_action_get.h"
#include "pnbc_osc_action_put.h"

union any_args_t {
  dec_args_t dec_args;
  get_args_t get_args;
  put_args_t put_args;
};
typedef union any_args_t any_args_t;

#endif
