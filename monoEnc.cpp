#include <iostream>
using namespace std;
class Encrypt
{
	private:
	string inptext,encptext;
	int K;
	public:
	Encrypt(string inp,int k)
	{
		inptext=inp;
		K=k;
	}
	void encrypt()
	{
		encptext="";
		for(int i=0;i<inptext.length();i++)
		{
			if(isupper(inptext[i]))
			{
				encptext+=(inptext[i]+ K - 65)%26 + 65 ;
			}
			else if(islower(inptext[i]))
			{
				encptext+=(inptext[i]+ K - 97)%26 +97 ;
			}
			else 
			{
				encptext+=inptext[i];
			}
		}
	}
	string getEncpText()
	{
		return encptext;
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
	
	Encrypt e(inp,K);
	e.encrypt();
	cout<<"\nEncrypted text: "<<e.getEncpText();
	return 0;
}
