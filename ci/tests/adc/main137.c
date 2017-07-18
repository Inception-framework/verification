#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xb5"); 
  __asm volatile("ADCS R11, R4, #0x91");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
