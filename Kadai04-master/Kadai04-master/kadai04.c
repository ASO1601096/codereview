#include <stdio.h>
#include <string.h>

#define MAX 128
/*                                               */
/*�����̘A���񐔂𒲂ׂāA�A���񐔂�num�ϐ���Ԃ�*/
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
/*�S�����A���ȏ�̕����̏ꍇ                     */
/*�g���unum�v�ustr�v�h��3�����̈��k��������쐬��*/
/*�o�̓t�@�C���̏I�[�ɓ\��t����                 */
/*                                               */
static void comp_write(char* out_str,const char str, int num){
	char comp_str[4]={0};
	comp_str[0]='@';
	comp_str[1]=str;
	comp_str[2]=num+'0';                                 /*�����𕶎��ɕύX����*/
	strcat(out_str,comp_str);                            /*�쐬������������o�̓t�@�C���ɓ\��t����*/	
	
}
/*                                               */
/*�S�����A�������̕����̏ꍇ                     */
/*num��A����str��������쐬��                   */
/*�o�̓t�@�C���̏I�[�ɓ\��t����                 */
/*                                               */
static void as_write(char* out_str,const char str, int num){
	char cons_str[4]={0};
	int j=0;
	while(num>0){
		cons_str[j]=str;
		j++;
		num--;
	}
	strcat(out_str,cons_str);                            /*�쐬������������o�̓t�@�C���ɓ\��t����*/
}
/*                                               */
/*              ���C���֐�                       */
/*                                               */
int main(void){
	
	int i=0,number;
	char in_04[MAX]={0};
	char out_04[MAX]={0};	
	char str;
	FILE *fp;	                                         /* (1)�t�@�C���|�C���^�̐錾 */
	
	fp = fopen("in_04.txt","w");      	                 /*�t�@�C�����������݃��[�h�ŊJ��*/
	
	if(fp==NULL){
	    printf("�t�@�C���I�[�v�����s\n");	             /*�t�@�C���I�[�v���Ɏ��s�����ꎸ�s�ƕ\�����I��*/
	    return -1;
	}

	printf("���������͂��Ă��������F\n");
	gets(in_04);                                         /*���͂�����������󂯎��*/
	
	fprintf(fp,"%s",in_04);                              /*��������t�@�C���ɏ�������*/

	while(in_04[i]!='\0'){
		str=in_04[i];
		number=serial_check(in_04,str,i);                /*str�̕����̘A�����`�F�b�N*/
		if(number<4){
			as_write(out_04,str,number);                 /*���̂܂�out_04�t�@�C���ɏ�������*/
		}else{
			comp_write(out_04,str,number);               /*���k�������out_04�t�@�C���ɏ�������*/
		}
		i+=number;                                       /*���̕����̈ʒu�Ɉړ�����*/
	}
	
	fclose(fp);
	
	fp = fopen("out_04.txt","w+");      	             /*�t�@�C�����������݃��[�h�ŊJ��*/
	
	if(fp==NULL){
	    printf("�t�@�C���I�[�v�����s\n");	             /*�t�@�C���I�[�v���Ɏ��s�����ꎸ�s�ƕ\�����I��*/
	    return -1;
	}

	printf("%s",out_04);                                 /*���k�����������\��*/
	
	fprintf(fp,"%s",out_04);                             /*��������t�@�C���ɏ�������*/
	fclose(fp);

	return (0);
}
