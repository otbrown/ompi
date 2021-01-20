// TODO: copyright info - this was copied from portals4 in this git repo

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
    param = mca_base_var_find("ompi", "osc", "portals4", key);
    if (0 > param) return false;

    ret = mca_base_var_get_value(param, &flag_value, NULL, NULL);
    if (OMPI_SUCCESS != ret) return false;

    if (0 == strcmp(value_string, value)) result = true;

    return result;
}

