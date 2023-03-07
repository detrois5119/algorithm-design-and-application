#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<std::vector<int> > test1;
vector<std::vector<int> > net;
vector<std::vector<int> > line;
int grid;
int capacity;
int num;


void route(int n,int i,int j,int a,int b){
	line[n].push_back(i);
	line[n].push_back(j);
	net[i][j]=net[i][j]+1;
//	cout<<n<<' '<<i<<' '<<j<<'\n';
	if(i!=a||j!=b){
		int distx=i-a;
		int disty=j-b;
//		cout<<distx<<' '<<disty<<'\n';
		if(distx!=0&&disty!=0){
//			cout<<'123'<<'\n';
			int weightx;
			int weighty;
			if(distx<0){
				weightx=net[i+1][j];
			}
			else{
				weightx=net[i-1][j];	
			}
			if(disty<0){
				weighty=net[i][j+1];
			}
			else{
				weighty=net[i][j-1];	
			}
//			cout<<' '<<weightx<<' '<<weighty<<'\n';
			if(weightx<weighty){
				if(distx<0){
					route(n,i+1,j,a,b);
				}
				else{
					route(n,i-1,j,a,b);	
				}
			}
			else{
				if(disty<0){
					route(n,i,j+1,a,b);
				}
				else{
					route(n,i,j-1,a,b);	
				}
			}
		}
		else if(disty!=0){
//			cout<<'456'<<'\n';
			if(disty<0){
				route(n,i,j+1,a,b);
			}
			else{
				route(n,i,j-1,a,b);	
			}
		}
		else{
			if(distx<0){
				route(n,i+1,j,a,b);
			}
			else{
				route(n,i-1,j,a,b);	
			}
		}
	}
}




int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    string strLine;
    while (getline(in, strLine))
    {
    	if (strLine.find(" ")!= std::string::npos){
	        stringstream ss(strLine);
	        vector<int> row;
	        string data;
	        while (ss >> data)
	        {
	        	
	        	if(data[0]<'a')
	            row.push_back(stoi(data));
	        }
	        test1.push_back(row);
	    }
    }

    grid=test1[0][0];
    capacity=test1[1][0];
    num=test1[2][0];
	net.resize(grid);
	for(int i=0;i<grid;++i)
	{
		net[i].resize(grid);
		for(int j=0;j<grid;++j)
		{
			net[i][j]=1;
		}
	}
	line.resize(num);
	for(int i=3;i<test1.size();++i){
		route(i-3,test1[i][1],test1[i][2],test1[i][3],test1[i][4]);
	}
	for(int i=0;i<line.size();i++){
		cout<<i<<' '<<line[i].size()/2-1<<'\n';
		for(int j=3;j<line[i].size();j+=2){
			cout<<line[i][j-3]<<' '<<line[i][j-2]<<' '<<line[i][j-1]<<' '<<line[i][j]<<'\n';
		}
	}
	
	fstream fout;
    fout.open(argv[2],fstream::out);
    if(!fout.is_open())
    {
        cout << "Error: the output file is not opened!!" << endl;
        exit(1);
    }
    for(int i=0;i<line.size();i++){
		fout<<i<<' '<<line[i].size()/2-1<<'\n';
		for(int j=3;j<line[i].size();j+=2){
			fout<<line[i][j-3]<<' '<<line[i][j-2]<<' '<<line[i][j-1]<<' '<<line[i][j]<<'\n';
		}
	}
	
}




