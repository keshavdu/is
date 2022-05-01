#include <iostream>
#include <string>
#include <map>
using namespace std;

class  RowTranspD
{
	int rounds,r,c;
	string inp,Key,out,t;
	char mat[100][100];
	map<int,int> m;
	public:
		RowTranspD();
		void input();
		void makeMat();
		void decrypt();
		void print();
		string getDecText();
};

RowTranspD::RowTranspD()
{
	r = c = rounds = 0;
	inp = "";
	Key = "";
	out = "";
}

void RowTranspD::input()
{
	cout<<"Enter the cipher text: ";
	getline(cin,inp);

	cout<<"Enter the key: ";
	cin>>Key;
	cout<<"Enter number of rounds: ";
	cin>>rounds;

	t = inp;
}

void RowTranspD::makeMat()
{
	r = t.length()/Key.length();
	c = Key.length();
	int l = 0;

	cout<<"matrix: \n";
	for(int i=0;i<c;i++)
	{
		m[Key[i]-'0'] = i;
		cout<<Key[i]<<" ";
	}

	cout<<"\n";

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			mat[i][j] = t[l++];
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void RowTranspD::decrypt()
{
	for(int k=1;k<=rounds;k++)
	{
		cout<<"\nRound "<<k<<" ";
		makeMat();
		t = "";
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
			{
				t += mat[j][m[i+1]];
			}
		}
		cout<<"Decrypted text :"<<t<<"\n";
		
	}
	out = t;
}

string RowTranspD::getDecText()
{
	return out;
}

int main()
{
	RowTranspD e;
	e.input();
	e.decrypt();
	cout<<"\nFinal decrypted text: "<<e.getDecText()<<"\n";

	return 0;
}
