#include<stdio.h>
#include<string.h>

int text_tree(char tree[]){
    int balance =0;
    if(tree[0]<'A'||tree[0]>'Z'){ 
        return 0;

    }
    for(int i=1;tree[i]!='\0';i++){
    if(tree[i]!='\0'){
        if(tree[i]=='('){
            balance++;
        }
        else if(tree[i]==')'){
            balance--;
        }
        else if(balance<0){
            return 0;
        }
        }
        }
        if(balance!=0){
            return 0;
        }
        return 1;
    }
    void count_tree(char tree[]){
        int count =0;
        for(int i=0;tree[i]!='\0';i++){
            if(tree[i]>='A'&& tree[i]<='Z'){
                count++;
                }   
        } printf("전체 노드의 수:%d\n",count);
    }
    void non_and_leaf_tree(char tree[]){
        int leaf = 0;
        int non =0;
        for(int i=0;tree[i];i++){
            if(tree[i]>='A'&& tree[i]<='Z'){
            if(tree[i+1]!='('){
                leaf++;
            }
            else
            {
                non++;
            }
        }
    }
        printf("리프 노드의 수:%d\n",leaf);
        printf("비 리프 노드의 수:%d\n",non);
    }
    void height_tree(char tree[]){
        int depth =1;
        int height =1;
        for(int i=0;tree[i]!='\0';i++){
            if(tree[i]=='('){
                depth++;
            }
            else if(tree[i]==')'){
                depth--;
            }
            if(depth>height){
                height = depth;
            }
        }
        printf("트리의 높이:%d\n",height);
    }
    void degree_tree(char tree[]){
       int count[100];
       int top =-1;
       int max_degree =0;
       for(int i=0;tree[i]!='\0';i++){
        
        if(tree[i]=='('){
        top++;
        count[top]=0;
        }
        else if(tree[i] >= 'A'&& tree[i]<='Z'){
        if(top>= 0){
            count[top]++;

        }
    }
        else if(tree[i]==')'){
            int degree = count[top];
            if(degree> max_degree){
               max_degree =degree;
            }
            top--;
        }
    }
    printf("모든 노드의 차수 중 최댓값: %d\n",max_degree);
}
void parent_C(char tree[]){
    int countstack[100];
    int top=-1;
    char parentC='\0';
    for(int i=0;tree[i]!='\0';i++){
        if(tree[i]>= 'A' && tree[i]<='Z'){
            if(tree[i]=='C'){
                parentC =countstack[top];
            }
            if(tree[i+1]=='('){
                top++;
                countstack[top]= tree[i];
            }
        }
            else if(tree[i]==')'){
                top--;
            }
        }
        printf("C의 부모 노드: %c\n",parentC);
    }
    void children_c(char tree[]){
        char countstack[100];
        int top=-1;
        char children[100];
        int childrencount =0;

        for(int i=0;tree[i]!='\0';i++){
            if(tree[i]>= 'A' && tree[i]<='Z'){
                if(top>=0&&countstack[top]=='C'){
                    children[childrencount++] = tree[i];
                    
                }
                if(tree[i+1]=='('){
                    countstack[++top]= tree[i];
                }  
                }
            
            if(tree[i]==')'){
                  top--;
            }
    }
        printf("C의 자식 노드: ");
        for(int i=0;i<childrencount;i++){
            printf("%c ",children[i]);
        }
        printf("\n");
    }

void print_tree(char tree[]){
    int depth = 0;
    for(int i=0;tree[i]!='\0';i++){
     if(tree[i]>='A'&& tree[i]<='Z'){
        if(depth== 0){
            printf("%c\n",tree[i]);
        }
        else{
            for(int j= 0;j<depth-1;j++){
                printf("    ");
            }
        
        printf("+---%c\n", tree[i]);
        }
    }
     else if(tree[i]=='('){
        depth++;
     }
     else if(tree[i]==')'){
         depth--;
     }
     
}
}
int main(){
    char tree[100];
    printf("트리를 입력하세요: ");
    scanf("%s",tree);
    if(text_tree(tree)){
        printf("오바른 트리입니다.\n");
    }
    else{
        printf("오바른 트리가 아닙니다.\n");

    }
    printf("입력한 트리:%s\n",tree);
    count_tree(tree);
    non_and_leaf_tree(tree);
    height_tree(tree);
    degree_tree(tree);
    parent_C(tree);
    children_c(tree);
    print_tree(tree);
 return 0;

}