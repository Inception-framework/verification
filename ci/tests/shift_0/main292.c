#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x56"); 
  __asm volatile("mov R1,#0x0b"); 
  __asm volatile("LSR R2, R8, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
