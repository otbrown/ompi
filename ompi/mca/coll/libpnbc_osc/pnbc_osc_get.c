/* -*- Mode: C; c-basic-offset:2 ; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2006      The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2013-2018 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2006      The Technical University of Chemnitz. All
 *                         rights reserved.
 * Copyright (c) 2015      Los Alamos National Security, LLC.  All rights
 *                         reserved.
 * Copyright (c) 2015-2018 Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 *
 * Author(s): Luis Cebamanos <l.cebamanos@epcc.ed.ac.uk>, Daniel Holmes <d.holmes@epcc.ed.ac.uk>
 *
 * Copyright (c) 2012      Oracle and/or its affiliates.  All rights reserved.
 * Copyright (c) 2016      IBM Corporation.  All rights reserved.
 * Copyright (c) 2017      Ian Bradley Morgan and Anthony Skjellum. All
 *                         rights reserved.
 * Copyright (c) 2018      FUJITSU LIMITED.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 */

#include "pnbc_osc_internal.h"
#include "ompi/mca/coll/base/coll_tags.h"
#include "ompi/op/op.h"
#include "ompi/mca/pml/pml.h"
#include "ompi/mca/osc/osc.h"


static int nbc_try_get(void *origin_addr, int origin_count,  MPI_Datatype origin_datatype,
                       int target_rank, int assert, MPI_Aint target_disp, int target_count,
                       MPI_Datatype target_datatype, int lock_type, ompi_win_t *win){
  
  int ret;
  /* [state is unlocked] */
  //TODO: Maybe some checking?
  ret = win->w_osc_module->osc_try_lock(lock_type, target_rank, assert, win);
  /* we get the lock */
  if(OMPI_SUCCESS == ret){
    win->w_osc_module->osc_get(origin_addr, origin_count, origin_datatype,
                               target_rank, target_disp, target_count,
                               target_datatype, win);
  }else{
    /* return error code */
    return ret;
  }
  
  /* [state is locked] */
  ret = win->w_osc_module->osc_try_unlock(target_rank, win);
  /* return error code or success */
  return ret;
}

static int nbc_try_get_all(void *origin_addr, int origin_count,  MPI_Datatype origin_datatype,
                           int target_rank, int assert, MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, int lock_type, ompi_win_t *win){
  int ret;
}
