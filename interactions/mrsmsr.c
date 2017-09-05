__attribute__((naked))
void main(void){
  __asm volatile("mrs r1, msp");
  __asm volatile("mov r1, #33");
  __asm volatile("msr msp, r1");
  __asm volatile("bx lr");
}
