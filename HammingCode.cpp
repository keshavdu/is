#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;
class HammingCode
{
	int *dw,*cw,m,r,l;
	public:
		HammingCode()
		{
			dw=cw=0;
			m=r=l=0;
		}
//=========================================================================================================		
		void input()
		{
			cout<<"\nEnter the length of dataword: ";
			cin>>m;
			dw=new int[m];
			cout<<"Enter the dataword: \n";
			for(int i=0;i<m;i++)
			cin>>dw[i];
		}
//=========================================================================================================		
		void getRN()
		{
			for(int i=0;;i++)
			{
				if(pow(2,i)>=(m+i+1))
				{	
					r=i;
					break;
				}
				
			}
			
			cout<<"\nNumber of redundant bits= "<<r<<endl;
		}
//=========================================================================================================		
		void genCW()
		{
			l=m+r;
			int *tdw=new int[l];
			int i,j,bc,c=m-1,p=0;
			for(i=0;i<l;i++)
			{
				if(pow(2,p)==(i+1))
				{
					tdw[i]=0;
					p++;
				}
				else
				tdw[i]=dw[c--];
			}
			
			i=j=c=p=bc=0;
			
			for(i=0;i<l;i++)
			{
				if(pow(2,p)==(i+1))
				{
					for(j=i;j<l;j++)
					{
						if(tdw[j]==1)
						{
							c++;
						}
						bc++;
						if(bc==(i+1))		//take i+1 bits and then leave i+1 bits
						{
							j+=bc;
							bc=0;
						}
					}
					
					p++;
					
					if(c%2!=0)
					tdw[i]=1;
					
					c=bc=0;
				}
			}
			
			cw=new int[m+r];
			c=l-1;
			for(i=0;i<l;i++)
			{
				cw[i]=tdw[c--];
			}
			
		}
//=========================================================================================================		
		void printCW()
		{
			cout<<"\n";
			for(int i=0;i<l;i++)
			cout<<cw[i]<<" ";
			cout<<"\n";
		}
		
		int* getCW()
		{
			return cw;
		}
		int getL()
		{
			return l;
		}
};
//=========================================================================================================
class Receiver 
{
	int *rdw,*rcw,rm,rr,rl;
	public:
		Receiver()
		{
			rcw=0;
			rr=rm=0;
		}
		
		Receiver(int *r,int l)
		{
			rl=l;
			rcw=new int[rl];
			for(int i=0;;i++)
			if(pow(2,i)>=rl+1)
				{
					rr=i;
					break;
				}
				
			rm=rl-rr;
			rcw=r;
		}
//=========================================================================================================		
		bool checkRCW()
		{
			
			int *tdw=new int[rl];
			int i,j,c,p,bc,err;
			
			bool b=true;
			c=rl-1;
			
			for(i=0;i<rl;i++)
			{
				tdw[i]=rcw[c--];
			}
			
			i=j=c=p=bc=err=0;
			
			
			for(i=0;i<rl;i++)
			{
				if(pow(2,p)==(i+1))
				{
					for(j=i;j<rl;j++)
					{
						if(tdw[j]==1)
						{
							c++;
						}
						bc++;
						if(bc==(i+1))
						{
							j+=bc;
							bc=0;
						}
					}
					
					p++;
					
					if(c%2!=0)
					{	
						b=false;
						err+=(i+1);
					}
					
					c=bc=0;
				}
			}
			
			
			if(!b)
			{	cout<<"\nIncorrect message received!!\n";
				cout<<"Error found at bit number: "<<rl-err;
				err=rl-err;
				if(rcw[err]==0)
				rcw[err]=1;
				else
				rcw[err]=0;
			}
			cout<<endl;
			return b;
		}
//=========================================================================================================
		void printRCW()
		{
			cout<<"\n";
			for(int i=0;i<rl;i++)
			cout<<rcw[i]<<" ";
			cout<<endl;
		}
//=========================================================================================================		
		void extractDW()
		{	
			int p=rr-1,c=0,i;
			rdw=new int[rm];
			
			for(i=0;i<rl;i++)
			{
				if(i!=(rl-pow(2,p)))
				{
					rdw[c++]=rcw[i];
				}
				else
				p--;
			}
			
			for(i=0;i<c;i++)
			cout<<rdw[i]<<" ";
			cout<<"\n\n";
		}
//=========================================================================================================		
};
		
int main()
{
	HammingCode A;
	A.input();
	A.getRN();
	A.genCW();
	cout<<"\nCodeword sent:";
	A.printCW();
	
	int *tcw,tL;
	tcw=A.getCW();
	tL=A.getL();
	srand(time(0));
	int p=rand()%(tL+10);
	//cout<<"\nRandom number: "<<p;
	if(p<tL)		//generating error if p is less than length of codeword
	{
		if(tcw[p]==1)
		tcw[p]=0;
		else
		tcw[p]=1;
	}
	
	Receiver r(tcw,tL);
	cout<<"\nCodeword received:";
	r.printRCW();
	bool b=r.checkRCW();	
	
	if(b)
	{
		cout<<"\nMessage received correctly!!\n";
		
	}
	else
	{
		cout<<"\nAfter error correction codeword:";
		
		r.printRCW();
	}
	
	cout<<"\nExtracted dataword:\n";
	r.extractDW();		

	return 0;

}

