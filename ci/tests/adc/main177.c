#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x70"); 
  __asm volatile("ADCS R3, R7, #0x41");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
