#include <gcc-plugin.h>
#include <tree.h>
#include <tree-pass.h>
#include <stdio.h>
#include <stringpool.h>
#include <attribs.h>
#include "attribute.h"

static tree attr_handler(tree *node, tree name, tree args, int flags, bool *no_add_attrs) {
    // will never be called
    return NULL_TREE;
}

int get_func_cfc_attr(tree func_decl)
{
    tree a = lookup_attribute("cfcheck", DECL_ATTRIBUTES(func_decl));
    if(a == NULL_TREE) return CFC_ATTR_UNDEFINED;
    a = TREE_VALUE(a);
    //fprintf(stderr, "found cfc attribute on function %s\n", DECL_NAME(func_decl)->identifier.id.str);
    if(a && TREE_CODE(TREE_VALUE(a)) != VOID_TYPE)
    {
        // enable if arg is a true-y value
        if(TREE_INT_CST_ELT(TREE_VALUE(a), 0))
            return CFC_ATTR_ENABLE;
        else 
            return CFC_ATTR_DISABLE;
    }else
    {
        //fprintf(stderr, "Enable by default\n");
        return CFC_ATTR_ENABLE;
    }
}

static attribute_spec attr_cfc = { "cfcheck", 0, 1, false,  false, false, attr_handler };

static void register_attr(void *event_data, void *data) {
    register_attribute(&attr_cfc);
}

void cfc_attr_init(const char *name)
{
    register_callback(
        name,
        PLUGIN_ATTRIBUTES,
        register_attr,
        nullptr
    );
}
