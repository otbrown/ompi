#ifndef PNBC_OSC_ACTION_GET_H
#define PNBC_OSC_ACTION_GET_H

#include "pnbc_osc_trigger_common.h"
#include "ompi/request/request.h"
#include "ompi/win/win.h"

struct get_args_t {
  MPI_Win win;
  void *buf;
  int origin_count;
  MPI_Datatype origin_datatype;
  int target;
  MPI_Aint target_displ;
  int target_count;
  MPI_Datatype target_datatype;
  MPI_Request *request;
};
typedef struct get_args_t get_args_t;

//static enum TRIGGER_ACTION_STATE action_all_get(get_args_t *get_args);
extern trigger_action_all_cb_fn_t action_all_get_p;

//static enum TRIGGER_ACTION_STATE action_one_get(int index, get_args_t *get_args);
extern trigger_action_one_cb_fn_t action_one_get_p;

#endif
