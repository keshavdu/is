#include <cctype>
#include <iostream>
#include <map>
using namespace std;
class Encrypt 
{
	private:
  	string inptext, key, encptext;
  	char mat[5][5];
  	map<char, pair<int, int>> mapp;
  	
	void makeMatrix();
  	string makePairs();

	public:
  	Encrypt(string, string);
  	void encrypt();
	string getEncpText();

};
Encrypt::Encrypt(string inp, string k) 
{
	inptext = inp;
	key = k;
}
void Encrypt::makeMatrix() 
{
  	string t = "";
  	for (char c : key) 
  	{
		c = toupper(c);
    		if (c == 'J')
      			c = 'I';
    		if (t.find(c) == string::npos)
      			t += c;
  	}
  	for (char c = 'A'; c <= 'Z'; c++) 
  	{
    		if (t.find(c) == string::npos && c != 'J')
      			t += c;
  	}
  	int l = 0;
  	for (int i = 0; i < 5; i++) 
  	{
    		for (int j = 0; j < 5; j++) 
    		{
      			mapp[t[l]] = {i, j};
      			mat[i][j] = t[l];
      			l++;
      			
      			cout<<mat[i][j]<<" ";
    		}
			cout<<endl;
    		
  	}
  	
}
string Encrypt::makePairs() 
{
  	string p = "";
  	p += toupper(inptext[0]);
  	for (int i = 1; i < inptext.length(); i++) 
  	{
    		if(inptext[i]!=' ')
		{
			if (inptext[i] == inptext[i - 1] && p.length() % 2 != 0)
      				p += 'X';
    		
			p += toupper(inptext[i]);	
  		}
	}
  	if (p.length() % 2 != 0)
    		p += 'Z';

	for(int i = 0; i < p.length(); i++)
	{
		if(p[i] == 'J')
			p[i] = 'I';
	}
  	return p;
}
void Encrypt::encrypt() 
{
  	makeMatrix();
  	string p = makePairs();
  	char a, b;
  	encptext = "";
  	for (int i = 0; i < p.length(); i += 2) 
  	{
    		a = p[i];
    		b = p[i + 1];
    		if (mapp[a].first == mapp[b].first) 
    		{
      			encptext += mat[mapp[a].first][(mapp[a].second + 1) % 5];
      			encptext += mat[mapp[b].first][(mapp[b].second + 1) % 5];
    		} 
    		else if (mapp[a].second == mapp[b].second) 
    		{
      			encptext += mat[(mapp[a].first + 1) % 5][mapp[a].second];
      			encptext += mat[(mapp[b].first + 1) % 5][mapp[b].second];
    		} 
    		else 
    		{
      			encptext += mat[mapp[a].first][mapp[b].second];
     	 		encptext += mat[mapp[b].first][mapp[a].second];
    		}
  	}
}
string Encrypt::getEncpText()
{
	return encptext;
}
int main() 
{
	string inp,k;
	cout<<"Enter Plain text: ";
	cin>>inp;
	cout<<"Enter key: ";
	cin>>k;
	cout<<endl;
	
  	Encrypt e(inp,k);
  	e.encrypt();
	cout<<"\n\nCipher text: "<<e.getEncpText()<<"\n";
	return 0;
}
