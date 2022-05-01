#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class StreamE
{
	private:
		string inp,out,Key;
	
	public:
		StreamE();
		void input();
		void generateKey();
		void encrypt();
		string getEncText();
};

StreamE::StreamE()
{
	inp = out = Key = "";
}
void StreamE::input()
{
	cout<<"Enter the input text: ";
	getline(cin,inp);
}
void StreamE::generateKey()
{
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

void StreamE::encrypt()
{
	generateKey();
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

string StreamE::getEncText()
{
	return out;
}

int main()
{
	StreamE e;
	e.input();
	e.encrypt();
	cout<<"Cipher text: "<<e.getEncText()<<"\n\n";

	return 0;
}
