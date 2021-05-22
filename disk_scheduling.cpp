#include<stdio.h>
 
#include<stdlib.h>
 
#include<conio.h>
 
#include<string.h>
 
#include<windows.h>
 
#include <math.h>
 
#include <iostream>
using namespace std;

int disk[1000];  //储存磁道的数据结构 
int initial; //初始的磁头
int number;  //磁道的数量 



int create(){
    int a;
    cout<<"请输入初始磁道"<<endl;
    cin>>initial;
    if(initial<0){
        cout<<"输入错误,按任意键程序退出"<<endl;
        getch();
        system("cls");
        return 0;
    }
    cout<<"请输入磁道的数量"<<endl;
    cin>>number;
    for(int i=0; i<number;i++){
        printf("请输入磁道%d\n",i+1);
        cin>>disk[i];         //输入磁道
        if(disk[i]<0){
            cout<<"输入错误,按任意键程序退出\n"<<endl;
            getch();
            system("cls");
            return 0;
        }            

    }
    
    cout<<"您输入的磁道顺序为"<<endl;
    for(int i=0;i<number;i++){
        printf("磁道%d为: %d\n",i+1,disk[i]);
    } 
    printf("创建成功，请按任意键退出创建....\n");
    getch();
    system("cls");
    return 0;
        
}

int FCFS(){
    int length[number];  //表示移动距离
    int temp;   //记录当前位置
    int sum=0;     //记录总共位移
    printf("欢迎来到先来先服务调度(从磁道%d开始)\n",initial);
    temp =initial; //先记录initial的位置
    if(!number){
        printf("请创建磁道!\n");
        return 0;
    }
    for(int i=0;i<number;i++){
        
        if(disk[i]<temp){
            length[i]=temp-disk[i];
            temp = disk[i]; 
        }
        else{
            length[i]=disk[i]-temp;
            temp = disk[i];
        }
        sum += length[i];
    }
    double avg = (double)sum/number;
    printf("被访问的磁道顺序\t\t\t磁道号移动距离\n");
    for(int i=0; i<number; i++){
        printf("\t%d\t\t\t\t\t%d\n",disk[i],length[i]);
    }
    printf("\n");
    printf("寻道总长度为：%d\n",sum);
    printf("平均寻道距离为：%.2lf\n",avg);
    printf("请按任意键退出....\n");
    getch();
    system("cls");
    return 0;
}

int SSTF(){
    int length[number];  //表示移动距离
    int sequence[number];  // 记录顺序
    int temp,k;   //记录当前位置
    int sum=0;     //记录总共位移
    printf("欢迎来到先来先服务调度(从磁道%d开始)\n",initial);
    temp =initial; //先记录initial的位置
    if(!number){
        printf("请创建磁道!\n");
        return 0;
    }
    int gap[number]; //记录磁头与各个磁道的位置
    int flag[number];

    for(int i = 0; i<number;i++){    //全部设为0
        flag[i] =1; 
    }
    

    for(int i=0;i<number;i++){
    
        int min=1000; 

        for(int j=0; j<number;j++){
            if(flag[j]){   
                if(temp>disk[j]){
                    gap[j]=temp-disk[j];
                    if(gap[j]<min){
                        min = gap[j];
                        k = j; 
                    }
                }
                else{
                    gap[j]=disk[j]-temp;
                     if(gap[j]<min){
                        min = gap[j];
                        k = j; 
                    }
                }
            }
           // printf("%d\n",min);   
        }

        if(temp>disk[k]){
            length[k] = temp-disk[k];
            sum+=length[k];
        }
        else{
            length[k]= disk[k] - temp;
            sum+=length[k];
        }

        flag[k] = 0;  //标记为0，不会再比较它
        temp = disk[k]; //记录磁头所在的位置
        sequence[i] = k; 
    }
     

    
    double avg = (double)sum/number;  //计算平均

    printf("被访问的磁道顺序\t\t\t磁道号移动距离\n");
     
    int record;                       //记录sequence中的顺序

    for(int i = 0; i<number; i++){
        record = sequence[i]; 
        printf("\t%d\t\t\t\t\t%d\n",disk[record],length[record]);
    }
    printf("\n");
    printf("寻道总长度为：%d\n",sum);
    printf("平均寻道距离为：%.2lf\n",avg);
    printf("请按任意键退出....\n");
    getch();
    system("cls");
    return 0;
}




int interface1(){

    int input;
    while(1){
    cout<<"-------欢迎来到磁盘调度系统-------"<<endl;
    cout<<endl;
     cout<<"-------若没创建磁道，请先创建磁道！-------"<<endl;
    cout<<"---------------1.创建磁道---------------------"<<endl;
    cout<<"---------------2.FCFS调度----------------------"<<endl;
    cout<<"---------------3.SSTF调度----------------------"<<endl;
    cout<<"---------------4.退出----------------------"<<endl;
    cout<<""<<endl;
    cout<<"-----作者: 刘建中 -学号: 11719720418-----"<<endl;
    cout<<endl;
    cout<<"-----请输入磁盘调度的方式(1~4)-----"<<endl;
    cin>>input;
    switch(input){
        case 1:
        create();
        break;
         
        case 2:
        FCFS();
        break;

        case 3:
        SSTF();
        break;


        case 4:
        return 0;
          
        default:
        cout<< "输入无效，请重新输入"<<endl;  
        break; 
        
      }
    }
}

int main(){
    interface1();
    return 0;
}