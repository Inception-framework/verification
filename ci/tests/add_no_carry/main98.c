#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x4d"); 
  __asm volatile("mov R1,#0xf9"); 
  __asm volatile("ADDS R5, R8, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
