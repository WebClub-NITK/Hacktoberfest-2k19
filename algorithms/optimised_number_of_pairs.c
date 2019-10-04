int pairs(int arr[],int num)
{	int count=0;
	for(int i=0;arr[i]!='\0';++i)
	for(int j=0;arr[j]!='\0';++j)
		if(arr[i]+arr[j]==num)
			++count;
	return count;
}
