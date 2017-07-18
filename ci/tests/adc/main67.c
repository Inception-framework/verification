#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x4f"); 
  __asm volatile("mov R2,#0xc0"); 
  __asm volatile("ADCS R5, R11, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
