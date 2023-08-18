#include<iostream>
using namespace std;

struct node{
	int dist[20];
	int fr[20];
	
	
} route[20];


int main (){
	int dm[20][20],no;
	
	cout<<"enter no of nodes"<<endl;
	cin>>no;
	cout<<"enter distance matrix"<<endl;
	for(int i=0;i<no;i++){
	
	for(int j=0;j<no;j++){
		cin>>dm[i][j];
		dm[i][j]=0;
		route[i].dist[j]=dm[i][j];
		route[i].fr[j]=j;
	}
}

int flag;
do{
	flag=0;
	for(int i=0;i<no;i++){
		for(int j=0;j<no;j++){
			for (int k=0;k<no;k++){
				if((route[i].dist[j])>(route[i].dist[k]+ route[k].dist[j])){
				route[i].dist[j]=route[i].dist[k]+ route[k].dist[j];
				route[i].fr[j]=k;
				flag=1;
				}
				
			}
		}
	}
}while(flag);


for(int i=0;i<no;i++){
	cout<<"Router info for router"<<i+1<<endl;
	cout<<"dest\tnext hop\tdist"<<endl;
	for(int j=0;j<no;j++)
	printf("%d\t%d%\t\t%d\n",j+1,route[i].fr[j]+1,route[i].dist[j]);
	
}
return 0;
}



