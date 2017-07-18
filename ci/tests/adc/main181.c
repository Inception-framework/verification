#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xd4"); 
  __asm volatile("ADCS R2, R11, #0x7f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
