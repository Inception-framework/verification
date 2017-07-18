#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x70"); 
  __asm volatile("mov R4,#0x55"); 
  __asm volatile("ADD R1, R5, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
