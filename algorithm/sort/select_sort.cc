void choiceSort(int arr[], int n){  
	for(int i = 0;i < n; i++){  
		int m = i;  
        for(int j = i + 1;j < n;j++){  
            //如果第j个元素比第m个元素小，将j赋值给m   
			if(arr[j] < arr[m]){  
                m = j;  
            }  
        }  
        //交换m和i两个元素的位置   
		if(i != m){  
            int t = arr[i];  
            arr[i] = arr[m];  
            arr[m] = t;  
		}  
    }  
}  
