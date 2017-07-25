#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x21"); 
  __asm volatile("LSR R8, R0, 15");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
