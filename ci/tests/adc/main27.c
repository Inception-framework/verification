#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x3f"); 
  __asm volatile("mov R7,#0x6b"); 
  __asm volatile("ADCS R2, R11, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
