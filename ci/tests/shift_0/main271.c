#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xfe"); 
  __asm volatile("mov R1,#0x16"); 
  __asm volatile("LSL R10, R0, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
