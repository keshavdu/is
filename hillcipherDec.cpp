#include <iostream>
#include <cmath>
using namespace std;
class HillCiphD
{
	private:
	string inp,out;
	int inMat[100][100],keyMat[100][100],outMat[100][100];
	float inv[100][100];
	int M;
	void makeMat();

	public:
	HillCiphD();
	void input();
	void decrypt();
	string getDecText();

	void print();
};

HillCiphD::HillCiphD()
{
	inp = "";
	out = "";
	M = 0;
}

void HillCiphD::input()
{ 
	cout<<"Enter the plain text: ";
	cin>>inp;
	for(char &c : inp)
		c = toupper(c);
	
	cout<<"Enter the size of Key matrix: ";
	cin>>M;

	
	cout<<"Enter the Key matrix: \n";
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>keyMat[i][j];
		}
	}
}

void HillCiphD::makeMat()
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

void HillCiphD::decrypt()
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

string HillCiphD::getDecText()
{
	return out;
}

void HillCiphD::print()
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
			cout<<inv[i][j]<<" ";
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
	HillCiphD h;
	h.input();
	h.decrypt();
	h.print();
	cout<<"Decrypted text: "<<h.getDecText()<<"\n";

	return 0;
}
