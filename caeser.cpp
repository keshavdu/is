#include <iostream>
using namespace std;
class Encrypt
{
	private:
	string inptext,encptext;
	const int K=3;
	public:
	Encrypt(string inp)
	{
		inptext=inp;
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
class Decrypt
{
	private:
	string inptext,dectext;
	const int K=3;
	public:
	Decrypt(string inp)
	{
		inptext=inp;
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
	
	Encrypt e(inp);
	e.encrypt();
	cout<<"\nEncrypted text: "<<e.getEncpText();

	Decrypt d(e.getEncpText());
	d.decrypt();
	cout<<"\nDecrypted text: "<<d.getDecText()<<"\n";
	return 0;
}
