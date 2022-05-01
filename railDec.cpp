#include <iostream>
using namespace std;
class RailFenceD
{
	private:
		string inp,out;
		int K,R,C;
		char mat[100][100];

		 
	public:
		RailFenceD();
		void input();
		void decrypt();
		string getDecText();

		void print();

};

RailFenceD::RailFenceD()
{
	inp = "";
	out = "";
	K = 0;
	R = 0;
	C = 0;
}

void RailFenceD::input()
{
	cout<<"Enter the cipher text: ";
	getline(cin,inp);

	cout<<"Enter the key: ";
	cin>>K;

	R = K;
	C = inp.length();

	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
			mat[i][j] = '_';
	}
}

void RailFenceD::decrypt()
{
	int r,c,l;
	r=c=l=0;
	while(c<C)
	{
		while(r<R)
		{
			mat[r][c] = '*';
			r++;
			c++;
		}
		r -= 2;
		if(c==C)
			break;
		while(r>=0)
		{
			mat[r][c] = '*';
			r--;
			c++;
		}
		r += 2;
	}
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(mat[i][j] == '*')
				mat[i][j] = inp[l++];
		}
	}

	r=c=0;
	while(c<C)
	{
		
		while(r<R)
		{
			out += mat[r][c];
			r++;
			c++;
		}
		r -= 2;
		while(r>=0)
		{
			out += mat[r][c];
			r--;
			c++;
		}
		r += 2;
	}


}

void RailFenceD::print()
{
	cout<<"\nMatrix: \n";
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			cout<<mat[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
}

string RailFenceD::getDecText()
{
	return out;
}
int main()
{
	RailFenceD d;
	d.input();
	d.decrypt();
	d.print();
	cout<<"Decrypted text: "<<d.getDecText();
	cout<<"\n";
	
	return 0;
}
