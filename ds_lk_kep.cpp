#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;//tro toi node cua node ke tiep
    Node *previous;//tro toi node cua node phia truoc
};
//khai boa danh sach
struct list
{
    Node *ndau;//luon tro toi phan tu dau tien
    Node *nduoi;//luon tro toi phan tu cuoi cung  
};

void taoList(list &l)//tao danh sach
{
    l.ndau=NULL;
    l.nduoi=NULL;
}
Node *taoNode(int x)//tao node
{
    Node *node =new Node;
    node->data=x;
    node->next=NULL;
    node->previous=NULL;
    return node;
}
void themDau(list &l,int x)
{
    Node *p=taoNode(x);
    if(l.ndau==NULL)//danh sach rong
    {
        l.ndau=l.nduoi=p;//
    }
    else{
        p->next=l.ndau;
        l.ndau->previous=p;
        l.ndau=p; 
    }
}
int  xoaDau(list &l,int a)
{

    if(l.ndau=NULL)
    {    
        Node *p=l.ndau;//con tro p luu trữ địa chỉ của phần tử đầu tiên(ndau)
        l.ndau=l.ndau->next;//Cập nhật giá trị biến ndau lưu trữ địa chỉ phần tử liền sau phần tử ndau
        delete p;
        if(l.ndau!=NULL)
        {
            l.ndau->previous=NULL;//truong hop danh sach khac rong
        }
        else{
            l.nduoi=NULL;//truong hop danh sach khong con phan tu nao
        }   
        return 1;
    }
    return 0;

}
void xuatTraiSangPhai(const list l)
{
    Node *p=l.ndau;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void xuatPhaiSangTrai(const list l)
{
    Node *p=l.nduoi;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->previous;
    }
}
int main()
{
    list l;
    int n,x,a;
    cout<<"Nhap n: ";
    cin>>n;
    taoList(l);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        themDau(l,x);
    }
    cout<<xoaDau(l,a);
    xuatTraiSangPhai(l);
    cout<<endl;
    xuatPhaiSangTrai(l);
    return 0;
}