#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("add r1,r1,#1025");
  __asm volatile("mov r2,sp");
  __asm volatile("loop:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("add r2,#1025");
  __asm volatile("lsl r2,#2");
  __asm volatile("add r2,sp");
  __asm volatile("loop2:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop2");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("mov R0,sp"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0x29"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x04"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xcd"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xef"); 
  __asm volatile("mov R9,#0"); 
  __asm volatile("add R9,R9,#0x53"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xe8"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xeb"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x43"); 
  __asm volatile("mov R4,#0"); 
  __asm volatile("add R4,R4,#0x0b"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x68"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x0c"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x1c"); 
  __asm volatile("mov R5,#0"); 
  __asm volatile("add R5,R5,#0x9a"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x6a"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xb3"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x29"); 
  __asm volatile("mov R7,#0"); 
  __asm volatile("add R7,R7,#0x00"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x00"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x00"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x91"); 
  __asm volatile("LDRH R9, [R0 ,#20]!");
  #ifndef KLEE
  __asm volatile("stop: b stop");
  #else
  __asm volatile("bx lr");
  #endif
}
