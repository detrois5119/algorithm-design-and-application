#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<vector<vector<int> > > sleep;
vector<vector<int> > sleep2 ;
vector<vector<int> > sleep3 ;
vector<std::vector<int> > Data2D;
vector<int> index12;




int getIndex2(int K){
    for (int i=0;i<Data2D.size();++i){
		if (Data2D[i][1] == K){
			return i;
		}
	}
    return -1;
}

vector<int> MIS(int i,int j){
	int j2=index12[j]; 
	int k=Data2D[abs(j2)][0];
	if(sleep3[i][j]==1){
		sleep[i][j]=MIS(i,j-1);
		return sleep[i][j];
	}
	else if(sleep3[i][j]==2){
		if(sleep2[i][j-1]>sleep2[i][k-1]+1+sleep2[k+1][j-1]){
			sleep[i][j]=MIS(i,j-1);
			return sleep[i][j];
		}
		else{
			sleep[i][j]=MIS(i,k-1);
			vector <int> a;
			a=MIS(k+1,j-1);
			for(int ii=0; ii < a.size() ; ++ii) {
				sleep[i][j].push_back(a[ii]);
			}
			sleep[i][j].push_back(k);
			sleep[i][j].push_back(j);
			return sleep[i][j];	
		}

	}
	else if(sleep3[i][j]==3){
		sleep[i][j]=MIS(i+1,j-1);
		sleep[i][j].push_back(i);
		sleep[i][j].push_back(j);
		return sleep[i][j];
	}
	else{
		return sleep[i][j];
	}
}


int main(int argc, char **argv)
{
	if(argc != 3)
    {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
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
			sleep2[i][j]=0;
		}
	}
	
	sleep3.resize(last_num+1);
	for(int i=0; i < last_num+1; ++i)
	{
		sleep3[i].resize(last_num+1);
		for(int j=0; j < last_num+1; ++j){
			sleep3[i][j]=0;
		}
	}
	
	index12.resize(last_num+1);
	for(int i=0; i < index12.size(); ++i)
	{
		index12[i]=getIndex2(i);
	}
	int j=0;
	while (j<=last_num){
		for (int i=0;i+j<last_num+1;++i){
			int j2=index12[i+j]; 
			int k=Data2D[abs(j2)][0];
			if (i+j==i){
				sleep2[i][i+j]=0;
			}
			else if (j2==-1){
			sleep2[i][i+j]=sleep2[i][i+j-1];
			sleep3[i][i+j]=1;
			} 	
			else if (k==i){
				sleep2[i][i+j]=sleep2[i+1][i+j-1]+1;
				sleep3[i][i+j]=3;
			}
			else if(k>i){
				if(sleep2[i][i+j-1]>sleep2[i][k-1]+1+sleep2[k+1][i+j-1]){
					sleep2[i][i+j]=sleep2[i][i+j-1];
				}
				else{
					sleep2[i][i+j]=sleep2[i][k-1]+1+sleep2[k+1][i+j-1];
				}
				sleep3[i][i+j]=2;	
			}
			else{
				sleep2[i][i+j]=sleep2[i][i+j-1];
				sleep3[i][i+j]=1;
			}
		}
		j++;
	}

    vector<int> test;
	test=MIS(0,last_num);
	
	vector<vector<int> > ans;
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
	
	return 0;  
	
	
}




