#include <termios.h>
#include <unistd.h>
int main (void) {
  struct termios t;
  struct termios *tp = &t;
  tcgetattr (STDIN_FILENO, tp);
  return 0;
}

  
