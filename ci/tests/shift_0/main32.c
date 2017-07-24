#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x3f"); 
  __asm volatile("LSR R3, R2, 31");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
