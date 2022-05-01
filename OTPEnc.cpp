#include <iostream>
#include <cstdlib>
using namespace std;

class OTPEnc
{
	private:
		string inp,out,Key;
	
	public:
		OTPEnc();
		void input();
		void encrypt();
		string getEncText();
};

OTPEnc::OTPEnc()
{
	inp = out = Key = "";
}
void OTPEnc::input()
{
	cout<<"Enter the input text: ";
	getline(cin,inp);

	srand(time(0));
	int r;
	for(char &c : inp)
	{
		c = toupper(c);
		r = rand()%27;
		if(r == 26)
			Key += " ";
		else 
			Key += r + 65;
	}
}

void OTPEnc::encrypt()
{
	int p,k,r;
	for (int i=0; i<inp.length(); i++)
	{
		p = inp[i] == 32 ? 26 : inp[i] - 65;
		k = Key[i] == 32 ? 26 : Key[i] - 65;

		r = (p + k) % 27;

		if(r == 26)
			out += " ";
		else 
			out += r + 65;
	}
	cout<<"\nKey: "<<Key<<"\n";
}

string OTPEnc::getEncText()
{
	return out;
}

int main()
{
	OTPEnc e;
	e.input();
	e.encrypt();
	cout<<"Cipher text: "<<e.getEncText()<<"\n\n";

	return 0;
}
