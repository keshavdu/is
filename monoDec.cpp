#include <iostream>
using namespace std;
class Decrypt
{
	private:
	string inptext,dectext;
	int K;
	public:
	Decrypt(string inp,int k)
	{
		inptext=inp;
		K=k;
	}
	void decrypt()
	{
		dectext="";
		for(int i=0;i<inptext.length();i++)
		{
			if(isupper(inptext[i]))
			{
				dectext+=(inptext[i] - 65-K+26)%26 + 65 ;
			}
			else if(islower(inptext[i]))
			{
				dectext+=(inptext[i]- 97-K+26)%26 +97 ;
			}
			else 
			{
				dectext+=inptext[i];
			}
		}
	}
	string getDecText()
	{
		return dectext;
	}

};
int main()
{
	string inp;
	int K;
	cout<<"Enter the input text: ";
	getline(cin,inp);
	cout<<"Enter key: ";
	cin>>K;

	Decrypt d(inp,K);
	d.decrypt();
	cout<<"\nDecrypted text: "<<d.getDecText()<<"\n";
	return 0;
}
