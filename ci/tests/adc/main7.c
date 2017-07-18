#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x1f"); 
  __asm volatile("mov R12,#0x07"); 
  __asm volatile("ADCS R8, R4, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
