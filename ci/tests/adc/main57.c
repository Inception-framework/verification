#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x6a"); 
  __asm volatile("ADCS R8, R2, #0xc0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
