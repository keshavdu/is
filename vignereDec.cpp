#include <iostream>
using namespace std;

class VignereDec
{
	private:
		string inp,out,Key;
	
	public:
		VignereDec();
		void input();
		void decrypt();
		string getDecText();
};

VignereDec::VignereDec()
{
	inp = out = Key = "";
}
void VignereDec::input()
{
	cout<<"Enter the cipher text: ";
	cin>>inp;
	for(char &c : inp)
		c = toupper(c);

	cout<<"Enter the key: ";
	cin>>Key;
	for(char &c : Key)
		c = toupper(c);
}

void VignereDec::decrypt()
{
	string t = Key;
	int l = 0;
	while(t.length()<inp.length())
	{
		t += t[l++];
	}

	for (int i=0; i<inp.length(); i++)
	{
		out += (inp[i] - t[i] + 26 ) % 26 + 65;
	}
}

string VignereDec::getDecText()
{
	return out;
}

int main()
{
	VignereDec d;
	d.input();
	d.decrypt();
	cout<<"Decrypted text: "<<d.getDecText()<<"\n";

	return 0;
}
