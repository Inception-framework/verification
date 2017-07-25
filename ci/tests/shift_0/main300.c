#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xae"); 
  __asm volatile("mov R0,#0x1f"); 
  __asm volatile("LSR R7, R2, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
