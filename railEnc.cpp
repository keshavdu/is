#include <iostream>
using namespace std;
class RailFenceE
{
	private:
		string inp,out;
		int K,R,C;
		char mat[100][100];

		 
	public:
		RailFenceE();
		void input();
		void encrypt();
		string getEncText();

		void print();

};

RailFenceE::RailFenceE()
{
	inp = "";
	out = "";
	K = 0;
	R = 0;
	C = 0;
}

void RailFenceE::input()
{
	cout<<"Enter the plain text: ";
	getline(cin,inp);

	cout<<"Enter the key value: ";
	cin>>K;

	R = K;
	C = inp.length();

	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C+R-2; j++)
			mat[i][j] = '_';
	}
}


void RailFenceE::encrypt()
{
	int r,c,l;
	r=c=l=0;
	while(c<C)
	{
		
		while(r<R)
		{
			if(l < inp.length())
				mat[r][c] = inp[l];
			else 
				mat[r][c] = 'X';
			r++;
			c++;
			l++;

			if(r<R && c==C)
				C += R-r;
		}
		r -= 2;
		while(r>=0)
		{
			if(l < inp.length())
				mat[r][c] = inp[l];
			else 
				mat[r][c] = 'X';
			r--;
			c++;
			l++;

			if(r>=0  && c==C)
				C += R-(R-r)+1;
		}
		r += 2;
	}


}

void RailFenceE::print()
{
	cout<<"\nMatrix: \n";
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			cout<<mat[i][j];
			if(mat[i][j] != '_')
				out += mat[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
}

string RailFenceE::getEncText()
{
	return out;
}
int main()
{
	RailFenceE e;
	e.input();
	e.encrypt();
	e.print();
	cout<<"Cipher text: "<<e.getEncText();
	cout<<"\n";
	
	return 0;
}
