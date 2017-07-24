#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x12"); 
  __asm volatile("mov R8,#0x1b"); 
  __asm volatile("LSR R5, R7, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
