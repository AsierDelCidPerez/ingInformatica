
#include <iostream>
#include <time.h>

using namespace std;

int aleatorio(int a, int b){
    return rand()%(b-a+1) + a;
}

int main(){
    srand(clock());
    int A = 20;
    int B = 30;
    int C = 50;

    printf("{\n");
    for(int i=0;i<A;i++){
        printf("{\n");
        for(int j=0;j<B;j++){
            printf("{");
            for(int k=0;k<C;k++){
                printf("%d, ", aleatorio(-1, 80));
            }
            printf("},\n");
        }
        printf("},\n");
    }
    printf("}\n");
}