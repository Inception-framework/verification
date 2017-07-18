#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xcb"); 
  __asm volatile("mov R10,#0x29"); 
  __asm volatile("ADCS R1, R7, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
