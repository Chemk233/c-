#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500//声明N
struct DRIVER//定义DRIVER的结构体
{
	int NUMBER;//处罚单号
	char NAME[20];//驾驶员姓名
	char ID[20];//车牌号
	char kind[10];//违章类别
	int money;//罚款金额
	char name[20];//交警姓名
	int year;//处罚时间（年）
	int month;//月
	int day;//日
}driver[N];//数组名
void luru()//信息录入
{
	int removex(int m);
	int i,j,m;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//打开文件夹
	{
		if((fp=fopen("list.txt","w"))==NULL)//创建文件夹
		{
			printf("文件打开或创建失败,返回主菜单\n");
			exit(0);
		}
	}	
    else
	{
	for(i=0;!feof(fp);i++)
	{
		fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
	}
	    m=i-1;//缓存罚单总数
	    printf("\n※ 信息录入 ※\n");
	    printf("***********************************************************\n");
        printf("\n请输入要录入的罚款单数量:\n");
	    scanf("%d",&j);
		for(i=m;i<j+m;i++)
		{
			printf("请输入第%d张罚款单:\n",i+1);
			printf("\n 处罚单号 驾驶员姓名 车牌号 罚款金额（元） 交警姓名 处罚时间（年 月 日）\n");//输入罚款单
			scanf("%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
			fprintf(fp,"%d %s %s %s %d %s %d %d %d\n",driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
			printf("第%d张罚款单信息输入成功\n",i+1);
		}
		fclose(fp);
		removex(j+m);////文本重建
		printf("\n全部保存成功,按下回车,返回主菜单\n");
		getchar();
		getchar();
	}
}
void change()//信息修改
{
	int removex(int m);
	int i,j,m,n=-1;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//打开文件夹
	{
		printf("文件打开或创建失败,返回主菜单\n");
	}
	else
	{
		for(i=0;!feof(fp);i++)
		{
		fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
		}
		m=i;
	    fclose(fp);
	    printf("\n※ 信息修改 ※\n");
	    printf("***********************************************************\n");
		printf("\n请输入将修改的罚款单的罚款单号\n");
	    scanf("%d",&j);
	    for(i=0;i<m;i++)
		{
		    if(j==driver[i].NUMBER)//寻找要修改的罚款单
			{
			    printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
                printf("----------------------------------------------------------------------------------------------------------\n");
		        printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	            printf("       |--------------------------------------------------------------------------------------------------\n");
		        printf("\n请选择将修改的内容\n");
                printf("1_驾驶员姓名\n");
	            printf("2_车牌号\n");
				printf("3_违规类别\n");
				printf("4_罚款金额\n");
	            printf("5_交警姓名\n");
	            printf("6_处罚时间\n");
	            printf("请选择（1-6）:\n");
	            scanf("%d",&j);
			    switch(j)
				{
					case(1)://修改驾驶员姓名
					{
			              printf("请重新输入驾驶员姓名:\n");
			              scanf("%s",&driver[i].NAME);
					      printf("已修改为\n");
	                      printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(2)://修改车牌号
					{
			              printf("请重新输入车牌号:\n");
			              scanf("%s",&driver[i].ID);
					      printf("已修改为\n");
	                      printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(3)://修改违规类别
					{
			              printf("请重新输入违规类别:\n");
			              scanf("%s",&driver[i].kind);
					      printf("已修改为\n");
	                      printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(4)://修改金额
					{
			              printf("请重新输入金额:\n");
			              scanf("%d",&driver[i].money);
					      printf("已修改为\n");
	                      printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(5)://修改交警姓名
					{
			              printf("请重新输入交警姓名:\n");
			              scanf("%s",&driver[i].name);
					      printf("已修改为\n");
	                      printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
					case(6)://修改处罚时间
					{
			              printf("请重新输入处罚时间:\n");
			              scanf("%d %d %d",&driver[i].year,&driver[i].month,&driver[i].day);
					      printf("已修改为\n");
	                      printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
                          printf("----------------------------------------------------------------------------------------------------------\n");
		                  printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                      printf("       |--------------------------------------------------------------------------------------------------\n");
				          break;
					}
	                default:
					{
			             printf("错误");
						 break;
					}
				}
              break;
			}
		}
		n=removex(m-1);//文本重建
		printf("\n修改成功，点击回车，返回主菜单\n");
	}
	if(n==-1)
	{
		  printf("无法找到或修改该罚款单，按下回车,返回主菜单\n");
	}
	getchar();
	getchar();
}
void chaxun()//信息查询
{
	int i,j,n=1,year,month,day;
	char s[20];
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//打开文件夹
	{
		printf("\n文件打开失败或文件不存在,按下回车,返回主菜单\n");
	}
	else
	{
	    printf("\n※ 信息查询 ※\n");
	    printf("***********************************************************\n");
	    printf("请选择查询方式\n");
        printf("1_按驾驶员姓名查询\n");
	    printf("2_按车牌号查询\n");
	    printf("3_按交警姓名查询\n");
	    printf("4_按处罚时间查询\n");
	    printf("请选择（1-4）:\n");
	    scanf("%d",&j);
	switch(j)
	{
	case(1)://按驾驶员姓名查询
		{
			printf("请输入驾驶员姓名:\n");
			scanf("%s",&s);
			fp=fopen("list.txt","r");
			printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(strcmp(driver[i].NAME,s)==0)//挑选并显示与信息所匹配的罚款单
				{
	                printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n++;
				}
			}
			fclose(fp);
			break;
		}
	case(2)://按车牌号查询
		{
			printf("请输入车牌号:\n");
			scanf("%s",&s);
			fp=fopen("list.txt","r");
			printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(strcmp(driver[i].ID,s)==0)//挑选并显示与信息所匹配的罚款单
				{
	                printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n++;
				}
			}
			fclose(fp);
			break;
		}
	case(3)://按交警姓名查询
		{
			printf("请输入交警姓名:\n");
			scanf("%s",&s);
			fp=fopen("list.txt","r");
			printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(strcmp(driver[i].name,s)==0)//挑选并显示与信息所匹配的罚款单
				{
	                printf("%4d   | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n++;
				}
			}
			fclose(fp);
			break;
		}
		case(4)://按处罚时间查询
		{
			printf("请输入处罚时间:（精确到年 月 日)\n");
			scanf("%d %d %d",&year,&month,&day);
			fp=fopen("list.txt","r");
			 printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(driver[i].year==year)//挑选并显示与信息所匹配的罚款单
				{
					if(driver[i].month==month)
					{
						if(driver[i].day==day)
						{
	                     printf("%4d   | %5d  %8s    %10s  %5s    %5d   %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
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
			printf("错误");
		}
	}
	    if(n==1)
		{
			printf("         无法找到与该信息所匹配的罚款单\n");
		}
	    printf("\n点击回车，返回主菜单\n");
	}
	getchar();
	getchar();
}
void del()//信息删除
{
	int removex(int m);
	int i,j,m,n=-1;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//打开文件夹
	{
		printf("\n文件打开失败或文件不存在,按下回车,返回主菜单\n");
	}
    else
	{
		printf("\n※ 信息删除 ※\n");
	    printf("***********************************************************\n");
        printf("\n请输入要删除的罚款单号:\n");
	    scanf("%d",&j);
        for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(driver[i].NUMBER==j)//挑选并显示与信息所匹配的罚款单
				{
					printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
                    printf("----------------------------------------------------------------------------------------------------------\n");
	                printf("       | %5d  %8s    %10s  %5s    %5d    %8s     %4d年%2d月%2d日\n",driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n=i;
				}
			}
		    m=i;//缓存罚单总数
			fclose(fp);
         if(n!=-1)
		 {
	        for(i=n;i<m;i++)//删除模块，将删除罚款单后的罚款单逐层向上复制，覆盖要删除的罚款单
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
	        printf("\n删除该罚款单中。。。\n");	
	        n=removex(m-2);
			printf("\n删除该罚款单成功，按下回车,返回主菜单\n");		
		 }
		 else
	{
		printf("无法找到或删除该罚款单，按下回车,返回主菜单\n");
	}
	}
	getchar();
	getchar();
}
int removex(int m)//文本重建，重建一个新文本，覆盖原来的久文本
{
	FILE *fp1;
	int i,n=-1;
	if((fp1=fopen("list2.txt","w"))==NULL)//创建文件夹
	{
		printf("文件重新创建失败\n");
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
void look()//信息浏览
{
	int i;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//打开文件夹
	{
    	printf("\n文件打开失败或文件不存在,按下回车,返回主菜单\n");
	}
	else
	{
	    printf("\n※ 信息浏览 ※\n");
	    printf("***********************************************************\n");
	    printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
	for(i=0;!feof(fp);i++)
	{
	    fscanf(fp,"%d %s %s %s %d %s %d %d %d\n",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
	    //--------------------------------------------------------------------------------------------------------
	    printf("%4d   | %5d  %8s    %10s  %5s    %5d   %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	    printf("       |--------------------------------------------------------------------------------------------------\n");
	}
	    fclose(fp);
	    printf("\n点击回车，返回主菜单\n");
	}
	getchar();
	getchar();
}
void tongji()//处罚信息统计
{
	int i,j,n=1,s=0,year,month;
	FILE *fp;
	if((fp=fopen("list.txt","r+"))==NULL)//打开文件夹
	{
    	printf("\n文件打开失败或文件不存在,按下回车,返回主菜单\n");
	}
	else
	{
		printf("\n※ 信息统计 ※\n");
	    printf("***********************************************************\n");
	    printf("请选择统计方式\n");
	    printf("1_统计某一年\n");
        printf("2_统计某一月\n");
	    printf("请选择（1-2）:\n");
	    scanf("%d",&j);
	switch(j)
	{
	case(1)://统计某一年
		{
			printf("请输入时间（年）:\n");
			scanf("%d",&year);
			fp=fopen("list.txt","r");
			printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d\n",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(driver[i].year==year)//挑选并显示与信息所匹配的罚款单
				{
	                printf("%4d   | %5d  %8s    %10s  %5s    %5d   %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
	                printf("       |--------------------------------------------------------------------------------------------------\n");
					n++;
					s+=driver[i].money;
				}
			}
				break;
		}
	case(2)://统计某一月
		{
			printf("请输入时间（年 月）:\n");
			scanf("%d %d",&year,&month);
			fp=fopen("list.txt","r");
			printf("※※※  处罚单号  驾驶员姓名   车牌号   违章类别  罚款金额    交警姓名   处罚时间（年 月 日）\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			for(i=0;!feof(fp);i++)
			{
				fscanf(fp,"%d %s %s %s %d %s %d %d %d",&driver[i].NUMBER,&driver[i].NAME,&driver[i].ID,&driver[i].kind,&driver[i].money,&driver[i].name,&driver[i].year,&driver[i].month,&driver[i].day);
				if(driver[i].year==year)//挑选并显示与信息所匹配的罚款单
				{
					if(driver[i].month==month)
					{
	                    printf("%4d   | %5d  %8s    %10s  %5s    %5d   %8s     %4d年%2d月%2d日\n",i+1,driver[i].NUMBER,driver[i].NAME,driver[i].ID,driver[i].kind,driver[i].money,driver[i].name,driver[i].year,driver[i].month,driver[i].day);
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
	printf("该时间段罚款单总数为 %d \n",n-1);
	printf("该时间段罚款单总金额数为 %d 元\n",s);
	printf("\n统计该时间段罚款单成功，按下回车,返回主菜单\n");
	}
	getchar();
	getchar();
}
void menu()//菜单
{
	printf("\n欢迎来到交通处罚单管理系统\n");
	printf("\n");
	printf("\n");
	printf("※ 主菜单 ※\n");
	printf("***********************************************************\n");
	printf("              ▲  1.车辆信息录入  ▲\n"); 
	printf("              ▲  2.车辆信息修改  ▲\n"); 
	printf("              ▲  3.车辆信息查询  ▲\n"); 
	printf("              ▲  4.车辆信息删除  ▲\n");
	printf("              ▲  5.车辆信息浏览  ▲\n");
	printf("              ▲  6.处罚信息统计  ▲\n");
	printf("              ▲  0.退出管理系统  ▲\n"); 
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
	while(1)//功能选择模块
	{   
		system("cls");//返回时清屏
		menu();
		printf("\n请输入选择项(0-6):");
		scanf("%d",&n);
		system("cls");//出发时清屏
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
			printf("错误选项,点击回车，返回主菜单");
			getchar();
			getchar();
			break;
		}
	}
}