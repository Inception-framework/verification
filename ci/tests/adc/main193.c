#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x70"); 
  __asm volatile("ADCS R4, R0, #0x53");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
