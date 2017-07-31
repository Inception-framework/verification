#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0"); 
  __asm volatile("add R5,R5,#0x4c"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x9a"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x0a"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xe1"); 
  __asm volatile("SUB R6, R5, #0x37");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
