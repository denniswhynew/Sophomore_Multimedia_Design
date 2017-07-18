#include <fstream>
#include <climits>
using namespace std;
unsigned char image[512][512],lib[256][16];
int a[16];
int check()
{
    int n=0;
    int m=INT_MAX;
    for(int i=0;i<256;i++)
    {
        int ss=0;
        for(int j=0;j<16;j++)
        {
            ss+=((a[j]-lib[i][j])*(a[j]-lib[i][j]));
        }
        if(ss<m)
        {
            n=i;
            m=ss;
        }
    }
    return n;
}
int main()
{
    ifstream lin("CODEBOOK.dat"),fin("image2.raw",ios_base::in | ios_base::binary);
    ofstream fout("index.set");
    for(int i=0;i<256;i++)
    {
        for(int j=0;j<16;j++)
            lib[i][j]=lin.get();
    }
    for(int i=0;i<512;i++)
    {
        for(int j=0;j<512;j++)
            image[i][j]=fin.get();
    }
    for(int i=0;i<512;i++)
    {
        for(int j=0;j<32;j++)
        {
            int l=0;
            for(int k=j*16;k<16*(1+j);k++)
            {
                a[l]=image[i][k];
                l++;
            }
            fout<<check()<<" ";
        }
    }
}
