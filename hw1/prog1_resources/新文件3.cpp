void getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
 
    // If element was found
    if (it != v.end())
    {
     
        // calculating the index
        // of K
        int index = it - v.begin();
        cout << index << endl;
    }
    else {
        // If the element is not
        // present in the vector
        cout << "-1" << endl;
    }
}
