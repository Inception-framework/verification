#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0x60"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xf7"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x18"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x63"); 
  __asm volatile("mov R6,#0"); 
  __asm volatile("add R6,R6,#0x62"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xe3"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x2f"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xee"); 
  __asm volatile("ADCS R7, R11, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
