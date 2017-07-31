#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0"); 
  __asm volatile("add R2,R2,#0xfc"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0xa0"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x55"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x36"); 
  __asm volatile("SUB R11, R2, #0xcd");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
