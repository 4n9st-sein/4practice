#include <stdio.h>

typedef enum {
  TYPE_INT,
  TYPE_FUNCTION,
  TYPE_POINTER,
} TYPE;
struct c_type;
struct u_type;
struct function;
struct a_value;
struct pointer;

struct c_type {
 TYPE value;
 union u_type type;
}
union u_type {
  int i;
  struct function *f;
  struct pointer *p;
}
struct funtction {
  struct c_type *r_type;
  struct a_value *a_val;
}
struct a_value {
  struct c_type *a_type;
  struct a_val *n_arg;
}

struct pointer {
  struct c_type *base_type;
  void *p;
}

