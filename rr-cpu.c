#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct node{
  int t , id ;
  struct node *pre , *next ;
}np;
//insert data in link list
np* insert_End(np *p , int x , int y ){
  struct node *temp = (np*)malloc( sizeof(np)) ;
  temp->t = x ;
  temp->id = y ;
  temp->next = NULL ;
  if ( p == NULL ){
  p = temp ;
  return p;
  }
    struct node *temp1 = p ;
    while( temp1->next != NULL )
    temp1 = temp1->next ;
    temp1->next = temp ;
    return p ;
}
//delete node from begining of link list
np* delete_begin( np* p ){
  np *ptr = p ;
  ptr = ptr->next ;
  p->pre = NULL ;
  free(p);
  p = ptr ;
  return p ;
}
//display process id with cpu schudling 
void display( struct node *p){
  struct node *temp = p;
  printf("P_ID\tP_BT\n----------\n");
  while(temp != NULL ){
    printf("%d\t%d\n",temp->id,temp->t) ;
    temp = temp->next ;
    }
  printf("\n") ;
}
//this will make ghangchart for all processes
int g_chat( np *p , int m_t , int bt , int a[2][100] ){
 int k = 0 , s = 0 ;
  while( s <= m_t ){
    if ( p->t > bt ){
      s += bt ;
      a[0][k] = p->id ;
      a[1][k++] = s ;
      p = insert_End( p , p->t - bt , p->id );
      p = delete_begin(p);
    }else{
      s += p->t ;
      a[0][k] = p->id ;
      a[1][k++] = s ;
      p = delete_begin(p);
    }
  }
  return k ;
}
int main() {
  struct node *p1 = NULL ;
  int i = 0 , s = 0 , m_t , bt , s1 ;
  int a[2][100] ;
  srand(time(0));
  printf("enter max time and cpu burst time\n");
  scanf("%d%d",&m_t,&bt);
  while( s <= m_t ){
    int x = rand() % 20 ;
    s += x ;
    p1 = insert_End( p1 , x , i );
    i++ ;
  }
  printf("%d\n\n",s);
  display( p1 );
  int k = g_chat(p1 , m_t , bt , a );
  printf("Gang_Chart\n-----------\n\n");
  printf("P_ID\tEXECUTION_TIME\n\n");
  for ( int i = 0 ; i < k ; i++ )
  printf("%d ------> %d unit_time\n",a[0][i],a[1][i]);
}