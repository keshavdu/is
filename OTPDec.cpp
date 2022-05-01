#include <iostream>
using namespace std;

class OTPDec
{
	private:
		string inp,out,Key;
	
	public:
		OTPDec();
		void input();
		void decrypt();
		string getDecText();
};

OTPDec::OTPDec()
{
	inp = out = Key = "";
}
void OTPDec::input()
{
	cout<<"Enter the input text: ";
	getline(cin,inp);

	cout<<"Enter the Key: ";
	getline(cin,Key);
}

void OTPDec::decrypt()
{
	int p,k,r;
	for (int i=0; i<inp.length(); i++)
	{
		p = inp[i] == 32 ? 26 : inp[i] - 65;
		k = Key[i] == 32 ? 26 : Key[i] - 65;

		r = (p - k + 27) % 27;

		if(r == 26)
			out += " ";
		else 
			out += r + 65;
	}
	cout<<"\nKey: "<<Key<<"\n";
}

string OTPDec::getDecText()
{
	return out;
}

int main()
{
	OTPDec d;
	d.input();
	d.decrypt();
	cout<<"Decrypted text: "<<d.getDecText()<<"\n\n";

	return 0;
}
