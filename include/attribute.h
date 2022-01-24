#ifndef CFC_ATTRIBUTE_H
#define CFC_ATTRIBUTE_H
#include <tree.h>
void cfc_attr_init(const char *name);
int get_func_cfc_attr(tree func_decl);
#define CFC_ATTR_ENABLE 1
#define CFC_ATTR_DISABLE 0
#define CFC_ATTR_UNDEFINED -1
#endif
