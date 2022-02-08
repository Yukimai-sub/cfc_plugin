#ifndef CFC_UTIL_H
#define CFC_UTIL_H

// @return true if cfc is enabled *here*
bool is_cfc_enabled(cgraph_node *func, basic_block bb = nullptr);
// @return true if cfc is enabled for the function
bool is_cfc_enabled(function *func);

#endif
