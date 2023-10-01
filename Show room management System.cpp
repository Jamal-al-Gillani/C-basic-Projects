//Car showroom management system
#include <iostream>
using namespace std;
struct node
{
    string car_name;
    string brand_name;
    string model_name;
    string issue;
    int price;
    string data;
    node* left;
    node* right;
    node *next;
};
class showroom
{
private:
    node *head;
    node *tail;
    float counter;
    float counter1;

public:
    showroom()
    {
        head = NULL;
        tail = NULL;
        counter = 0;
        counter1 = 0;
    }
    ~showroom()
    {
        delete head;
        delete tail;
    }
    void add_car(string a, string b,string c, int n)
    {
        counter++;
        node *newnode = new node;
        newnode->car_name = a;
        newnode->brand_name = b;
        newnode->model_name=c;
        newnode->price = n;
        newnode->next = NULL;
        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {

            tail->next = newnode;
            tail = newnode;
            newnode->next = NULL;
        }
    }

    string delete_car(string v)
    {
          string del;
        counter--;
        if (head->car_name == v)
        {
            string del=head->car_name;
            head = head->next;
            cout<<"Deleted"<<endl;
              return del; 
           
        }

        node *tmp = NULL;
        node *pr = NULL;
        tmp = head;
        while (tmp != NULL)
        {
            if (tmp->car_name == v)
            {
                pr->next = tmp->next;
                cout<<"Deleted"<<endl;
                return del;
                break;
            }
            
            else
            {
                pr = tmp;
                tmp = tmp->next;
            }
        }
    }
    void car_issue(string v)
    {
        counter1++;
        node *tmp = NULL;
        tmp = head;
        int state;
        state = 0;
        while (tmp != NULL)
        {
            if (tmp->car_name == v)
            {
                cout << "car Issued\n";

                state = 1;
                break;
            }

            tmp = tmp->next;
        }
        if (state == 0)
        {
            cout << "Not Issued\n";
        }
    }
    void print_car_record(string v)
    {
        node *tmp = NULL;
        tmp = head;
        while (tmp != NULL)
        {
            if (tmp->car_name == v)
            {
                cout << tmp->car_name << endl;
                cout << tmp->brand_name << endl;
                cout << tmp->model_name << endl;
                cout << tmp->price << endl
                     << endl;
            }
            tmp = tmp->next;
        }
    }

    void print_record()
    {
        node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->car_name << endl;
            cout << ptr->brand_name << endl;
            cout << ptr->model_name << endl;
            cout << ptr->price << endl
                 << endl;
            ptr = ptr->next;
        }
    }
    void total_cars()
    {

        cout << "Total car  " << this->counter << "\n";
    }
    void total_issue()
    {

        cout << "Total car Issued " << this->counter1 << "\n";
    }
    void percentage_issue_car()
    {
        double per;
        per = (counter1 / counter) * 100;
        cout << "Percentage of Issue car:" << per << "%" << endl;
    }
};
class stack:public showroom{
    private:
    node *head;
    node *tail;
    public:
    stack()
    {
        head = NULL;
        tail = NULL;
       
    }
    
         void push(string v){
            node *newnode=new node;
         newnode->car_name=v;
         newnode->next=NULL;
      
         if(head==NULL&& tail==NULL){
         head=newnode;
         tail=newnode;
         }
         else{
             //for add in head
             newnode->next=head;
             head=newnode;
         }
         }
         void pop(){
           head=head->next;
        
         }
         void Display(){
             node *ptr=head;
          while(ptr!=NULL){
              cout<<ptr->car_name<<endl;
              ptr=ptr->next;
          }
         }
         
     };
class BST:public showroom{
     private:
     node* root;
     node *lef;
     node *rig;
     int ch=-1;
     public:
     BST(){
         root=NULL;
        
     }
     node *insert_help(node *temp_r,string car_name, string b,string c, int n){
            if (temp_r==NULL)
            {
                /* code */
                node *newnode=new node();
                newnode->left=NULL;newnode->right=NULL;
                newnode->car_name=car_name;
                newnode->brand_name = b;
        		newnode->model_name=c;
        		newnode->price = n;
                return newnode;
            }
            
            if (n>temp_r->price)
            {
                temp_r->right=insert_help(temp_r->right,car_name, b, c, n);
                return temp_r;
            }else{
                temp_r->left=insert_help(temp_r->left,car_name, b, c, n);
                return temp_r;
            }
            
     }
    void insert(string car_name, string b,string c, int n){
        root=insert_help(root,car_name, b, c, n);
    }
    
    void display_In(node *r){
        if (r==NULL)
        {
            return;
        }
        
            
            display_In(r->left);
            cout<<r->car_name<<endl;
            cout<<r->brand_name<<endl;
            cout<<r->model_name<<endl;
            cout<<r->price<<endl<<endl;
            display_In(r->right);
           
    }
    node *delete_help(node *r,string car_name){
        if (r==NULL)
        {
            return NULL;
        }
            if (r->car_name==car_name)
            {
                lef=r->left;
                rig=r->right;
                ch=0;
                return NULL;
            }
        if (car_name>r->car_name)
            {
                r->right=delete_help(r->right,car_name);
                return r;
            }else{
                r->left=delete_help(r->left,car_name);
                return r;
            }
    }
    node * insert_r_h(node *r_h,node *to_h){
            if (r_h==NULL)
            {
                return to_h;
            }
            
            if (to_h->car_name>r_h->car_name)
            {
                r_h->right=insert_r_h(r_h->right,to_h);
            }else{
                r_h->left=insert_r_h(r_h->left,to_h);
            }
            return r_h;
    }
    void insert_r(node *to_i){
        insert_r_h(root,to_i);
    }
    string del(string car_name){
        root=delete_help(root,car_name);
        if (ch==0){
            if(lef!=NULL)insert_r(lef);
            if(rig!=NULL)insert_r(rig);
        

        }else{
            cout<<"No element exist to delete\n";
        }
    }
    bool search_help(node *r,string car_name){
        if (r==NULL)
        {
            return false;
        }
        
            if (r->car_name==car_name)
            {
                return true;
            }else if (car_name>r->car_name)
            {
                return search_help(r->right,car_name);
            }else{
                return search_help(r->left,car_name);
            }        
        
           
    }
    bool search(string car_name){
        return search_help(root,car_name);
    }
    
    
    void display(){
          display_In(root);     
    }
};

int main()
{
    showroom obj;
    stack obj1;
    BST obj2;
    string pCar_name,car_name[10]={"Civic","BRV","Parado","V8","Spotage","Prince"};
    string pBrand_name,brand_name[10]={"Honda","Honda","Toyota","Toyota","KIA","KIA"};
    string pModel_name,model_name[10]={"2020","2021","2020","2021","2020","2021",};
    string issue;
    string l;
    int p_price,price[10]={1500000,500000,2500000,10000000,200000,1500000};

    int n;
    cout << "\n\t*************";
    cout << "\n\t*              Welcome              *";
    cout << "\n\t*     1 : Add Car                   *";
    cout << "\n\t*     2 : Delete Exist Car          *";
    cout << "\n\t*     3 : Delete Add Car            *";
    cout << "\n\t*     4 : Display Exist Car record  *";
    cout << "\n\t*     5 : Car issue                 *";
    cout << "\n\t*     6 : Total number of Cars      *";
    cout << "\n\t*     7 : Number of Cars issued     *";
    cout << "\n\t*     8 : Percentage of Car issued  *";
    cout << "\n\t*     9 : Display all Car record    *";
    cout << "\n\t*     10 : Display Deleted car      *";
    cout << "\n\t*     11 : Exit                     *";
    cout << "\n\t*************";
    cout << "\n\n";
    for(int i=0; i<6;i++){
        obj.add_car( car_name[i], brand_name[i],model_name[i],price[i] );
    }
    while (1)
    {
        cout << "Enter a Number:";
        cin >> n;
        switch (n)
        {
        case 1:
           cout<<"car name:";
			cin>>pCar_name;
			cout<<"brand name:";
			cin>>pBrand_name;
			cout<<"Model : ";
			cin>>pModel_name;
			cout<<"car price: ";
			cin>>p_price;
            obj2.insert( pCar_name, pBrand_name,pModel_name,p_price );
            
            break;
        case 2:
        cout << "Enter name: ";
            cin >> pCar_name;
            l=obj.delete_car(pCar_name);
             obj1.push(l);
            break;
        case 3:
        cout << "Enter name: ";
            cin >> pCar_name;
            obj2.del(pCar_name);
          
            break;

        case 4:
        cout << "Enter name: ";
            cin >> pCar_name;
            obj.print_car_record(pCar_name);
            break;
        case 5:
            cout << "Enter name: ";
            cin >> pCar_name;
            obj.car_issue(pCar_name);
            break;
        case 6:
            obj.total_cars();
            break;
        case 7:
            obj.total_issue();
            break;
        case 8:
            obj.percentage_issue_car();
            break;
        case 9:

            obj.print_record();
            obj2.display();
            break;
        case 10:
           obj1.Display();
           break;
        case 11:
            cout << "Exit";
            exit(0);

        default:
            cout << "Enter a Valid Number";
            break;
        }
    }

    return 0;
}