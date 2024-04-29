#include <iostream>
#include <iterator>//size()
#include <cmath>//fmod()
void sort(int s[]);
void search(int F, int S, int E, int s[]);
int n;
using namespace std;
int main(int argc, char *argv[]){
	cin>>n;
	int s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
    sort(s);
    cout<<"after sort:"<<endl;
    for(int i=0;i<n;i++){
		cout<<s[i]<<" ";		
	}
	cout<<endl;
    int t;
    cin>>t;
	search(t,0,sizeof(s)/sizeof(s[0]),s);
    return 0;
}
void sort(int s[]){
    int tmp;
    for(int i=1;i<n;i++){
    	for(int j=i-1;j>=0;j--){
    		if(s[j]>s[j+1]){
    			tmp=s[j];
    			s[j]=s[j+1];
    			s[j+1]=tmp;
    		}else{
    			break;
    		}
    	}
    }
}
void search(int S, int F, int E, int s[]){
		int m=(F+E)/2,flag=0;
	if(fmod(((double)(F+E)/2),1.0)==0){
		m--;
	}
	if(s[m]==S){cout<<m;flag=1;} 
	else if(s[m]<S){F=m;}
	else{E=m+1;}
	if(E-F<=4){//數量過少，直接搜尋
		for(int i=F;i<E;i++){
			if(s[i]==S){flag=1;cout<<i;}
		} 
		if(!flag){cout<<"N/A";}
	}else{
		search(S,F,E,s);
	}
} 
