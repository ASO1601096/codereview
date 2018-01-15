#include <stdio.h>
#include <string.h>

#define MAX 128
/*                                               */
/*文字の連続回数を調べて、連続回数のnum変数を返す*/
/*                                               */
static int serial_check(const char* in_str,char str,int pos){
	int j=0;
	int num=0;
	while(in_04[pos+j]==str){
		j++;
		num++;
	}
	return num;
}
/*                                               */
/*４文字連続以上の文字の場合                     */
/*“＠「num」「str」”の3文字の圧縮文字列を作成し*/
/*出力ファイルの終端に貼り付ける                 */
/*                                               */
static void comp_write(char* out_str,const char str, int num){
	char comp_str[4]={0};
	comp_str[0]='@';
	comp_str[1]=str;
	comp_str[2]=num+'0';                                /*数字を文字に変更する*/
	strcat(out_str,comp_str);                            /*作成した文字列を出力ファイルに貼り付ける*/	
	
}
/*                                               */
/*４文字連続未満の文字の場合                     */
/*num回連続のstr文字列を作成し                   */
/*出力ファイルの終端に貼り付ける                 */
/*                                               */
static void as_write(char* out_str,const char str, int num){
	char cons_str[4]={0};
	int j=0;
	while(num>0){
		cons_str[j]=str;
		j++;
		num--;
	}
	strcat(out_str,cons_str);                            /*作成した文字列を出力ファイルに貼り付ける*/
}
/*                                               */
/*              メイン関数                       */
/*                                               */
int main(void){
	
	int i=0,number;
	char in_04[MAX]={0};
	char out_04[MAX]={0};	
	char str;
	FILE *fp;	                             /* (1)ファイルポインタの宣言 */
	
	fp = fopen("in_04.txt","w");      	     /*ファイルを書き込みモードで開く*/
	
	if(fp==NULL){
	    printf("ファイルオープン失敗\n");	 /*ファイルオープンに失敗した場失敗と表示し終了*/
	    return -1;
	}

	printf("文字列を入力してください：\n");
	gets(in_04);                             /*入力した文字列を受け取る*/
	
	fprintf(fp,"%s",in_04);                  /*文字列をファイルに書き込む*/

	while(in_04[i]!='\0'){
		str=in_04[i];
		number=serial_check(in_04,str,i);                /*strの文字の連続をチェック*/
		if(number<4){
			as_write(out_04,str,number);                 /*そのままout_04ファイルに書き込む*/
		}else{
			comp_write(out_04,str,number);               /*圧縮文字列をout_04ファイルに書き込む*/
		}
		i+=number;                                       /*次の文字の位置に移動する*/
	}
	
	fclose(fp);
	
	fp = fopen("out_04.txt","w+");      	    /*ファイルを書き込みモードで開く*/
	
	if(fp==NULL){
	    printf("ファイルオープン失敗\n");	    /*ファイルオープンに失敗した場失敗と表示し終了*/
	    return -1;
	}

	printf("%s",out_04);                       /*圧縮した文字列を表示*/
	
	fprintf(fp,"%s",out_04);                   /*文字列をファイルに書き込む*/
	fclose(fp);

	return (0);
}
