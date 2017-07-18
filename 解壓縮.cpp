#include <fstream>
using namespace std;
unsigned char lib[256][16];
int rar[16384];
int main()
{
    ifstream lin("CODEBOOK.dat"),fin("index.set");
    ofstream fout("image2VQ.raw",ios_base::out | ios_base::binary);
    for(int i=0;i<256;i++)
    {
        for(int j=0;j<16;j++)
            lib[i][j]=lin.get();
    }
    for(int i=0;i<16384;i++)
        fin>>rar[i];
    for(int i=0;i<16384;i++)
    {
        for(int j=0;j<16;j++)
        {
            fout<<lib[rar[i]][j];
        }
    }
}
