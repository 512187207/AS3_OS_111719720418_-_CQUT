#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <iostream>

#define SIZE 1024 //定义页面的大小
using namespace std;
 int n,m;
 

 typedef struct page {  //定义page结构体，储存其ID和对应的frame的值
    int ID[100];                 //页号
    int Coresponding_frame[100]; // 对应的帧号
    int phy_Add1[100]; //定义物理地址区间
    int phy_Add2[100]; 
}page;

 typedef struct segement{
     int ID[100];
     int size[100];         //定义逻辑段的大小
     int totalsize;         //定义全部段的大小 
     int phy_Add1[100]; //定义物理基地址区间
     int phy_Add2[100];
 }seg;


page Initialization(){                       //初始化页表

    int a,b; 
    printf("请输入最大页面号\n");
    scanf("%d",&n);
    page p;      //初始化结构数组，使它能够存储想要数量的页号
    for(int i=0; i<=n; i++){
        p.ID[i] = i;      //定义页面ID号
        printf("请输入页号为%d所对应的帧号\n",i); 
        scanf("%d",&a);   //输入其对应的帧号
        p.Coresponding_frame[i] = a;      //定义其对应的帧号
        p.phy_Add1[i]=a*SIZE;
        p.phy_Add2[i]=a*SIZE+SIZE-1;

    }  
    b=SIZE;
    printf("以下为页表，页面大小为%dKB\n",b);
    printf("===========================\n");
    printf("页号\t帧号\t物理地址范围\n");
    for(int j=0; j<=n;j++){             //绘制表格
        printf("%d\t%d\t%d~%d\n",p.ID[j],p.Coresponding_frame[j], p.phy_Add1[j],p.phy_Add2[j]);
    }
    printf("==========================\n");
    return p;                        //返回结构体
}

seg Init(){              //初始化段表
    int a,b; 
    printf("请输入最大段号\n");
    scanf("%d",&m);
    seg s;            //初始化结构体
    s.totalsize=0;    //初始化全部数值为0
    for(int i=0; i<=m;i++){
        s.ID[i]=i;
        printf("请输入段号为%d的大小\n", s.ID[i]);
        scanf("%d",&b);
         s.size[i]= b;     //定义每一个段的大小
        printf("请输入段号为%d所对应的基地址\n", s.ID[i]);
        scanf("%d",&a);
        s.phy_Add1[i]=a;
        s.phy_Add2[i]=a+s.size[i]-1; //算出物理地址范围
        s.totalsize+=s.size[i];
    }
    printf("以下为段表\n",b);
    printf("============================================\n");
    printf("段号\t界限\t物理基地址\t物理地址范围\n");
    for(int j=0; j<=m;j++){             //绘制表格
        printf("%d\t%d\t%d\t\t%d~%d\n",s.ID[j],s.size[j],s.phy_Add1[j],s.phy_Add1[j],s.phy_Add2[j]);
    }
    printf("============================================\n");
    return s;
}

int page_mode(){

    page p1 = Initialization();    //执行初始化页表，并且将之前页表的信息传给主函数 

     while(1){    //循环想要输入逻辑地址            
        int l_Add;
        int p_number,offset;      
        printf("请输入十进制的逻辑地址\n"); 
        scanf("%d",&l_Add);
        p_number = l_Add/SIZE; //算出页号
        offset = l_Add%SIZE;   //算出偏移值

         if(p_number>n||l_Add<0){
            if(p_number>n){
                printf("错误，超出最大页面值,请重新输入\n");
            }
            else{
                 printf("输入错误,请重新输入\n");
            }
         }
        else{ 
            int f_number;   
            int p_Add;   //初始化物理地址
            f_number = p1.Coresponding_frame[p_number]; //找出页号所对应的帧号
            p_Add = f_number*SIZE+offset; //算出物理地址
            printf("逻辑地址为%d的物理地址是%d\n",l_Add,p_Add);
        }
        printf("是否需要继续输入？输入1则继续输入测试，输入1以外的则退出程序并重新输入页表\n");
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
    while(1){    //循环想要输入逻辑地址            
        int l_Add;
        int offset;      
        printf("逻辑地址输入：请输入逻辑段号\n"); 
        scanf("%d",&l_Add);
        printf("请输入段内偏移值\n"); 
        scanf("%d",&offset);
         if(l_Add>m||l_Add<0||offset>=s1.size[l_Add]){  //如果段号大于0，偏移量超过，或者无效输入
            if(l_Add>m){
                printf("错误，超出短号最大值,请重新输入\n");
            }
            else if(offset>s1.size[l_Add]){
                printf("错误,偏移量超过界限,请重新输入\n");

            }
            else{
                 printf("输入错误,请重新输入\n");
            }
         }
        else{ 
            int p_Add;
            p_Add = s1.phy_Add1[l_Add]+offset;  //算出物理地址
            printf("逻辑地址段号为%d偏移量为%d的物理地址是%d\n",l_Add,offset,p_Add);
        }
        printf("是否需要继续输入？输入1则继续输入测试，输入1以外的则退出程序并重新输入页表\n");
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
    cout<<"-------欢迎来到地址转换系统-------"<<endl;
    cout<<endl;
    cout<<"---------------1.分页---------------------"<<endl;
    cout<<"---------------2.分段----------------------"<<endl;
    cout<<"---------------3.退出----------------------"<<endl;
    cout<<""<<endl;
    cout<<"-----作者: 刘建中 -学号: 11719720418-----"<<endl;
    cout<<endl;
    cout<<"-----请输入转换逻辑地址的方式(1~3)-----"<<endl;
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
        cout<< "输入无效，请重新输入"<<endl;  
         break; 
        
    }
    }
}



int main(){
    menu();
    return 0;
}