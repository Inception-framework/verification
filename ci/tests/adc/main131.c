#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xe5"); 
  __asm volatile("mov R9,#0xec"); 
  __asm volatile("ADCS R0, R11, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
