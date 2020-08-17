#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define pp pop_back
#define fr first
#define sc second
#define ins insert
using namespace std;

const ll maxN = (int)1e9+10;
vector <char> var;
vector <int> binary[100];
vector <int> val;
vector <int> final;
vector <int> bin[100];

int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cout<<"Enter SOP:"<<endl;
	cin>>s;
	int l= s.length();

	for(int i=0;i<l;i++)
		if(s[i]=='+')
			continue;
		else
		{
			int flag=0;
			for(int j=0;j<var.size();j++)
				if(var[j]==s[i])
				{
					flag=1;
					break;
				}
			if(flag==0)
				var.pb(s[i]);
		}
	int idx=0;
	bool ne=false;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='+')
		{
			idx++;
			continue;
		}
		if(s[i]<='Z' && s[i]>='A')
			if(s[i+1]==39)
			{
				ne=true;
				binary[idx].pb(0);
			}
			else
				binary[idx].pb(1);
	}
	int size=var.size();
	if(ne==true)
		size=var.size()-1;
	idx++;
	for(int i=0;i<idx;i++)
	{
		int value=0;
		int count=0;
		for(int j=binary[i].size()-1;j>=0;j--)
		{
			value+=pow(2,count)*binary[i][j];
			count++;
		}
		val.pb(value);
	}
	sort(val.begin(),val.end());
	int temp_size=size;
	size=pow(2,size)-1;
	for(int i=0;i<=size;i++)
	{
		bool flag1=false;
		for(int j=0;j<val.size();j++)
		{
			if(i==val[j])
			{
				flag1=true;
				break;
			}
		}
		if(flag1==false)
			final.pb(i);
	}
	for(int i=0;i<final.size();i++)
	{
		for(int j=0;j<temp_size;j++)
		{
			bin[i].pb(final[i]%2);
			final[i]=final[i]/2;
		}
		reverse(bin[i].begin(),bin[i].end());
	}

	cout<<"POS :"<<endl;
	for(int i=0;i<final.size();i++)
	{
		char t='A';
		cout<<"(";
		for(int j=0;j<bin[i].size();j++)
		{
			if(bin[i][j]==0)
			{
				if(j!=bin[i].size()-1)
				{
					cout<<t<<"+";	
				}
				else
				{
					cout<<t;
				}
			}
			else
			{
				if(j!=bin[i].size()-1)
				{
					cout<<t<<"'+";	
				}
				else
				{
					cout<<t<<"'";
				}
				
			}
			t++;
		}
		cout<<").";
	}
}


