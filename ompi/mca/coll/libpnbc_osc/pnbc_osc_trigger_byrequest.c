#include "ompi/request/request.h"
#include "ompi/request/request_default.h"
#include "pnbc_osc_trigger_common.h"

// some built-in tests resets and actions for 'all' in triggerable_array
// also usable with triggerable_single


int triggered_all_byrequest_flag(FLAG_t *trigger, void *cbstate) {
  ompi_request_t **request = *((ompi_request_t***)cbstate);
  int *flag = (int*)trigger;
  ompi_request_default_test(request, flag, MPI_STATUS_IGNORE);
  if (!flag)
    return ACTION_SUCCESS;
  else
    return TRIGGER_PENDING;
}

int triggered_one_byrequest_flag(FLAG_t *trigger, int index, void *cbstate) {
  ompi_request_t **request = ((ompi_request_t***)cbstate)[index];
  int *flag = (int*)trigger;
  ompi_request_default_test(request, flag, MPI_STATUS_IGNORE);
  if (!flag)
    return ACTION_SUCCESS;
  else
    return TRIGGER_PENDING;
}

