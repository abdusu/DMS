#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout<<"after sorting"<<endl;
    for(int i=0; i<n;i++){
	    cout<<arr[i]<<",";
    }
}
int main(){
    int arr[]={10,15,5,20,14};
    bubbleSort(arr,5);
    return 0;
}
