#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <iostream>

#define SIZE 1024 //����ҳ��Ĵ�С
using namespace std;
 int n,m;
 

 typedef struct page {  //����page�ṹ�壬������ID�Ͷ�Ӧ��frame��ֵ
    int ID[100];                 //ҳ��
    int Coresponding_frame[100]; // ��Ӧ��֡��
    int phy_Add1[100]; //���������ַ����
    int phy_Add2[100]; 
}page;

 typedef struct segement{
     int ID[100];
     int size[100];         //�����߼��εĴ�С
     int totalsize;         //����ȫ���εĴ�С 
     int phy_Add1[100]; //�����������ַ����
     int phy_Add2[100];
 }seg;


page Initialization(){                       //��ʼ��ҳ��

    int a,b; 
    printf("���������ҳ���\n");
    scanf("%d",&n);
    page p;      //��ʼ���ṹ���飬ʹ���ܹ��洢��Ҫ������ҳ��
    for(int i=0; i<=n; i++){
        p.ID[i] = i;      //����ҳ��ID��
        printf("������ҳ��Ϊ%d����Ӧ��֡��\n",i); 
        scanf("%d",&a);   //�������Ӧ��֡��
        p.Coresponding_frame[i] = a;      //�������Ӧ��֡��
        p.phy_Add1[i]=a*SIZE;
        p.phy_Add2[i]=a*SIZE+SIZE-1;

    }  
    b=SIZE;
    printf("����Ϊҳ��ҳ���СΪ%dKB\n",b);
    printf("===========================\n");
    printf("ҳ��\t֡��\t�����ַ��Χ\n");
    for(int j=0; j<=n;j++){             //���Ʊ��
        printf("%d\t%d\t%d~%d\n",p.ID[j],p.Coresponding_frame[j], p.phy_Add1[j],p.phy_Add2[j]);
    }
    printf("==========================\n");
    return p;                        //���ؽṹ��
}

seg Init(){              //��ʼ���α�
    int a,b; 
    printf("���������κ�\n");
    scanf("%d",&m);
    seg s;            //��ʼ���ṹ��
    s.totalsize=0;    //��ʼ��ȫ����ֵΪ0
    for(int i=0; i<=m;i++){
        s.ID[i]=i;
        printf("������κ�Ϊ%d�Ĵ�С\n", s.ID[i]);
        scanf("%d",&b);
         s.size[i]= b;     //����ÿһ���εĴ�С
        printf("������κ�Ϊ%d����Ӧ�Ļ���ַ\n", s.ID[i]);
        scanf("%d",&a);
        s.phy_Add1[i]=a;
        s.phy_Add2[i]=a+s.size[i]-1; //��������ַ��Χ
        s.totalsize+=s.size[i];
    }
    printf("����Ϊ�α�\n",b);
    printf("============================================\n");
    printf("�κ�\t����\t�������ַ\t�����ַ��Χ\n");
    for(int j=0; j<=m;j++){             //���Ʊ��
        printf("%d\t%d\t%d\t\t%d~%d\n",s.ID[j],s.size[j],s.phy_Add1[j],s.phy_Add1[j],s.phy_Add2[j]);
    }
    printf("============================================\n");
    return s;
}

int page_mode(){

    page p1 = Initialization();    //ִ�г�ʼ��ҳ�����ҽ�֮ǰҳ�����Ϣ���������� 

     while(1){    //ѭ����Ҫ�����߼���ַ            
        int l_Add;
        int p_number,offset;      
        printf("������ʮ���Ƶ��߼���ַ\n"); 
        scanf("%d",&l_Add);
        p_number = l_Add/SIZE; //���ҳ��
        offset = l_Add%SIZE;   //���ƫ��ֵ

         if(p_number>n||l_Add<0){
            if(p_number>n){
                printf("���󣬳������ҳ��ֵ,����������\n");
            }
            else{
                 printf("�������,����������\n");
            }
         }
        else{ 
            int f_number;   
            int p_Add;   //��ʼ�������ַ
            f_number = p1.Coresponding_frame[p_number]; //�ҳ�ҳ������Ӧ��֡��
            p_Add = f_number*SIZE+offset; //��������ַ
            printf("�߼���ַΪ%d�������ַ��%d\n",l_Add,p_Add);
        }
        printf("�Ƿ���Ҫ�������룿����1�����������ԣ�����1��������˳�������������ҳ��\n");
        int input;
        scanf("%d",&input);
        switch(input){
         case 1: 
         break;
         default:
         return 0;
        } 
    }
    return 0; 
}


int segement_mode(){
    seg s1 = Init();
    while(1){    //ѭ����Ҫ�����߼���ַ            
        int l_Add;
        int offset;      
        printf("�߼���ַ���룺�������߼��κ�\n"); 
        scanf("%d",&l_Add);
        printf("���������ƫ��ֵ\n"); 
        scanf("%d",&offset);
         if(l_Add>m||l_Add<0||offset>=s1.size[l_Add]){  //����κŴ���0��ƫ����������������Ч����
            if(l_Add>m){
                printf("���󣬳����̺����ֵ,����������\n");
            }
            else if(offset>s1.size[l_Add]){
                printf("����,ƫ������������,����������\n");

            }
            else{
                 printf("�������,����������\n");
            }
         }
        else{ 
            int p_Add;
            p_Add = s1.phy_Add1[l_Add]+offset;  //��������ַ
            printf("�߼���ַ�κ�Ϊ%dƫ����Ϊ%d�������ַ��%d\n",l_Add,offset,p_Add);
        }
        printf("�Ƿ���Ҫ�������룿����1�����������ԣ�����1��������˳�������������ҳ��\n");
        int input;
        scanf("%d",&input);
        switch(input){
         case 1: 
         break;
         default:
         return 0;
        } 
    }



}


int menu(){
    int input;

    while(1){
    cout<<"-------��ӭ������ַת��ϵͳ-------"<<endl;
    cout<<endl;
    cout<<"---------------1.��ҳ---------------------"<<endl;
    cout<<"---------------2.�ֶ�----------------------"<<endl;
    cout<<"---------------3.�˳�----------------------"<<endl;
    cout<<""<<endl;
    cout<<"-----����: ������ -ѧ��: 11719720418-----"<<endl;
    cout<<endl;
    cout<<"-----������ת���߼���ַ�ķ�ʽ(1~3)-----"<<endl;
    cin>>input;
    switch(input){
        case 1:
         page_mode();
         break;
         
        case 2:
        segement_mode();
        break;

        case 3:
        return 0;
          
        default:
        cout<< "������Ч������������"<<endl;  
         break; 
        
    }
    }
}



int main(){
    menu();
    return 0;
}