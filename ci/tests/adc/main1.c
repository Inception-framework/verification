#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xcf"); 
  __asm volatile("ADCS R8, R7, #0x9b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
