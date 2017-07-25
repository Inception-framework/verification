#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x3d"); 
  __asm volatile("LSR R2, R1, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
