#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xfe"); 
  __asm volatile("mov R6,#0x03"); 
  __asm volatile("LSR R7, R1, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
