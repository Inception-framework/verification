#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x42"); 
  __asm volatile("ADCS R6, R8, #0x96");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
