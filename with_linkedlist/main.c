#include "header.h"
int main(void) {
    Tdbl dbl;
    int i =0;
    int test_size = 10;
    int testData[test_size];
    for(i=0;i < test_size;i++)
      testData[i] = i;
    initialize_dbl(&dbl);
    print_dbl(dbl);
    for(i=0;i < test_size;i++){
      insert_to_dbl_back(&dbl, testData[i]);
    }//end of adding values to list.
    printf("Done: Test data generated\n");
    print_dbl(dbl);
    printf("\n");
    build_xor_values(dbl);
    verify_xor_values(dbl);
}//end of main function
