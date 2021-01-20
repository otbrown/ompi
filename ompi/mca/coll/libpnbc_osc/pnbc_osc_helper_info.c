/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2011-2017 Sandia National Laboratories.  All rights reserved.
 * Copyright (c) 2015-2018 Los Alamos National Security, LLC.  All rights
 *                         reserved.
 * Copyright (c) 2015-2017 Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 * Copyright (c) 2017      The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2016-2017 IBM Corporation. All rights reserved.
 * Copyright (c) 2018      Amazon.com, Inc. or its affiliates.  All Rights reserved.
 * Copyright (c) 2020      EPCC, The University of Edinburgh. All rights
 *                         reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * Author(s): Daniel Holmes  EPCC, The University of Edinburgh
 *
 * $HEADER$
*/

#include "pnbc_osc_internal.h"
#include "pnbc_osc_helper_info.h"

bool check_config_value_equal(char *key, ompi_info_t *info, char *value) {
    char *value_string;
    int value_len, ret, flag, param;
    const bool *flag_value;
    bool result = false;

    ret = ompi_info_get_valuelen(info, key, &value_len, &flag);
    if (OMPI_SUCCESS != ret) goto info_not_found;
    if (flag == 0) goto info_not_found;
    value_len++;

    value_string = (char*)malloc(sizeof(char) * value_len + 1); /* Should malloc 1 char for NUL-termination */
    if (NULL == value_string) goto info_not_found;

    ret = ompi_info_get(info, key, value_len, value_string, &flag);
    if (OMPI_SUCCESS != ret) {
        free(value_string);
        goto info_not_found;
    }
    assert(flag != 0);
    if (0 == strcmp(value_string, value)) result = true;
    free(value_string);
    return result;

 info_not_found:
    param = mca_base_var_find("ompi", "coll", "libpnbcs_osc", key);
    if (0 > param) return false;

    ret = mca_base_var_get_value(param, &flag_value, NULL, NULL);
    if (OMPI_SUCCESS != ret) return false;

    if (0 == strcmp(value_string, value)) result = true;

    return result;
}

