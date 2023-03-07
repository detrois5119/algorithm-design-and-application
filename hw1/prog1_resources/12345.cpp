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
vector<vector<int>> sleep2 ;


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
	int i1=getIndex(A,i); 
	int j2=getIndex2(A,j); 
	vector<int> ans;	
	if (j==i){
		ans = {};
		return ans;
	}
	
	else if (i1!=-1&A[abs(i1)][1]==j){
			ans=sleep[i+1][j-1];	
			ans.push_back(i);
			ans.push_back(j);
		    return ans;
	    
	}
	else if(j2!=-1 & A[abs(j2)][0]>i){	
				vector<int> ans2;
				vector<int> ans3;
				vector<int> ans4;
				ans2=sleep[i][j-1];
				ans3=sleep[i][A[j2][0]-1];
				ans4=sleep[A[j2][0]+1][j-1];
		        if(ans2.size()>=ans3.size()+ans4.size()+1){
		    	return ans2;	
				}
				else{
				ans3.insert(ans3.end(), ans4.begin(), ans4.end());
				ans3.push_back(A[j2][0]);
			    ans3.push_back(j);
		    	return ans3;	
		    	}
		    
	}
	else{
		return sleep[i][j-1];
	}		 
    

}

void MISS(vector<vector <int> > A,int i,int j){
	int i1=getIndex(A,i); 
	int j2=getIndex2(A,j);
	if(sleep2[i][j]==-1){
		sleep2[i][j]=1; 	
		if (j==i){}
		
		else if (i1!=-1&A[abs(i1)][1]==j){
			    MISS(A,i+1,j-1);
		    
		}
		else if(j2!=-1 & A[abs(j2)][0]>i){	
				MISS(A,i,j-1);
				MISS(A,i,A[j2][0]-1);
				MISS(A,A[j2][0]+1,j-1);	
			    }
		else{
			MISS(A,i,j-1);
		}
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

    int last_num=Data2D.size()*2-1;

    sleep.resize(last_num+1);
	for(int i=0; i < last_num+1; ++i)
	{
		sleep[i].resize(last_num+1);

	}
	
	sleep2.resize(last_num+1);
	for(int i=0; i < last_num+1; ++i)
	{
		sleep2[i].resize(last_num+1);
		for(int j=0; j < last_num+1; ++j){
			sleep2[i][j]=-1;
//			cout << sleep2[i][j];
		}
//		cout << '\n';
	}
	MISS(Data2D,0,last_num);
//	for(int i=0; i < last_num+1; ++i)
//	{
//		for(int j=0; j < last_num+1; ++j){
////			cout << sleep2[i][j];
//		}
////		cout << '\n';
//	}

    
	int j=0;
	while (j<=last_num){
		for (int i=0;i+j<last_num+1;++i){
			if(sleep2[i][i+j]!=-1)
			sleep[i][i+j]=MIS(Data2D,i,i+j);
		}
		j++;
	}
	int num=last_num;
	cout << num <<"\n";
	cout << sleep[0][num].size()/2 << '\n';
	for (int i=0;i<sleep[0][last_num].size();++i)
	cout << sleep[0][last_num][i] << ' ';
}




