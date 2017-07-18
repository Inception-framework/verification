#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xcd"); 
  __asm volatile("mov R11,#0x61"); 
  __asm volatile("ADCS R4, R2, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
