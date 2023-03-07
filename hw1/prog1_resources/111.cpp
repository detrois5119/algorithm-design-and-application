#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
//int iii=0;
int getIndex(vector<std::vector<int> > v,int K){
    for (int i=0;i<v.size();++i){
		if (v[i][0] == K){
			return i;
		}
	}
}

int getIndex2(vector<std::vector<int> > v,int K){
    for (int i=0;i<v.size();++i){
		if (v[i][1] == K){
			return i;
		}
	}
}

vector<vector<int>> Return2DVector(vector<int> x, vector<int> z){
	vector < vector<int> > sleep;
	sleep.resize(x.size());
	for(int i=0; i < x.size(); ++i)
	{
		sleep[i].resize(2);
	} 
	for(int i=0; i < x.size(); ++i)
	{
		sleep[i][0]=x[i];
		sleep[i][1]=z[i];
	} 
	return sleep;
}

vector<vector<int>> MIS(vector<std::vector<int> > A,int i,int j){
	int i1=getIndex(A,i);
	int j1=getIndex(A,j);
	int j2=getIndex2(A,j);
	vector<int> st;
	vector<int> ed;	
	vector<int> st1;
	vector<int> ed1;
	vector < vector<int> > sleepp;	
	if (A[i1][1]=j){
		st.push_back(i);
		ed.push_back(j);
		sleepp=MIS(A,i+1,j-1);
		for(int i=0;i<sleepp.size();i++){
			st1[i]=sleepp[i][0];
			ed1[i]=sleepp[i][1];
		}	
	}
	else{
		if(A[j2][0]>i){
			vector<int> st2;
			vector<int> ed2;
			vector<int> st3;
			vector<int> ed3;
			vector<int> st4;
			vector<int> ed4;
			vector<std::vector<int> > sleepp;
			vector<std::vector<int> > sleepp1;
			vector<std::vector<int> > sleepp2;
//			st.push_back(A[j2][0]);
//			ed.push_back(j);
			sleepp=MIS(A,i+1,j-1);
			for(int i=0;i<sleepp.size();i++){
			st2[i]=sleepp[i][0];
			ed2[i]=sleepp[i][1];
			}
			sleepp1=MIS(A,i+1,j-1);
			for(int i=0;i<sleepp.size();i++){
			st3[i]=sleepp1[i][0];
			ed3[i]=sleepp1[i][1];
			}
			sleepp2=MIS(A,i+1,j-1);
			for(int i=0;i<sleepp.size();i++){
			st4[i]=sleepp2[i][0];
			ed4[i]=sleepp2[i][1];
			}
			st3.insert(st3.end(), st4.begin(), st4.end());
	        ed3.insert(ed3.end(), ed4.begin(), ed4.end());
	        if(st2.size()>st3.size()+1){
	        	st1=st2;
	        	ed1=ed2;
			}
			else{
				st3.push_back(A[j2][0]);
				st1=st3;
				ed3.push_back(j);
				ed1=ed3;
			}
	        
		}
		else{
			vector<std::vector<int> > sleepp;
			if(i>A[j2][0]){
				st.push_back(A[j2][0]);
				ed.push_back(j);
			}
			else{
				st.push_back(j);
				ed.push_back(A[j1][1]);
			}
			sleepp=MIS(A,i+1,j-1);
		    for(int i=0;i<sleepp.size();i++){
				st1[i]=sleepp[i][0];
				ed1[i]=sleepp[i][1];
		    }
		}
			
		}
	st.insert(st.end(), st1.begin(), st1.end());
	ed.insert(ed.end(), ed1.begin(), ed1.end());
	return Return2DVector(st,ed);
}
	

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    string strLine;
    vector<std::vector<int> > Data2D;
    while (getline(in, strLine))
    {
    	if (strLine.length()>2){
	        stringstream ss(strLine);
	        vector<int> row;
	        int data;
	        while (ss >> data)
	        {

	            row.push_back(data);
	            
	        }

	        Data2D.push_back(row);
	    }
    }
//    cout << getIndex2(Data2D,10);
//    cout << Data2D[0][0];
//	cout << getIndex(Data2D);
//	, 5
}





