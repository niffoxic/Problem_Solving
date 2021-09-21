int maxSumSubarray(int arr[], int n)
{
   int del = 0;
   int ndel = arr[0];
   int res = arr[0];
   for(int i = 1; i < n; i++){
       del = max(del + arr[i], ndel);
       ndel = max(ndel + arr[i], arr[i]);
       res = max(res, max(del, ndel));
   }
   return res;
}
