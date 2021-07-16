/*You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two elements. Find the minimum number of swaps required to sort the array in ascending order.
 Solution
 */
void swap(vector<int>& arr,int i,int j)
{
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    vector<int> temp(arr.begin(),arr.end());
    sort(temp.begin(),temp.end());
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=i;
    }
    int swaps = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=temp[i])
        {
            swaps++;
            int index = arr[i];
            swap(arr,i,mp[temp[i]]);
            mp[index]=mp[temp[i]];
            mp[temp[i]]=i;
        }
    }
    return swaps;
}
