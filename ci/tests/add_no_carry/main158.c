#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xe3"); 
  __asm volatile("mov R10,#0xbd"); 
  __asm volatile("ADDS R1, R3, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
