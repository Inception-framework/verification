#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xe7"); 
  __asm volatile("ADCS R11, R0, #0x67");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
