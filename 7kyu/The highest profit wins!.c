void min_max (const int arr[/* count */], int count, int *min, int *max)
{
// assign to the min and max pointers
    *min = arr[0];
    *max = arr[0]; 
    for(int i = 1; i< count ; i++)
    {
      if(arr[i] > *max)
      {
        *max = arr[i];
      }
      
      if(arr[i] < *min)
      {
        *min = arr[i];
      }
      
    }

}
