#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x38"); 
  __asm volatile("LSR R3, R11, 31");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
