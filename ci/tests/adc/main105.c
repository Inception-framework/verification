#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x2b"); 
  __asm volatile("ADCS R9, R6, #0x35");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
