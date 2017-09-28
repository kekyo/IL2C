#include <stdbool.h>
#include <stdint.h>

int32_t ConditionalBranchMainBody(int32_t a)
{
  bool local0;
  int32_t local1;

  int32_t __stack0_int32_t;
  bool __stack0_bool;
  int32_t __stack1_int32_t;

  __stack0_int32_t = a;
  __stack1_int32_t = 0;
  __stack0_bool = (__stack0_int32_t > __stack1_int32_t) ? true : false;
  local0 = __stack0_bool;
  __stack0_bool = local0;
  if (__stack0_bool == false) goto L_0000;
  __stack0_int32_t = a;
  __stack1_int32_t = 1;
  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
  local1 = __stack0_int32_t;
  goto L_0001;
L_0000:
  __stack0_int32_t = a;
  __stack1_int32_t = 2;
  __stack0_int32_t = __stack0_int32_t + __stack1_int32_t;
  local1 = __stack0_int32_t;
  goto L_0001;
L_0001:
  __stack0_int32_t = local1;
  return __stack0_int32_t;
}
