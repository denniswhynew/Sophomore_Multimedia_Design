#include <iostream>
#include <fstream>
using namespace std;
unsigned char image[512][512],fimage[1024][1024];
int main()
{
    //ifstream fin("firefoxx.raw",ios_base::in | ios_base::binary);
    ofstream fout("export.raw",ios_base::out | ios_base::binary);
    fstream file1;
    string file;
    cout<<"輸入讀取檔案名稱(需要檔名)*1:";
    cin>>file;

    file1.open(file.c_str(),ios_base::in | ios_base::binary);
    float num=255/4;
    if(!file1)
        cout<<"file open fail!"<<endl;
    else
    {
        cout <<"Do some operations.\n";
        for(int i=0;i<512;i++)
        {
            for(int j=0;j<512;j++)
            {
               image[i][j]=file1.get();
               if(image[i][j]/num==0)
                fimage[i*2][j*2]=0;
               else
                fimage[i*2][j*2]=255;
               if(image[i][j]/num<=1)
                fimage[i*2+1][j*2]=0;
               else
                fimage[i*2+1][j*2]=255;
               if(image[i][j]/num<=2)
                fimage[i*2][j*2+1]=0;
               else
                fimage[i*2][j*2+1]=255;
               if(image[i][j]/num<=3)
                fimage[i*2+1][j*2+1]=0;
               else
                fimage[i*2+1][j*2+1]=255;
            }
        }
        for(int i=0;i<1024;i++)
        {
            for(int j=0;j<1024;j++)
            {
                fout<<fimage[i][j];
            }
        }
    }
    file1.close();
    fout.close();
    cout <<"Finish.\n";
    return 0;
}

