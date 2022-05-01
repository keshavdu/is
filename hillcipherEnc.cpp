#include <iostream>
#include <cmath>
using namespace std;
class HillCiphE
{
	private:
	string inp,out;
	int inMat[100][100],keyMat[100][100],outMat[100][100];
	int M;
	void makeMat();

	public:
	HillCiphE();
	void input();
	void encrypt();
	string getEncText();

	void print();
};

HillCiphE::HillCiphE()
{
	inp = "";
	out = "";
	M = 0;
}

void HillCiphE::input()
{ 
	cout<<"Enter the plain text: ";
	cin>>inp;
	for(char &c : inp)
		c = toupper(c);
	
	cout<<"Enter the size of Key matrix: ";
	cin>>M;

	while(inp.length()%M != 0)
	{
		inp += 'Z';
	}
	
	cout<<"Enter the Key matrix: \n";
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>keyMat[i][j];
		}
	}
}

void HillCiphE::makeMat()
{
	int l = 0;
	for(int i=0;i<inp.length()/M;i++)
	{
		for(int j=0;j<M;j++)
		{
			inMat[i][j] = inp[l++] - 65;
		}
	}
	
}

void HillCiphE::encrypt()
{
	makeMat();
	for(int i=0;i<inp.length()/M;i++)
	{
		for(int j=0;j<M;j++)
		{
			outMat[i][j] = 0;
			for(int k=0;k<M;k++)
			{
				outMat[i][j] +=  inMat[i][k] * keyMat[k][j];
				outMat[i][j] %= 26;
				
			}
			out +=  outMat[i][j] + 65;
		}
	}
}

string HillCiphE::getEncText()
{
	return out;
}

void HillCiphE::print()
{
	cout<<"\nInput matrix:\n";
	for(int i=0;i<inp.length()/M;i++)
	{
		for (int j=0; j<M; j++)
		{
			cout<<inMat[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"\nKey matrix:\n";
	for(int i=0;i<M;i++)
	{
		for (int j=0; j<M; j++)
		{
			cout<<keyMat[i][j]<<" ";
		}
		cout<<"\n";
	}

	cout<<"\nOutput matrix:\n";
	for(int i=0;i<inp.length()/M;i++)
	{
		for (int j=0; j<M; j++)
		{
			cout<<outMat[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
int main()
{
	HillCiphE h;
	h.input();
	h.encrypt();
	h.print();
	cout<<"Cipher text: "<<h.getEncText()<<"\n";

	return 0;
}
