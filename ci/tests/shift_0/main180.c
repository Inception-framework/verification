#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xd2"); 
  __asm volatile("LSL R8, R1, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
