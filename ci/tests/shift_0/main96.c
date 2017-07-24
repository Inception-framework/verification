#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x35"); 
  __asm volatile("LSL R8, R2, 31");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
