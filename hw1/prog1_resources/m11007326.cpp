#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> sleep;
vector<vector<int>> sleep2 ;
vector<std::vector<int> > Data2D;




int getIndex2(int K){
    for (int i=0;i<Data2D.size();++i){
		if (Data2D[i][1] == K){
			return i;
		}
	}
    return -1;
}

vector<int> MIS(int i,int j){
	int j2=getIndex2(j); 
	vector<int> ans;	
	if (j==i){
		ans = {};
		return ans;
	}
	
	else if (j2!=-1&Data2D[abs(j2)][0]==i){
			ans=sleep[i+1][j-1];	
			ans.push_back(i);
			ans.push_back(j);
		    return ans;
	    
	}
	else if(j2!=-1 & Data2D[abs(j2)][0]>i){	
				vector<int> ans2;
				vector<int> ans3;
				vector<int> ans4;
				ans2=sleep[i][j-1];
				ans3=sleep[i][Data2D[j2][0]-1];
				ans4=sleep[Data2D[j2][0]+1][j-1];
		        if(ans2.size()>=ans3.size()+ans4.size()+1){
		    	return ans2;	
				}
				else{
				ans3.insert(ans3.end(), ans4.begin(), ans4.end());
				ans3.push_back(Data2D[j2][0]);
			    ans3.push_back(j);
		    	return ans3;	
		    	}
		    
	}
	else{
		return sleep[i][j-1];
	}		 
    

}

void MISS(int i,int j){
	int j2=getIndex2(j);
	if(sleep2[i][j]==-1){
		sleep2[i][j]=1; 	
		if (j==i){}
		
		else if (j2!=-1&Data2D[abs(j2)][0]==i){
			    MISS(i+1,j-1);
		    
		}
		else if(j2!=-1 & Data2D[abs(j2)][0]>i){	
				MISS(i,j-1);
				MISS(i,Data2D[j2][0]-1);
				MISS(Data2D[j2][0]+1,j-1);	
			    }
		else{
			MISS(i,j-1);
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
    
    ifstream in(argv[1]);
    string strLine;
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
		}
	}
	MISS(0,last_num);
    
	int j=0;
	while (j<=last_num){
		for (int i=0;i+j<last_num+1;++i){
			if(sleep2[i][i+j]!=-1)
			sleep[i][i+j]=MIS(i,i+j);
		}
		j++;
	}

	
	vector<vector<int>> ans;
	ans.resize(sleep[0][last_num].size()/2);
	for(int i=0; i < ans.size(); ++i)
	{
		ans[i].resize(2);

	}
	
    cout << "======================" << endl;
    cout << "        Parser        " << endl;
    cout << "======================" << endl;
	cout << ans.size() << '\n';
	int iii=0;
	for (int i=0;i<sleep[0][last_num].size();i=i+2){
		ans[iii][0]=sleep[0][last_num][i];
		ans[iii][1]=sleep[0][last_num][i+1];
		++iii;
	}
	
	sort(ans.begin(),ans.end());
	
	for (int i=0;i<ans.size();++i){
		cout << ans[i][0] <<' '<<ans[i][1] <<"\n";
	}
	
	fstream fout;
    fout.open(argv[2],fstream::out);
    if(!fout.is_open())
    {
        cout << "Error: the output file is not opened!!" << endl;
        exit(1);
    }
    fout << ans.size() << '\n';
	for (int i=0;i<ans.size();++i){
		fout << ans[i][0] <<' '<<ans[i][1] <<"\n";
	}
	
	
}




