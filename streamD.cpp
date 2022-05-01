#include <iostream>
using namespace std;

class StreamD
{
	private:
		string inp,out,Key;
	
	public:
		StreamD();
		void input();
		void decrypt();
		string getDecText();
};

StreamD::StreamD()
{
	inp = out = Key = "";
}
void StreamD::input()
{
	cout<<"Enter the input text: ";
	getline(cin,inp);

	cout<<"Enter the Key: ";
	getline(cin,Key);
}

void StreamD::decrypt()
{
	int p,k,r;
	for (int i=0; i<inp.length(); i++)
	{
		p = inp[i] == 32 ? 26 : inp[i] - 65;
		k = Key[i] == 32 ? 26 : Key[i] - 65;

		r = p ^ k;

		if(r == 26)
			out += " ";
		else 
			out += r + 65;
	}
	cout<<"\nKey: "<<Key<<"\n";
}

string StreamD::getDecText()
{
	return out;
}

int main()
{
	StreamD d;
	d.input();
	d.decrypt();
	cout<<"Decrypted text: "<<d.getDecText()<<"\n\n";

	return 0;
}
