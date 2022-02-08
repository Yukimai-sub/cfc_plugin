// CUSTOM0: CTRLSIG_S/M
// 31302928272625242322212019181716151413121110 9 8 7 6 5 4 3 2 1 0
// +- - - - - - - -+- - - - - - - -+- - - - - - - -+-+- - - - - - -+
// | imm8 (d)      |   imm8 (S)    |   imm8 (D)    |C|   CUSTOM0   |
// +- - - - - - -+- - - - -+- - - - -+- - -+- - - - -+- - - - - - -+
// |  funct7     |  rs2    |  rs1    | f3  |   rd    |   CUSTOM0   |
// +---------------------------------------------------------------+ 
// C: 0-S 1-M

#include <cstdio>
#include <gcc-plugin.h>
#include <tree.h>
#include <cgraph.h>
#include "attribute.h"
#include "cmd-arg.h"



bool is_cfc_enabled(cgraph_node *func, basic_block bb)
{
  int attr = get_func_cfc_attr(func->get_fun()->decl);
  return cmd_cfc_enabled ? attr != CFC_ATTR_DISABLE : attr == CFC_ATTR_ENABLE;
}

bool is_cfc_enabled(function *func)
{
  int attr = get_func_cfc_attr(func->decl);
  return cmd_cfc_enabled ? attr != CFC_ATTR_DISABLE : attr == CFC_ATTR_ENABLE;
}
