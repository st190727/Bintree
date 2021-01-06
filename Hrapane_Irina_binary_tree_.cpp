#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include<stdio.h>
#include<stdlib.h>
#include <iomanip>

using namespace std;
int n=1;
struct Node
        {
            int data;    
            Node *left, *right;
            Node *p;      
        };
//-------------------------------------------------
Node *CreateNode()
{     
Node *newNode;
newNode=new Node;
cout<<"\nInput number what to add:  "; 
cin>>newNode->data;
newNode->left=NULL;
newNode->right=NULL;
return newNode;      
}
//-----------------------------------------------

void *InOrder (Node *p) 
{
    if(p!=NULL)
    {
        InOrder(p->left);
        cout<<p->data<<" ";
        InOrder(p->right);
    } 
}
void *PreOrder(Node *p)
{
    if(p!=NULL)
    {
          cout<<p->data<<" ";
          PreOrder(p->left);
          PreOrder(p->right);    
    }   
}

void *PostOrder(Node *p)
{
   if(p!=NULL)
   {
        PostOrder(p->left);
        PostOrder(p->right);
        cout<<p->data<<" ";  
    }  
}
//----------------------------------------------------
void *AddNode (Node *root)
{ 
int x;
Node *cur, *cur2, *newNode,*key;
key=newNode=CreateNode();
cur=root;

while((cur->left!=NULL && cur->right !=NULL)|| 
       (cur->left!=NULL && newNode->data<cur->data) ||
       (cur->right!=NULL &&newNode->data>cur->data))
       
    {if(newNode->data<cur->data)cur=cur->left;else cur = cur ->right;}
      
     if(newNode->data<cur->data)cur->left=newNode;else cur->right=newNode;  
}  
//---------------------------------------------------
int CountNodes(Node *root)
{
    if(root==NULL)return 0;
    if(root->left!=NULL)
    {
        n=n+1;
        n=CountNodes(root->left);
    }
    if(root->right!=NULL)
    {
        n=n+1;
        n=CountNodes(root->right);   
    } 
    return n; 
}
//------------------------------------------------
Node *CreateTree(Node *root)
{
    int n;
    cout<<"\nInput nodes count: ";cin>>n;
    while(n-->0)
    {
      AddNode(root); 
    }
     return root;    
}
//------------------------------------------------???
void PrintTree (Node *cur)
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
if ( ! cur ) return;
SetConsoleTextAttribute(hConsole, 12);
PrintTree (cur->left);
cout<<cur->data<<" ";
PrintTree (cur->right);
}
//------------------------------------------------
void *Print(Node *root)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    if (!root)
        return 0; 
    if (!root->left&&!root->right)
    {
        cout<<root->data<<" "; 
        return 0;
    }
    if (root->left)
       Print(root->left);
       
    if (root->right)
       Print(root->right);    
}
//----------------------------------------------
Node *Find(Node *root, int x)
{
 Node *cur;
 cur=root;
 cout<<"\nInput x (What find): ";cin>>x;
                    while (!cin.good() || x<=0)
                        {
                            cin.clear ();
                            cin.ignore( 256, '\n');
                            cout<<"\nError! Please try again...";
                            cout<<"\nInput again: "; cin>>x;
                        }
 while(cur!=NULL)
    {
        if(cur->data==x)return cur;
        else
            if(cur->data>x)cur=cur->left;
            else cur=cur->right;
        
       /* while(cur->data!=x)
        {
            cout<<"\nNot found";
            cout<<"\nPlease try again...";
            cout<<"\nInput again: "; cin>>x;    
        }  */
    }
    return NULL;   
}
//-------------------------------------------------------
Node *PoiskMin(Node *root)
{
    while(root->left!=NULL)
    {
     root=root->left;   
    }
return root;
}
//-----------------------------------------------------
Node* DeleteNode(Node *root, int x)
{
    
    cout<<"\nInput x (What to delete): ";cin>>x;
    if(root==NULL) return 0;
    else if (x<root->data)
    {
        root->left=DeleteNode(root->left,x);   
    }
    else if (x>root->data)
    {
        root->right=DeleteNode(root->right,x);   
    }
    else
    {
            if(root->left==NULL&&root->right==NULL)
            {
             delete root;
            
             root=NULL;cout<<"\nis deleted!";return root;   
            }
        
            else if(root->left==NULL)
            {
             Node *temp=root;
             root=root->right;
             delete temp;cout<<"\nTempright is deleted!";
             return root;   
            }
            else if(root->right==NULL)
            {
             Node *temp=root;
             root=root->left;
             delete temp;cout<<"\ntempleft is deleted!";
             return root;   
            }
            
            else
            {
             Node *temp=PoiskMin(root->right);
             root->data=temp->data;
             root->right=DeleteNode(root->right,temp->data);   
            }
            
    }
    return root;
} 
//----------------------
Node *swaptree(Node*p)
{
    Node *temp1=NULL,*temp2=NULL;
    if(p!=NULL)
    {
      
            temp1=swaptree(p->left);temp2=swaptree(p->right);
            p->right=temp1;
            p->left=temp2;
          
    }
   return p; 
}
//----------------------
int main () 
{

 ///////////////////////////////////////////// 
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 11);
    cout<<"\n\tSubject: Algorithms\n";
    cout<<"\tTeacher name: Vija Vagale\n";
    cout<<"\tStudent name: Irina Hrapane\n";
    cout<<"\t\t\n\n";
SetConsoleTextAttribute(hConsole, 15);
    cout<<"\tProgramm name: My Binary Tree\n";
    system("Pause>>nul");
/////////////////////////////////////////////
Node *root=NULL;
    Node *cur, *p;
    int x; int s; int data;int n;
    system("Pause>>nul");   
    int izvele;
    do
    {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\t\t\n\nProgramm about data structure: Binary Tree\n\n";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<setw(5)<<"80."<<"\t"<<"Create root\n";
        cout<<setw(5)<<"90."<<"\t"<<"Print root\n\n";
        
        cout<<setw(5)<<"1."<<"\t"<<"Create tree\n";
        cout<<setw(5)<<"2."<<"\t"<<"Print tree\n";
        cout<<setw(5)<<"3."<<"\t"<<"Add Node\n";
        cout<<setw(5)<<"4."<<"\t"<<"Search Node;\n";
        cout<<setw(5)<<"5."<<"\t"<<"Count Node Total;\n\n";
        
        cout<<setw(5)<<"6."<<"\t"<<"Delete (3 cases);\n";
        cout<<setw(5)<<"7."<<"\t"<<"Print leaf nodes;\n";
        cout<<setw(5)<<"8."<<"\t"<<"Swapping tree;\n\n";
        
        cout<<setw(5)<<"9."<<"\t"<<"PreOrder;\n";
        cout<<setw(5)<<"10."<<"\t"<<"InOrder;\n";
        cout<<setw(5)<<"11."<<"\t"<<"PostOrder;\n";
        cout<<setw(5)<<"0."<<"\t"<<"The end\n";
        cout << "\n\nChoose number: ";
        cin>>izvele;  
            
            switch(izvele) {
            case 80: if(!root) root=CreateNode();
                    else cout<<"root exist!"; system("Pause>>nul");break;
            case 90: if(root) cout<<"root = "<<root->data; 
                    else cout<<"Root doesnt exist!";system("Pause>>nul");break;
      
            case 1: if(root) {cout<<"\nBMK Create: \n"; CreateTree(root);system("Pause>>nul");}break; 
            case 2: if(root) {cout<<"\nBMK: \n"; 
                    PrintTree(root);system("Pause>>nul");}break; 
            case 3: if(root) AddNode(root); else root=CreateNode();system("Pause>>nul");break;  
            case 4: if(root) {cur=Find(root,x);cout<<"\nFound!!! and x = "<<cur->data<<"";system("Pause>>nul");}
                    break;
               
                     
            case 5: if(root){cout<<"\nBMK: \n";PrintTree(root);
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 7); 
                    cout<<"\n\nBMK count TOTAL: "<<CountNodes(root)<<"\n";
                    system("Pause>>nul");}break;
            case 6: cout<<"\nBefore Deletion: ";
                    InOrder(root);
                    DeleteNode(root,x);
                    
                    
                    system("Pause>>nul");break;
            case 7: if(root) {
                    cout<<"\nBMK: \n"; 
                    PrintTree(root);
                    SetConsoleTextAttribute(hConsole, 7); 
                    cout<<"\nBMK leaf nodes: \n"; Print(root);system("Pause>>nul");}break; 
                    
            case 8: if(root) {cout<<"\nBMK swapp: \n"; swaptree(root);PrintTree(root);system("Pause>>nul");}break;         
            case 9: if(root) {cout<<"\nBMK PreOrder: \n"; PreOrder(root);system("Pause>>nul");}break; 
            case 10:if(root) {cout<<"\nBMK InOrder: \n"; InOrder(root);system("Pause>>nul");}break;
            
            case 11:if(root) {cout<<"\nBMK PostOrder: \n"; PostOrder(root);system("Pause>>nul");}break;
                       
            
            case 0: cout << "End!";
                    system("Pause>>nul");break;                 
            default: 
                        cout << "Incorect choice!";
                        system("Pause>>nul");           
                } 
        }while (izvele!=0);
    
    system("Pause>>nul");
    return 0;

}
