#include <gcc-plugin.h>
#include <diagnostic-core.h>
#include <intl.h>
#include <cstring>


#define ARG_ENABLE_CFC "enable-cfc"
#define ARG_DISABLE_CFC "disable-cfc"

// default to enabled for backward compatible
bool cmd_cfc_enabled = true;

void cfc_cmd_arg_init(plugin_name_args *info) {
    const int argc = info->argc;
    auto argv = info->argv;
    bool arg_contains_enable_cfc = false, arg_contains_disable_cfc = false;
    for(int i = 0; i < argc; ++i)
        if(!strcmp(argv[i].key, ARG_ENABLE_CFC))
            arg_contains_enable_cfc = true;
        else if(!strcmp(argv[i].key, ARG_DISABLE_CFC))
            arg_contains_disable_cfc = true;
    if(arg_contains_disable_cfc)
    {
        if(arg_contains_enable_cfc)
            warning(0, "-fplugin-args-%s-enable-cfc and -fplugin-args-%s-disable-cfc provided at the same time. Ignoring the latter.", info->base_name, info->base_name);
        else cmd_cfc_enabled = false;
    }
    warning(0, "Loaded plugin: %s", info->base_name);
}
