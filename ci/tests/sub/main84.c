#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0"); 
  __asm volatile("add R4,R4,#0x68"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x77"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x7b"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0xab"); 
  __asm volatile("SUB R7, R4, #0xc4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
