/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2004-2007 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2013 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2008      Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2013-2015 Los Alamos National Security, LLC. All rights
 *                         reserved.
 * Copyright (c) 2014-2017 Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 * Copyright (c) 2016-2017 IBM Corporation.  All rights reserved.
 * Copyright (c) 2018      FUJITSU LIMITED.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef MCA_COLL_LIBPNBC_OSC_EXPORT_H
#define MCA_COLL_LIBPNBC_OSC_EXPORT_H

#include "ompi/mca/coll/coll.h"
#include "opal/sys/atomic.h"
#include "ompi/request/request.h"

BEGIN_C_DECLS

/*********************** LibPNBC_OSC tuning parameters ************************/


/********************* end of LibPNBC_OSC tuning parameters ************************/

struct ompi_coll_libpnbc_osc_component_t {
    mca_coll_base_component_2_0_0_t super;
    opal_free_list_t requests;
    opal_list_t active_requests;
    opal_atomic_int32_t active_comms;
    opal_mutex_t lock;                /* protect access to the active_requests list */
};
typedef struct ompi_coll_libpnbc_osc_component_t ompi_coll_libpnbc_osc_component_t;
OMPI_MODULE_DECLSPEC extern ompi_coll_libpnbc_osc_component_t mca_coll_libpnbc_osc_component;

struct ompi_coll_libpnbc_osc_module_t {
    mca_coll_base_module_t super;
    opal_mutex_t mutex;
    bool comm_registered;
};
typedef struct ompi_coll_libpnbc_osc_module_t ompi_coll_libpnbc_osc_module_t;
OBJ_CLASS_DECLARATION(ompi_coll_libpnbc_osc_module_t);

int ompi_coll_libpnbc_osc_progress(void);

int ompi_coll_libpnbc_osc_alltoallv_init(const void* sendbuf, const int *sendcounts, const int *sdispls,
                        MPI_Datatype sendtype, void* recvbuf, const int *recvcounts, const int *rdispls,
                        MPI_Datatype recvtype, struct ompi_communicator_t *comm, struct ompi_info_t *,
                        ompi_request_t ** request, struct mca_coll_base_module_2_3_0_t *module);


END_C_DECLS

#endif /* MCA_COLL_LIBPNBC_OSC_EXPORT_H */
