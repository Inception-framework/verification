void bubble_sort(int* a, int size){
  int i,j,tmp;
  __asm volatile("mov r0,r0");
  for(i=0;i<size;i++){
   for(j=i;j<size;j++){
     if(a[i] > a[j]){
       tmp = a[i];
       a[i] = a[j];
       a[j] = tmp;
     }
   }
  }
}

void sort_golden(int* a, int size){
  int i,j,tmp;
  //__asm volatile("mov r0,r0");
  for(i=0;i<size;i++){
   for(j=i;j<size;j++){
     if(a[i] > a[j]){
       tmp = a[i];
       a[i] = a[j];
       a[j] = tmp;
     }
   }
  }
}

void main(void){
  int array[6] = {1,5,2,7,4,2};
  int array_golden[6] = {1,5,2,7,4,2};
  
  bubble_sort(array,6);
  sort_golden(array_golden,6);

  #ifndef NOPRINT
  int i;
  int error = 0;
  printf("array       : ");
  for(i=0;i<6;i++){
    printf("%d ",array[i]);
    if(array[i]!=array_golden[i]){
       error = 1;
    }
  }
  printf("\n");
  printf("array_golden: ");
  for(i=0;i<6;i++){
    printf("%d ",array_golden[i]);
  }
  printf("\n");
 
  if(error){
    printf("error!! array != array_golden\n");
  }else{
    printf("ok!! array == array_golden\n");
  } 
  
  #endif 
}
