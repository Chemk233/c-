#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500//����N
struct DRIVER//����DRIVER�Ľṹ��
{
	int NUMBER;//��������
	char NAME[20];//��ʻԱ����
	char ID[20];//���ƺ�
	char kind[10];//Υ�����
	int money;//������
	char name[20];//��������
	int year;//����ʱ�䣨�꣩
	int month;//��
	int day;//��
}driver[N];//������
void luru()//��Ϣ¼��
{
	int removex(int m);
	int i,j,m;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//���ļ���
	{
		if((fp=fopen("list.txt","w"))==NULL)//�����ļ���
		{
			printf("�ļ��򿪻򴴽�ʧ��,�������˵�\n");
			exit(0);
		}
	}	
    else
	{
	for(i=0;!feof(fp);i++)
	{
		fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
	}
	    m=i-1;//���淣������
	    printf("\n�� ��Ϣ¼�� ��\n");
	    printf("***********************************************************\n");
        printf("\n������Ҫ¼��ķ������:\n");
	    scanf("%d",&j);
		for(i=m;i<j+m;i++)
		{
			printf("�������%d�ŷ��:\n",i+1);
			printf("\n �������� ��ʻԱ���� ���ƺ� �����Ԫ�� �������� ����ʱ�䣨�� �� �գ�\n");//���뷣�
			scanf("%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
			fprintf(fp,"%d %s %s %s %d %s %d %d %d\n",driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
			printf("��%d�ŷ����Ϣ����ɹ�\n",i+1);
		}
		fclose(fp);
		removex(j+m);////�ı��ؽ�
		printf("\nȫ������ɹ�,���»س�,�������˵�\n");
		getchar();
		getchar();
	}
}
void change()//��Ϣ�޸�
{
	int removex(int m);
	int i,j,m,n=-1;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//���ļ���
	{
		printf("�ļ��򿪻򴴽�ʧ��,�������˵�\n");
	}
	else
	{
		for(i=0;!feof(fp);i++)
		{
		fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
		}
		m=i;
	    fclose(fp);
	    printf("\n�� ��Ϣ�޸� ��\n");
	    printf("***********************************************************\n");
		printf("\n�����뽫�޸ĵķ���ķ����\n");
	    scanf("%d",&j);
	    for(i=0;i<m;i++)
		{
		    if(j==driver[i].NUMBER)//Ѱ��Ҫ�޸ĵķ��
			{
			    printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
                printf("----------------------------------------------------------------------------------------------------------\n");
		        printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	            printf("       |--------------------------------------------------------------------------------------------------\n");
		        printf("\n��ѡ���޸ĵ�����\n");
                printf("1_��ʻԱ����\n");
	            printf("2_���ƺ�\n");
				printf("3_Υ�����\n");
				printf("4_������\n");
	            printf("5_��������\n");
	            printf("6_����ʱ��\n");
	            printf("��ѡ��1-6��:\n");
	            scanf("%d",&j);
			    switch(j)
				{
					case(1)://�޸ļ�ʻԱ����
					{
			              printf("�����������ʻԱ����:\n");
			              scanf("%s",&driver[i].NAME);
					      printf("���޸�Ϊ\n");
	                      printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(2)://�޸ĳ��ƺ�
					{
			              printf("���������복�ƺ�:\n");
			              scanf("%s",&driver[i].ID);
					      printf("���޸�Ϊ\n");
	                      printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(3)://�޸�Υ�����
					{
			              printf("����������Υ�����:\n");
			              scanf("%s",&driver[i].kind);
					      printf("���޸�Ϊ\n");
	                      printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(4)://�޸Ľ��
					{
			              printf("������������:\n");
			              scanf("%d",&driver[i].money);
					      printf("���޸�Ϊ\n");
	                      printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(5)://�޸Ľ�������
					{
			              printf("���������뽻������:\n");
			              scanf("%s",&driver[i].name);
					      printf("���޸�Ϊ\n");
	                      printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(6)://�޸Ĵ���ʱ��
					{
			              printf("���������봦��ʱ��:\n");
			              scanf("%d %d %d",&driver[i].year,&driver[i].month,&driver[i].day);
					      printf("���޸�Ϊ\n");
	                      printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
	                default:
					{
			             printf("����");
						 break;
					}
				}
              break;
			}
		}
		n=removex(m-1);//�ı��ؽ�
		printf("\n�޸ĳɹ�������س����������˵�\n");
	}
	if(n==-1)
	{
		  printf("�޷��ҵ����޸ĸ÷�������»س�,�������˵�\n");
	}
	getchar();
	getchar();
}
void chaxun()//��Ϣ��ѯ
{
	int i,j,n=1,year,month,day;
	char s[20];
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//���ļ���
	{
		printf("\n�ļ���ʧ�ܻ��ļ�������,���»س�,�������˵�\n");
	}
	else
	{
	    printf("\n�� ��Ϣ��ѯ ��\n");
	    printf("***********************************************************\n");
	    printf("��ѡ���ѯ��ʽ\n");
        printf("1_����ʻԱ������ѯ\n");
	    printf("2_�����ƺŲ�ѯ\n");
	    printf("3_������������ѯ\n");
	    printf("4_������ʱ���ѯ\n");
	    printf("��ѡ��1-4��:\n");
	    scanf("%d",&j);
	switch(j)
	{
	case(1)://����ʻԱ������ѯ
		{
			printf("�������ʻԱ����:\n");
			scanf("%s",&s);
			fp=fopen("list.txt","r");
			printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(strcmp(driver[i].NAME,s)==0)//��ѡ����ʾ����Ϣ��ƥ��ķ��
				{
	                printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n++;
				}
			}
			fclose(fp);
			break;
		}
	case(2)://�����ƺŲ�ѯ
		{
			printf("�����복�ƺ�:\n");
			scanf("%s",&s);
			fp=fopen("list.txt","r");
			printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(strcmp(driver[i].ID,s)==0)//��ѡ����ʾ����Ϣ��ƥ��ķ��
				{
	                printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n++;
				}
			}
			fclose(fp);
			break;
		}
	case(3)://������������ѯ
		{
			printf("�����뽻������:\n");
			scanf("%s",&s);
			fp=fopen("list.txt","r");
			printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(strcmp(driver[i].name,s)==0)//��ѡ����ʾ����Ϣ��ƥ��ķ��
				{
	                printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n++;
				}
			}
			fclose(fp);
			break;
		}
		case(4)://������ʱ���ѯ
		{
			printf("�����봦��ʱ��:����ȷ���� �� ��)\n");
			scanf("%d %d %d",&year,&month,&day);
			fp=fopen("list.txt","r");
			 printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(driver[i].year==year)//��ѡ����ʾ����Ϣ��ƥ��ķ��
				{
					if(driver[i].month==month)
					{
						if(driver[i].day==day)
						{
	                     printf("%4d   | %5d  %8s    %10s  %5s    %5d   %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                     printf("       |--------------------------------------------------------------------------------------------------\n");
				         n++;
						}
					}
				}
			}
			fclose(fp);
			break;
		}
	default:
		{
			printf("����");
		}
	}
	    if(n==1)
		{
			printf("         �޷��ҵ������Ϣ��ƥ��ķ��\n");
		}
	    printf("\n����س����������˵�\n");
	}
	getchar();
	getchar();
}
void del()//��Ϣɾ��
{
	int removex(int m);
	int i,j,m,n=-1;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//���ļ���
	{
		printf("\n�ļ���ʧ�ܻ��ļ�������,���»س�,�������˵�\n");
	}
    else
	{
		printf("\n�� ��Ϣɾ�� ��\n");
	    printf("***********************************************************\n");
        printf("\n������Ҫɾ���ķ����:\n");
	    scanf("%d",&j);
        for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(driver[i].NUMBER==j)//��ѡ����ʾ����Ϣ��ƥ��ķ��
				{
					printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
                    printf("----------------------------------------------------------------------------------------------------------\n");
	                printf("       | %5d  %8s    %10s  %5s    %5d    %8s     %4d��%2d��%2d��\n",driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n=i;
				}
			}
		    m=i;//���淣������
			fclose(fp);
         if(n!=-1)
		 {
	        for(i=n;i<m;i++)//ɾ��ģ�飬��ɾ�������ķ��������ϸ��ƣ�����Ҫɾ���ķ��
			{
		       driver[i].NUMBER=driver[i+1].NUMBER;
		       strcpy(driver[i].NAME,driver[i+1].NAME);
		       strcpy(driver[i].ID,driver[i+1].ID);
               strcpy(driver[i].kind,driver[i+1].kind);
		       driver[i].money=driver[i+1].money;
		       strcpy(driver[i].name,driver[i+1].name);
		       driver[i].year=driver[i+1].year;
		       driver[i].month=driver[i+1].month;
		       driver[i].day=driver[i+1].day;
			}
	        printf("\nɾ���÷���С�����\n");	
	        n=removex(m-2);
			printf("\nɾ���÷���ɹ������»س�,�������˵�\n");		
		 }
		 else
	{
		printf("�޷��ҵ���ɾ���÷�������»س�,�������˵�\n");
	}
	}
	getchar();
	getchar();
}
int removex(int m)//�ı��ؽ����ؽ�һ�����ı�������ԭ���ľ��ı�
{
	FILE *fp1;
	int i,n=-1;
	if((fp1=fopen("list2.txt","w"))==NULL)//�����ļ���
	{
		printf("�ļ����´���ʧ��\n");
		return (n);
	}
	for(i=0;i<m;i++)
	{
		fprintf(fp1,"%d %s %s %s %d %s %d %d %d\n",driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	}
	fclose(fp1);
	getchar();
	getchar();
	remove("list.txt");		
    rename("list2.txt", "list.txt");
	return(i);
}
void look()//��Ϣ���
{
	int i;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//���ļ���
	{
    	printf("\n�ļ���ʧ�ܻ��ļ�������,���»س�,�������˵�\n");
	}
	else
	{
	    printf("\n�� ��Ϣ��� ��\n");
	    printf("***********************************************************\n");
	    printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
	for(i=0;!feof(fp);i++)
	{
	    fscanf(fp,"%d %s %s %s %d %s %d %d %d\n",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
	    //--------------------------------------------------------------------------------------------------------
	    printf("%4d   | %5d  %8s    %10s  %5s    %5d   %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	    printf("       |--------------------------------------------------------------------------------------------------\n");
	}
	    fclose(fp);
	    printf("\n����س����������˵�\n");
	}
	getchar();
	getchar();
}
void tongji()//������Ϣͳ��
{
	int i,j,n=1,s=0,year,month;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//���ļ���
	{
    	printf("\n�ļ���ʧ�ܻ��ļ�������,���»س�,�������˵�\n");
	}
	else
	{
		printf("\n�� ��Ϣͳ�� ��\n");
	    printf("***********************************************************\n");
	    printf("��ѡ��ͳ�Ʒ�ʽ\n");
	    printf("1_ͳ��ĳһ��\n");
        printf("2_ͳ��ĳһ��\n");
	    printf("��ѡ��1-2��:\n");
	    scanf("%d",&j);
	switch(j)
	{
	case(1)://ͳ��ĳһ��
		{
			printf("������ʱ�䣨�꣩:\n");
			scanf("%d",&year);
			fp=fopen("list.txt","r");
			printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d\n",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(driver[i].year==year)//��ѡ����ʾ����Ϣ��ƥ��ķ��
				{
	                printf("%4d   | %5d  %8s    %10s  %5s    %5d   %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n++;
					s+=driver[i].money;
				}
			}
				break;
		}
	case(2)://ͳ��ĳһ��
		{
			printf("������ʱ�䣨�� �£�:\n");
			scanf("%d %d",&year,&month);
			fp=fopen("list.txt","r");
			printf("������  ��������  ��ʻԱ����   ���ƺ�   Υ�����  ������    ��������   ����ʱ�䣨�� �� �գ�\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(driver[i].year==year)//��ѡ����ʾ����Ϣ��ƥ��ķ��
				{
					if(driver[i].month==month)
					{
	                    printf("%4d   | %5d  %8s    %10s  %5s    %5d   %8s     %4d��%2d��%2d��\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                    printf("       |--------------------------------------------------------------------------------------------------\n");
					    n++;
						s+=driver[i].money;
					}
				}
			}		
			break;
		}
	}
	fclose(fp);
	printf("��ʱ��η������Ϊ %d \n",n-1);
	printf("��ʱ��η���ܽ����Ϊ %d Ԫ\n",s);
	printf("\nͳ�Ƹ�ʱ��η���ɹ������»س�,�������˵�\n");
	}
	getchar();
	getchar();
}
void menu()//�˵�
{
	printf("\n��ӭ������ͨ����������ϵͳ\n");
	printf("\n");
	printf("\n");
	printf("�� ���˵� ��\n");
	printf("***********************************************************\n");
	printf("              ��  1.������Ϣ¼��  ��\n"); 
	printf("              ��  2.������Ϣ�޸�  ��\n"); 
	printf("              ��  3.������Ϣ��ѯ  ��\n"); 
	printf("              ��  4.������Ϣɾ��  ��\n");
	printf("              ��  5.������Ϣ���  ��\n");
	printf("              ��  6.������Ϣͳ��  ��\n");
	printf("              ��  0.�˳�����ϵͳ  ��\n"); 
    printf("***********************************************************\n");
}
void main()
{
	void luru();
	void change();
	void chaxun();
	void del();
	void look();
	void tongji();
	int n;
	while(1)//����ѡ��ģ��
	{   
		system("cls");//����ʱ����
		menu();
		printf("\n������ѡ����(0-6):");
		scanf("%d",&n);
		system("cls");//����ʱ����
		switch(n)
		{
		case 1:
			luru();
			break;
		case 2:
			change();
			break;
		case 3:
			chaxun();
			break;
		case 4:
			del();
			break;
		case 5:
			look();
			break;
		case 6:
			tongji();
			break;
		case 0:
			exit(0);
		default:
			printf("����ѡ��,����س����������˵�");
			getchar();
			getchar();
			break;
		}
	}
}