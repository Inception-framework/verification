#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0"); 
  __asm volatile("add R5,R5,#0x23"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x47"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xb2"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x4f"); 
  __asm volatile("SUB R7, R5, #0x3f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
