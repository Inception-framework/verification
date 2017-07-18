#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xb6"); 
  __asm volatile("mov R9,#0x1d"); 
  __asm volatile("ADCS R4, R0, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
