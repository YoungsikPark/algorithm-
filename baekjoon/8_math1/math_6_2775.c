#include <stdio.h>
/*
 이 아파트에 거주를 하려면 조건이 있는데, “a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 
 사람들의 수의 합만큼 사람들을 데려와 살아야 한다” 는 계약 조항을 꼭 지키고 들어와야 한다.
 2층의 2호
 1층의 1호부터 2호까지 사람들의 수의 합  
 아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을 때,
 주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하라. 
 
 단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.

첫 번째 줄에 Test case의 수 T가 주어진다. 그리고 각각의 케이스마다 입력으로 첫 번째 줄에 정수 k, 두 번째 줄에 정수 n이 주어진다

출력
각각의 Test case에 대해서 해당 집에 거주민 수를 출력하라.
*/
 
int main(){

  int arr[15][15] = {0,};  // 아파트의 층은 14보다 작거나 같기때문에 각각 15크기의 2중배열을 선언하고 0으로 초기화.
  int test,h,w,i,j;

  for(i=0; i<15; i++){
    arr[0][i] = i;  // 문제를 보면 0층의 i호에는 i명만큼 산다고해서 0층에는 i명으로 선언.
  }
  
  for(i=1; i<15; i++){
    for(j=1; j<15; j++){
      arr[i][j] = arr[i-1][j] + arr[i][j-1];
    }  // 문제에서 말한 공식대로 밑에층의 1호부터 해당호까지 사람들의 합을 arr[i][j]에 넣어준다.
  }

  scanf("%d",&test); 
  
  for(i=0;i<test;i++){
    scanf("%d %d", &h, &w);  
    printf("%d\n", arr[h][w]);  
  }

	return 0; 
}
