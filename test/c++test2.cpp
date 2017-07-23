#include<iostream>
#include<map>
#include<string>

using namespace std;
int main()
{
	int n;
	char ch;
	string s;
	map<string,int > balloon;
 while(scanf("%d",&n)!=EOF&&n ){
	while(n--){
		s="";
		while(1){
			scanf("%c",&ch);
			if(ch=='\n') break;
			s+=ch;	
		}
		if(!balloon.count(s)) balloon[s]=0;
		balloon[s]++;
	}
	map<string,int >::iterator it;
	for(it=balloon.begin();it!=balloon.end();it++)	{
		cout<<it->first<<" ";
		cout<<it->second<<endl;
	}
	balloon.clear();
 }
	return 0;
}