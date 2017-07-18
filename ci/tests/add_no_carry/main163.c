#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x4e"); 
  __asm volatile("mov R12,#0xe4"); 
  __asm volatile("ADDS R1, R8, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
