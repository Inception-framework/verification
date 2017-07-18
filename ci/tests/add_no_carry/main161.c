#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xbe"); 
  __asm volatile("mov R4,#0xf1"); 
  __asm volatile("ADD R7, R3, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
