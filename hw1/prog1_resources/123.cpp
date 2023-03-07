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

int MISS(int i,int j){
	
}

vector<int> MIS(vector<vector<int> > A,int i,int j){
	if(sleep[i][j].size()>0){
		
	}
	else{
	//	cout << 777777 <<'\n';
		int i1=getIndex(A,i);
		int j1=getIndex(A,j);
		int j2=getIndex2(A,j);
	//	cout << i <<'\n';
	//	cout << j <<'\n';
	//	cout << i1 <<'\n';
	//	cout << j1 <<'\n';
	//	cout << j2 <<'\n';
		vector<int> ans;
		vector<int> ans1;	
		if (i-j==0 || j<0){
	//	    cout << 88888888 <<'\n';
			ans = {};
			return ans;
		}
		
		else if (i1!=-1&A[abs(i1)][1]==j){
	//		cout << 3333333 <<'\n';
			ans.push_back(i);
			ans.push_back(j);
			ans1=MIS(A,i+1,j-1);
			ans.insert(ans.end(), ans1.begin(), ans1.end());
		    return ans;
		}
		else{
			if (j-i==1){
	//	    cout << 88888888 <<'\n';
			ans = {};
			return ans;
			}
			else if(j1!=-1){
	//			cout << 111111 << '\n';
				ans1=MIS(A,i,j-1);
				ans.insert(ans.end(), ans1.begin(), ans1.end());
				return ans;
			}
			else{
				if (A[j2][0]<i){
	//				cout << 88888888 <<'\n';
					ans = {};
					return ans;	
				}
	//			cout << 222222 << '\n';
				vector<int> ans2;
				vector<int> ans3;
				vector<int> ans4;
				ans2=MIS(A,i,j-1);
				ans3=MIS(A,i,A[j2][0]-1);
				ans4=MIS(A,A[j2][0]+1,j-1);
				ans3.insert(ans3.end(), ans4.begin(), ans4.end());
		        if(ans2.size()>=ans3.size()+1){
	//	        cout << 2323232323 <<'\n';
				ans.insert(ans.end(), ans2.begin(), ans2.end());
		    	return ans;	
				}
				else{
	//			cout << 242424242424 <<'\n'	;
				ans.push_back(A[j2][0]);
			    ans.push_back(j);
				ans.insert(ans.end(), ans3.begin(), ans3.end());
		    	return ans;	
				}		 
			}	
	    }
	}
}
	

int main(int argc, char **argv)
{
	if(argc != 3)
    {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
    //    system("pause");
        exit(1);
    }
    
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

    int last_num=Data2D[Data2D.size()-1][0];
    
    sleep.resize(1000);
	for(int i=0; i < 1000; ++i)
	{
		sleep[i].resize(1000);
		for(int j=0;j<1000;++j){
			sleep[i][j].resize(1000);
		}
	}

//    aans=MIS(Data2D,0,last_num);
//    for(int i=0;i<aans.size();++i)
//    cout << aans[i];
//    cout << '\n' << aans.size()/2;
    
    
	int j=0;
	while (j<=last_num){
		for (int i=0;i+j<last_num;++i){
			sleep[i][i+j]=MIS(Data2D,i,i+j);
		}
		j++;
	}

//	cout << Data2D.size();
//	cout << getIndex(Data2D);
//	, 5
}




