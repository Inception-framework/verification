#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x20"); 
  __asm volatile("mov R4,#0x0a"); 
  __asm volatile("LSL R2, R7, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
