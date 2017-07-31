#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0"); 
  __asm volatile("add R2,R2,#0xc4"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x84"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x1a"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x8d"); 
  __asm volatile("SUB R6, R2, #0xdd0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
