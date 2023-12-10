#include <stdio.h>

struct extended_euclidian_result {
  int gcd;
  int x;
  int y;
};

typedef struct extended_euclidian_result gcd_and_quotients;

gcd_and_quotients extended_euclidian (int a, int b, gcd_and_quotients *recursion_context);

int main (int argc, char *argv[]) {
  int a, b;

  scanf("%d %d", &a, &b);

  gcd_and_quotients recursion_context;
  gcd_and_quotients res = extended_euclidian(a, b, &recursion_context);

  printf("%d ", res.gcd);

  if (res.gcd != 1) printf("N\n");
  else {
    int mult_inverse = 0;

    if (res.x < 0) mult_inverse = (res.x % b + b) % b;
    else mult_inverse = res.x;

    printf("%d\n", mult_inverse);
  }

  return 0;
}

gcd_and_quotients extended_euclidian (int a, int b, gcd_and_quotients *recursion_context) {  
  if (a == 0) {
    recursion_context->gcd = b;
    recursion_context->x = 0;
    recursion_context->y = 1;

    return *recursion_context;
  }

  gcd_and_quotients prev = extended_euclidian(b % a, a, recursion_context);

  recursion_context->x = prev.y - (b / a) * prev.x;
  recursion_context->y = prev.x;

  return *recursion_context;
}