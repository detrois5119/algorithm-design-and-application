#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
//int iii=0;
vector<vector<vector<int>>> sleep;


int getIndex(vector<std::vector<int> > v,int K){
    for (int i=0;i<v.size();++i){
		if (v[i][0] == K){
			return i;
		}
	}
	return -1;
}

int getIndex2(vector<std::vector<int> > v,int K){
    for (int i=0;i<v.size();++i){
		if (v[i][1] == K){
			return i;
		}
		
	}
    return -1;
}

vector<int> MIS(vector<vector<int> > A,int i,int j){
//	cout << i << " " << j << "\n";
	int i1=getIndex(A,i); 
//	int j1=getIndex(A,j);
	int j2=getIndex2(A,j); 
	vector<int> ans;
	vector<int> ans1;	
	if (j==i){
		ans = {};
		return ans;
	}
	
	else if (i1!=-1&A[abs(i1)][1]==j){
			ans.push_back(i);
			ans.push_back(j);
			ans1=sleep[i+1][j-1];
			ans.insert(ans.end(), ans1.begin(), ans1.end());
		    return ans;
	    
	}
	else if(j2!=-1 & A[abs(j2)][0]>i){	
				vector<int> ans2;
				vector<int> ans3;
				vector<int> ans4;
				ans2=sleep[i][j-1];
				ans3=sleep[i][A[j2][0]-1];
				ans4=sleep[A[j2][0]+1][j-1];
				ans3.insert(ans3.end(), ans4.begin(), ans4.end());
		        if(ans2.size()>=ans3.size()+1){
				ans.insert(ans.end(), ans2.begin(), ans2.end());
		    	return ans;	
				}
				else{
				ans.push_back(A[j2][0]);
			    ans.push_back(j);
				ans.insert(ans.end(), ans3.begin(), ans3.end());
		    	return ans;	
		    	}
		    
	}
	else{
		ans1=sleep[i][j-1];
		ans.insert(ans.end(), ans1.begin(), ans1.end());
		return ans;
	}		 
    

}
	

int main(int argc, char **argv)
{
	vector<int> aans;
    ifstream in(argv[1]);
    string strLine;
    vector<std::vector<int> > Data2D;
    while (getline(in, strLine))
    {
    	if (strLine.find(" ")!= std::string::npos){
	        stringstream ss(strLine);
	        vector<int> row;
	        int data;
	        while (ss >> data)
	        {

	            row.push_back(data);
	            sort(row.begin(), row.end());
	            
	        }

	        Data2D.push_back(row);
	    }
    }
    sort(Data2D.begin(),Data2D.end());
//    cout << Data2D.size();
    int last_num=Data2D.size()*2-1;

    sleep.resize(last_num+1);
	for(int i=0; i < last_num+1; ++i)
	{
		sleep[i].resize(last_num+1);

	}

    
	int j=0;
	while (j<=last_num){
		for (int i=0;i+j<last_num+1;++i){
			sleep[i][i+j]=MIS(Data2D,i,i+j);
		}
		j++;
	}
	int num=last_num;
	cout << num <<"\n";
	cout << sleep[0][num].size()/2 << '\n';
	for (int i;i<sleep[0][num].size();++i)
	cout << sleep[0][num][i] << ' ';
//	vector<std::vector<int> > ans;

	

//	cout << Data2D.size();
//	cout << getIndex(Data2D);
//	, 5
}




