#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x1a"); 
  __asm volatile("mov R2,#0xb3"); 
  __asm volatile("ADCS R0, R0, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
