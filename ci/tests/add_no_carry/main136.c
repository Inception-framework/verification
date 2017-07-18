#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xd4"); 
  __asm volatile("mov R1,#0x32"); 
  __asm volatile("ADD R1, R1, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
