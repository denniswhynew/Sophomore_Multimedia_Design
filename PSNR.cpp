#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    unsigned char image[512][512],rimage[512][512];
    fstream file1,rfile1;
    string file,rfile;
    cout<<"輸入原始檔案名稱(需要檔名):";
    cin>>file;
    file1.open(file.c_str(),ios_base::in | ios_base::binary);
    if(!file1)
        cout<<"file open fail!"<<endl;
    cout<<"輸入壓縮後檔案名稱(需要檔名):";
    cin>>rfile;
    rfile1.open(rfile.c_str(),ios_base::in | ios_base::binary);
    if(!rfile1)
        cout<<"file open fail!"<<endl;

    for(int i=0;i<512;i++)
        for(int j=0;j<512;j++)
            image[i][j]=file1.get();
    for(int i=0;i<512;i++)
        for(int j=0;j<512;j++)
            rimage[i][j]=rfile1.get();
    double MSE=0,PSNR=0,temp;
    for(int i=0;i<512;i++)
    {
        for(int j=0;j<512;j++)
        {
            temp=(image[i][j]-rimage[i][j])*(image[i][j]-rimage[i][j]);
            MSE+=temp;
        }

    }
     MSE=MSE/(512*512);
     PSNR=10*log10(255*255/MSE);
     cout<<"PSNR : ";
     cout<<PSNR;

    file1.close();
    rfile1.close();
}
