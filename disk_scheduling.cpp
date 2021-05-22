#include<stdio.h>
 
#include<stdlib.h>
 
#include<conio.h>
 
#include<string.h>
 
#include<windows.h>
 
#include <math.h>
 
#include <iostream>
using namespace std;

int disk[1000];  //����ŵ������ݽṹ 
int initial; //��ʼ�Ĵ�ͷ
int number;  //�ŵ������� 



int create(){
    int a;
    cout<<"�������ʼ�ŵ�"<<endl;
    cin>>initial;
    if(initial<0){
        cout<<"�������,������������˳�"<<endl;
        getch();
        system("cls");
        return 0;
    }
    cout<<"������ŵ�������"<<endl;
    cin>>number;
    for(int i=0; i<number;i++){
        printf("������ŵ�%d\n",i+1);
        cin>>disk[i];         //����ŵ�
        if(disk[i]<0){
            cout<<"�������,������������˳�\n"<<endl;
            getch();
            system("cls");
            return 0;
        }            

    }
    
    cout<<"������Ĵŵ�˳��Ϊ"<<endl;
    for(int i=0;i<number;i++){
        printf("�ŵ�%dΪ: %d\n",i+1,disk[i]);
    } 
    printf("�����ɹ����밴������˳�����....\n");
    getch();
    system("cls");
    return 0;
        
}

int FCFS(){
    int length[number];  //��ʾ�ƶ�����
    int temp;   //��¼��ǰλ��
    int sum=0;     //��¼�ܹ�λ��
    printf("��ӭ���������ȷ������(�Ӵŵ�%d��ʼ)\n",initial);
    temp =initial; //�ȼ�¼initial��λ��
    if(!number){
        printf("�봴���ŵ�!\n");
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
    printf("�����ʵĴŵ�˳��\t\t\t�ŵ����ƶ�����\n");
    for(int i=0; i<number; i++){
        printf("\t%d\t\t\t\t\t%d\n",disk[i],length[i]);
    }
    printf("\n");
    printf("Ѱ���ܳ���Ϊ��%d\n",sum);
    printf("ƽ��Ѱ������Ϊ��%.2lf\n",avg);
    printf("�밴������˳�....\n");
    getch();
    system("cls");
    return 0;
}

int SSTF(){
    int length[number];  //��ʾ�ƶ�����
    int sequence[number];  // ��¼˳��
    int temp,k;   //��¼��ǰλ��
    int sum=0;     //��¼�ܹ�λ��
    printf("��ӭ���������ȷ������(�Ӵŵ�%d��ʼ)\n",initial);
    temp =initial; //�ȼ�¼initial��λ��
    if(!number){
        printf("�봴���ŵ�!\n");
        return 0;
    }
    int gap[number]; //��¼��ͷ������ŵ���λ��
    int flag[number];

    for(int i = 0; i<number;i++){    //ȫ����Ϊ0
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

        flag[k] = 0;  //���Ϊ0�������ٱȽ���
        temp = disk[k]; //��¼��ͷ���ڵ�λ��
        sequence[i] = k; 
    }
     

    
    double avg = (double)sum/number;  //����ƽ��

    printf("�����ʵĴŵ�˳��\t\t\t�ŵ����ƶ�����\n");
     
    int record;                       //��¼sequence�е�˳��

    for(int i = 0; i<number; i++){
        record = sequence[i]; 
        printf("\t%d\t\t\t\t\t%d\n",disk[record],length[record]);
    }
    printf("\n");
    printf("Ѱ���ܳ���Ϊ��%d\n",sum);
    printf("ƽ��Ѱ������Ϊ��%.2lf\n",avg);
    printf("�밴������˳�....\n");
    getch();
    system("cls");
    return 0;
}




int interface1(){

    int input;
    while(1){
    cout<<"-------��ӭ�������̵���ϵͳ-------"<<endl;
    cout<<endl;
     cout<<"-------��û�����ŵ������ȴ����ŵ���-------"<<endl;
    cout<<"---------------1.�����ŵ�---------------------"<<endl;
    cout<<"---------------2.FCFS����----------------------"<<endl;
    cout<<"---------------3.SSTF����----------------------"<<endl;
    cout<<"---------------4.�˳�----------------------"<<endl;
    cout<<""<<endl;
    cout<<"-----����: ������ -ѧ��: 11719720418-----"<<endl;
    cout<<endl;
    cout<<"-----��������̵��ȵķ�ʽ(1~4)-----"<<endl;
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
        cout<< "������Ч������������"<<endl;  
        break; 
        
      }
    }
}

int main(){
    interface1();
    return 0;
}