#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;
class CheckSum
{
	int *dw,*ch,n,m,*cw;
	float l;
	public:
		CheckSum()
		{
			n=m=0;
			dw=ch=cw=0;
		}
//=========================================================================================================
		void input()
		{
			cout<<"Enter the length of data word: ";
			cin>>n;
			cout<<"Enter the length of checksum: ";
			cin>>m;
			ch=new int[m];
			l=(float)n/m;
			l=ceil(l);
			l*=m;	//if length of dataword is not a multiple of length of checksum then 0 should be appended at msb of dataword
			dw =new int[(int)l];
			int i;
			
			cout<<"\nEnter the dataword:\n";
			for(i=(int)l-n;i<l;i++)
			cin>>dw[i];			//entering dataword
			
			
		}
//=========================================================================================================		
		void addition()
		{
			
			int lb=0,ub=m,i;
			int *s=new int[m];		//stores m(length of checksum) bits for addition 
			while(ub<=l)
			{
			
				for(i=0;i<m;i++)
				{
					s[i]=dw[lb];		//storing m bits for adding each group of bits to obtain checksum 
					lb++;
				}
				
				sum(s);
			
				ub+=m;				//to obtain next group of m bits
				
			}
		
		
		}
//=========================================================================================================		
		void sum(int *a)
		{
			
			
			
			int i,c=0;
			for(i=m-1;i>=0;i--)
			{
				if(c+a[i]+ch[i]==1)		//if no carry
				{
					ch[i]=1;
					c=0;
				}
				else if(c+a[i]+ch[i]>1)
				{
					
					if(c+a[i]+ch[i]==2)
					ch[i]=0;		//if sum is 2 i.e. 10 store 0 and take 1 carry
					else
					ch[i]=1;		//if sum is 3 i.e. 11 store 1 and take 1 carry
					c=1;
				}
				
			}
			
		
			while(c==1)			//to add carry bit again in the checksum
			{
				for(i=m-1;i>=0;i--)
				{
					if(ch[i]+c==1)
					{
						ch[i]=1;
						c=0;
						break ;
					}
					else
					{
						ch[i]=0;
						c=1;
					}
				}
			}
			
		}
//=========================================================================================================		
		void comp()		//aking the complement of the sum obtained to get checksum
		{
		
			int i;
			for( i=0;i<m;i++)
			{
				if(ch[i]==0)
				ch[i]=1;
				else
				ch[i]=0;
			}
			
			
		}
//=========================================================================================================		
		void genCodeWord()
		{
			comp();
			int c=0,i;
			cw=new int[n+m];
			
			for(i=(int)(l-n);i<l;i++)		//(l-n) for not storing the extra 0s from the msb of dataword
			cw[c++]=dw[i];				//storing the dataword 
			
			for(i=0;i<m;i++)
			cw[c++]=ch[i];				//appending the checksum to obtain the final codeword
			
			cout<<"\nCodeword sent:\n";
			c=1;
			for(i=0;i<n+m;i++)
			{
				cout<<cw[i]<<" ";
				if(c%m==0)
				{
					cout<<"   ";
					
				}
				c++;
			}
		}
		int* getCW()
		{
			return cw;
		}
		int getN()
		{
			return n;
		}
		int getM()
		{
			return m;
		}
		
};
//=========================================================================================================
class Receiver
{
	int *rdw,*rcw,*rem,n,m;
	float l;
	public:
		Receiver()
		{
			n=m=0;
			rdw=rcw=rem=0;
			l=0;
		}
		Receiver(int *cw,int N,int M)
		{
			rcw=cw;
			n=N; m=M;
			l=m+n;
			l=ceil((float)l/m);
			l*=m;			//if length of codeword is not a multiple of length of checksum then 0 should be appended at msb of codeword
			rdw=new int[(int)l];
			
			int i,j;			
			for(i=(int)l-(m+n),j=0;i<l;i++,j++)
			rdw[i]=rcw[j];			//received codeword including checksum is the dataword for receiver
	
			rem=new int[m];		//to perform addition and complement at the receiver end
		}
//=========================================================================================================		
		bool addition()
		{
			int lb=0,ub=m,i;
			int *s=new int[m];		//for storing m bits at a time for addition
			
			while(ub<=l)
			{
			
				for(i=0;i<m;i++)
				{
					s[i]=rdw[lb];		//storing m bits starting from 0
					lb++;
				}
				
				sum(s);
			
				ub+=m;				//to obtain next m bits
				
			}
			comp();
			bool b=true;
			for(i=0;i<m;i++)			//to check the result obatined after complementing at receiver end
			{
				if(rem[i]==1)
				{
					b=false;		//result should be 0 for correct transmision of message
					break;
				}
			}
			
			return b;
		}
//=========================================================================================================
		void sum(int *a)
		{
			
			
			
			int i,c=0;
			for(i=m-1;i>=0;i--)
			{
				if(c+a[i]+rem[i]==1)
				{
					rem[i]=1;
					c=0;
				}
				else if(c+a[i]+rem[i]>1)
				{
					
					if(c+a[i]+rem[i]==2)
					rem[i]=0;
					else
					rem[i]=1;
					c=1;
				}
				
			}
			
		
			while(c==1)
			{
				for(i=m-1;i>=0;i--)
				{
					if(rem[i]+c==1)
					{
						rem[i]=1;
						c=0;
						break ;
					}
					else
					{
						rem[i]=0;
						c=1;
					}
				}
			}
			
		}
//=========================================================================================================		
		void comp()
		{
			for(int i=0;i<m;i++)
			{
				if(rem[i]==0)
				rem[i]=1;
				else
				rem[i]=0;
			}
			
		}
//=========================================================================================================		
		void extractDW()
		{
			int i,c=1;
			rdw=new int[n];
			for(i=0;i<n;i++)
			rdw[i]=rcw[i];		//storing the dataword from the codeword
			
			cout<<"Received dataword:\n";
			for(i=0;i<n;i++)
			{
				cout<<rdw[i]<<" ";
				if(c%m==0)
				{
					cout<<"   ";
					
				}
				c++;
			}
				
		}
//=========================================================================================================	
		void printCW()
		{
			cout<<"\nCodeword received:\n";
			int c=1;
			for(int i=0;i<n+m;i++)
			{
				cout<<rcw[i]<<" ";
				if(c%m==0)
				{
					cout<<"   ";
					
				}
				c++;
			}
		}
};
//=========================================================================================================		
int main()
{
	CheckSum A;
	A.input();
	A.addition();
	A.genCodeWord();
	
	int *tcw,tN,tM;
	tcw=A.getCW();
	tN=A.getN();
	tM=A.getM();
	srand(time(0));
	int p=rand()%(tN+tM+10);
	cout<<"\nRandom number: "<<p;
	if(p<tN+tM)		//generating error if p is less than length of codeword
	{
		if(tcw[p]==0)
		tcw[p]=1;
		else
		tcw[p]=0;
	}
	
	
	Receiver r(tcw,tN,tM);
	bool b=r.addition();		//checking if the result at the receiver end is 0,b holds true if result is 0
	r.printCW();
	if(b)
	{
		cout<<"\nMessage received correctly!!\n";
		r.extractDW();
	}
	else
	cout<<"\nIncorrect message received!!\n";
	cout<<endl;

	return 0;
}
