#include <stdio.h>
#include <stdarg.h>
int tiny_printf(char *format, ...) {
  va_list pvar;
  va_start(pvar, format);
  for(int i = 0; format[i] != 0; i ++){
    if(format[i]=='%'&&format[i+1]=='d'){
      int arg = va_arg(pvar, int);
      if(arg > 9) {
        perror("to large arg");
        return 1;
      }
      putchar('0'+arg);
      i ++;
      continue;
    }
    putchar(format[i]);
  }
  va_end(pvar);
  return 0;
}


int main(void) {
  tiny_printf("hello: \n");
  tiny_printf("hello: %d\n", 1);
  tiny_printf("hello:%d %d\n",1,2);
}
