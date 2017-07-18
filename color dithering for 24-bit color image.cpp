#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
unsigned char image[3][512][512],Rimage[1024][1024],Gimage[1024][1024],Bimage[1024][1024],fimage[3][1024][1024];
int main()
{
    cout<<"This is color dithering for 24-bit color image"<<endl<<"請輸入檔名或路徑(須包含附檔名raw):";
    ofstream fout("result.raw",ios_base::out | ios_base::binary);
    fstream file;
    string file1;
    cin>>file1;
    file.open(file1.c_str(),ios_base::in | ios_base::binary);
    float num=255/4;
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
                //R
                image[0][i][j]=file.get();
               if(image[0][i][j]/num==0)
                Rimage[i*2][j*2]=0;
               else
                Rimage[i*2][j*2]=255;
               if(image[0][i][j]/num<=1)
                Rimage[i*2+1][j*2]=0;
               else
                Rimage[i*2+1][j*2]=255;
               if(image[0][i][j]/num<=2)
                Rimage[i*2][j*2+1]=0;
               else
                Rimage[i*2][j*2+1]=255;
               if(image[0][i][j]/num<=3)
                Rimage[i*2+1][j*2+1]=0;
               else
                Rimage[i*2+1][j*2+1]=255;
                //G
                image[1][i][j]=file.get();
               if(image[1][i][j]/num==0)
                Gimage[i*2][j*2]=0;
               else
                Gimage[i*2][j*2]=255;
               if(image[1][i][j]/num<=1)
                Gimage[i*2+1][j*2]=0;
               else
                Gimage[i*2+1][j*2]=255;
               if(image[1][i][j]/num<=2)
                Gimage[i*2][j*2+1]=0;
               else
                Gimage[i*2][j*2+1]=255;
               if(image[1][i][j]/num<=3)
                Gimage[i*2+1][j*2+1]=0;
               else
                Gimage[i*2+1][j*2+1]=255;
                //B
                image[2][i][j]=file.get();
               if(image[2][i][j]/num==0)
                Bimage[i*2][j*2]=0;
               else
                Bimage[i*2][j*2]=255;
               if(image[2][i][j]/num<=1)
                Bimage[i*2+1][j*2]=0;
               else
                Bimage[i*2+1][j*2]=255;
               if(image[2][i][j]/num<=2)
                Bimage[i*2][j*2+1]=0;
               else
                Bimage[i*2][j*2+1]=255;
               if(image[2][i][j]/num<=3)
                Bimage[i*2+1][j*2+1]=0;
               else
                Bimage[i*2+1][j*2+1]=255;
            }
        }
        cout <<"Writing Image.\n";
        for(int i=0;i<1024;i++)
        {
            for(int j=0;j<1024;j++)
            {
                fimage[0][i][j]=Rimage[i][j];
                fimage[1][i][j]=Gimage[i][j];
                fimage[2][i][j]=Bimage[i][j];
            }
        }
        for(int i=0;i<1024;i++)
        {
            for(int j=0;j<1024;j++)
            {
                for(int k=0;k<3;k++)
                {
                    fout<<fimage[k][i][j];
                }
            }
        }
    }
    file.close();
    fout.close();
    cout <<"Finish.\n";
    return 0;
}

