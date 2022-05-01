#include <iostream>
using namespace std;

class VignereEnc
{
	private:
		string inp,out,Key;
	
	public:
		VignereEnc();
		void input();
		void encrypt();
		string getEncText();
};

VignereEnc::VignereEnc()
{
	inp = out = Key = "";
}
void VignereEnc::input()
{
	cout<<"Enter the input text: ";
	cin>>inp;
	for(char &c : inp)
	{
		c = toupper(c);
	}
	cout<<"Enter the key text: ";
	cin>>Key;
	for(char &c : Key)
	{
		c = toupper(c);
	}
}

void VignereEnc::encrypt()
{
	string t = Key;
	int l = 0;
	while(t.length()<inp.length())
	{
		t += t[l++];
	}

	for (int i=0; i<inp.length(); i++)
	{
		out += (inp[i] + t[i] ) % 26 + 65;
	}
}

string VignereEnc::getEncText()
{
	return out;
}

int main()
{
	VignereEnc e;
	e.input();
	e.encrypt();
	cout<<"Cipher text: "<<e.getEncText()<<"\n";

	return 0;
}
