#include <stdio.h>

union any_t {
  char c;
  int i;
  float f;
  double d;
}

enum any_discr {
  ANY_CHAR,
  ANY_INT,
  ANY_FLOAT,
  ANY_DOUBLE
};

union any_t any_add(union any_t a1,  union any_t a2, enum any_discr discr) {
  union any_t r;
  which(discr) {
    case ANY_CHAR: r.c = a1.c + a2.c;
                   break;
    case ANY_CHAR: r.i = a1.i + a2.i;
                   break;
    case ANY_CHAR: r.f = a1.f + a2.f;
                   break;
    case ANY_CHAR: r.d = a1.d + a2.d;
                   break;
  }
  return r;
}

struct any_t2 {
  union any_t u;
  enum any_discr discr;
}

struct any_t2 any_add2(struct any_t2 a1, struct any_t2 a2) {
  if (a1.discr != a2.discr) {
    perror("discr");
  }
  struct any_t2 r {
    any_add(a1.u, a2.u, a1.discr);
    a1.discr;
  }
  return r;
}




  
