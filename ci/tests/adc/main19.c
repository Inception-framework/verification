#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xb6"); 
  __asm volatile("mov R1,#0xa6"); 
  __asm volatile("ADCS R7, R10, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
