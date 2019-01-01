/*
date：2019/01/01
author:BetterMe1
program:确定比赛名次、判断凶手、打印杨辉三角
compiler:Visual Studio 2013
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
1.
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。 
*/
//int main(){
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;//a,b,c,d,e用来存放运动员的名次
//	//利用循环遍历每一种情况，当每位选手都说对了一半时输出
//	for (a = 1; a < 6; a++){
//		for (b = 1; b < 6; b++){
//			for (c = 1; c < 6; c++){
//				for (d = 1; d < 6; d++){
//					for (e = 1; e < 6; e++){
//						//保证五个人名次不相等
//						//异或操作使得每位运动员只说对一半时结果为1
//						if (a != b && a != c && a != d && a != e &&
//							b != c && b != d && b != e && c != d &&
//							c != e && d != e && ((b == 2) ^ (a == 3))
//							&& ((b == 2) ^ (e == 4)) && ((c == 1) ^ (d == 2))
//							&& ((c == 5) ^ (d == 3)) && ((e == 4) ^ (a == 1))){//另一种表示异或的方法如：(e == 4) + (a == 1)=1,当两种情况满足一种时为1
//							printf("A选手是第%d名，B选手是第%d名，C选手是第%d名，D选手是第%d名，E选手是第%d名。\n", a, b, c, d, e);
//							break;
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

/*
2.
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
嫌疑犯的一个。以下为4个嫌疑犯的供词。
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。
*/
 
////此处为本人碎碎念：看到此题第一反应竟然是说假话的就一定是凶手吗（可能是脑回路比较清奇），
////查了一下原题貌似还都是上面这样，找出凶手这是在为难我胖虎，不过找出说谎的人还是可以滴，
////下面就默认骗警察叔叔的为凶手。
//int main(){
//	//遍历所有人，条件满足(3个人说真话，1个人说假话)时输出
//	for (char murderer = 'A'; murderer <= 'E'; murderer++){
//		if ((murderer != 'A') + (murderer == 'C') + (murderer == 'D') + (murderer != 'D') == 3){
//			printf("凶手是：%c\n", murderer);
//		}
//	}
//	system("pause");
//	return 0;
//}

/*
3.在屏幕上打印杨辉三角。
1
1 1
1 2 1
1 3 3 1
*/
void Yanghui(int n){//n表示几行
	int num[100][100] = { 0 };
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			if (j == 1 || j == i){
				num[i][j] = 1;//每行的第一个和最后一个都为1
			}
			else{
				num[i][j] = num[i - 1][j - 1] + num[i - 1][j];//其他元素的值是上方元素和左上方元素之和
			}
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int n = 0;
	printf("请输入打印杨辉三角的行数：");
	scanf("%d", &n);
	Yanghui(n);
	system("pause");
	return 0;
}
