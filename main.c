#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int kuyruk[MAX];
int ilk=-1;
int son=-1;
int kuyrukToplam=0;
float kuyrukOrtalama=0.0;

struct node
{
    int data;
    struct node * prev;
};
struct node* top=NULL;
int yiginUzunluk=-1;

int dizi[];

int main()
{
    for(int i=0; i<MAX; i++)
    {
        int okunanSayi;
        printf("\n Kuyruga Eklenecek Elemani Giriniz = ");
        scanf("%d",&okunanSayi);
        KuyrugaElemanEkle(kuyruk,okunanSayi);
    }
    kuyrukOrtalama = kuyrukToplam/MAX;

    /*
    printf("\n");
    for(int i=ilk; i<=son; i++)
    {
        printf(" %d -",kuyruk[i]);
    }
    printf("\n");
    */

    for(int i=ilk; i<=son; i++)
    {
        if(kuyruk[i]>kuyrukOrtalama)
        {
            YiginaEkle(kuyruk[i]);
        }
    }

    /*
    printf("\n");
    while(top!=NULL)
    {
        printf("deger = %d - adresi = %d - prev = %d\n", top->data,top,top->prev);
        top=top->prev;
    }
    printf("\n");
    */

    int i=0;
    while(top!=NULL)
    {
        dizi[i] = top->data;
        i++;
        top=top->prev;
    }

    printf("\n");
    for(int i=0; i<=yiginUzunluk; i++)
    {
        if(i!=yiginUzunluk)
        {
            printf(" %d -",dizi[i]);
        }
        else if(i==yiginUzunluk)
        {
            printf(" %d",dizi[i]);
        }
    }

    return 0;
}

void KuyrugaElemanEkle(int kuyruk[MAX],int sayi)
{
    if(son==-1)
    {
        ilk=son=0;
        kuyruk[son]=sayi;
    }
    else
    {
        son++;
        kuyruk[son]=sayi;
    }

    kuyrukToplam+=sayi;
    printf("\n*** Eleman Ekleme Basarili.. ***\n");
}

void YiginaEkle(int sayi)
{
    if(yiginUzunluk==-1)
    {
        yiginUzunluk = 0;
        top = (struct node *)malloc(sizeof(struct node));
        top->data=sayi;
        top->prev=NULL;
    }
    else
    {
        struct node * temp = (struct node *)malloc(sizeof(struct node));
        temp->data=sayi;
        temp->prev=top;
        top=temp;
        yiginUzunluk++;
    }
}