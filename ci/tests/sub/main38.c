#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0"); 
  __asm volatile("add R6,R6,#0x14"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xaa"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x45"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x1c"); 
  __asm volatile("SUB R11, R6, #0x627");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
