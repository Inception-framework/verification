#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x56"); 
  __asm volatile("LSR R0, R12, 11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
