#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x6b"); 
  __asm volatile("ADCS R9, R8, #0x35");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
