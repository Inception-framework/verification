#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x3d"); 
  __asm volatile("ADCS R10, R3, #0xc8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
