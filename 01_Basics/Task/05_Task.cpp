#include <iostream>
#include <cstdio>
using namespace std;

int main(){

    int n;
    int arr[n] = {};

    printf("Enter Number of students : ");
    scanf("%d",&n);
    for(int i = 0; i <=n; i++){
        printf("Enter %d element : ",i);
        scanf("%d",&arr[i]);
    }

    int sum = 0;
    int avg;
    int len = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<len; i++){
        sum = sum + arr[1];
    }
    avg = sum/len;

    for(int i = 0; i<len; i++){
        if(arr[i] >= avg){
            printf("Greter then and equal to avg : %d\n", arr[i]);
        }
    }

    printf("Avg:  %.2f",avg);


    return 0;
}