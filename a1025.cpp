#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
struct node{
	char id[13];
	int score;
	int r;
	int l;
	int lr;
}stu[30010];

bool cmp(node a, node b){
	if(a.score != b.score)
		return a.score > b.score;
	else 
		return strcmp(a.id, b.id)<0;
}

int main(){
	int n;
	scanf("%d", &n);
	int k;
	int l = 1;
	int count = 0;
	// 输入
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		int j;
		for(j = 0; j < k; j++){
			scanf("%s %d", stu[count].id, &stu[count].score);
			stu[count].l = l;
			count++;

		}
		sort(stu+count-j, stu+count, cmp);
		stu[count-j].lr = 1;
		for(int i = count-j; i < count; i++){
		if(stu[i].score == stu[i-1].score)
			stu[i].lr = stu[i-1].lr;
		else
			stu[i].lr = i + 1 - (count - j);
	}
		l++;
	}
	// 总排序
	sort(stu, stu+count+1, cmp);
	stu[0].r = 1;
	for(int i = 1; i < count; i++){
		if(stu[i].score == stu[i-1].score)
			stu[i].r = stu[i-1].r;
		else
			stu[i].r = i + 1;
	}


	// 输出
	for(int i = 0; i < count; i++){
		printf("%s %d %d %d\n", stu[i].id, stu[i].r, stu[i].l, stu[i].lr);
	}


	return 0;
}