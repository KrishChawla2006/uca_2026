/*
Question:
Matrix Zeores
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in-place.
Example 2:
Input:

matrix = [
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:

[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 31
-2^31 <= matrix[i][j] <= 2^31 - 1
Follow up:
Could you devise a constant space solution?
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    const int r = 3;
    const int c = 4;
    int arr[3][4] ={
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    
    bool firstrow = false;
    bool firstcol = false;

    for(int i=0;i<c;i++){
        if(arr[0][i]==0){
            firstrow=true;
            break;
        }
    }

    for(int i=0;i<r;i++){
        if(arr[i][0]==0){
            firstcol=true;
            break;
        }
    }

    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(arr[i][j]==0){
                arr[0][j]=0;
                arr[i][0]=0;
            }
        }
    }

    for(int i=1;i<c;i++){
        if(arr[0][i]==0){
            for(int j=0;j<r;j++){
                arr[j][i]=0;
            }
        }
    }

    for(int i=0;i<r;i++){
        if(arr[i][0]==0){
            for(int j=0;j<c;j++){
                arr[i][j]=0;
            }
        }
    }

    if(firstrow){
        for(int i=0;i<c;i++){
            arr[0][i]=0;
       }
    }

    if(firstcol){
        for(int i=0;i<r;i++){
            arr[i][0]=0;
       }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
