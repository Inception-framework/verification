#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xa6"); 
  __asm volatile("ADCS R3, R11, #0x20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
