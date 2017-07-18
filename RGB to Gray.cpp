#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
unsigned char image[3][512][512],fimage[512][512];
int main()
{
    cout<<"This is RGB to Gray"<<endl<<"請輸入檔名或路徑(須包含附檔名raw):";
    ofstream fout("result.raw",ios_base::out | ios_base::binary);
    fstream file;
    string file1;
    cin>>file1;
    file.open(file1.c_str(),ios_base::in | ios_base::binary);
    if(!file)
    {
        cout<<"檔案開啟錯誤"<<endl;
        system("pause");
    }
    else
    {
        //運算
        cout <<"Do some operations.\n";
        for(int i=0;i<512;i++)
        {
            for(int j=0;j<512;j++)
            {
                image[0][i][j]=file.get();
                image[1][i][j]=file.get();
                image[2][i][j]=file.get();
            }
        }
        cout <<"Writing Image.\n";
        for(int i=0;i<512;i++)
        {
            for(int j=0;j<512;j++)
            {
                fimage[i][j]=image[0][i][j]*0.299+image[1][i][j]*0.587+image[2][i][j]*0.114;
            }
        }
        for(int i=0;i<512;i++)
        {
            for(int j=0;j<512;j++)
            {
                fout<<fimage[i][j];
            }
        }
    }
    file.close();
    fout.close();
    cout <<"Finish.\n";
    return 0;
}

