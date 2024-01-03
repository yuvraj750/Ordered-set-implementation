#include<iostream>
#include<vector>
using namespace std;
class SET{
    public:
    vector<int> v;
    void insert(int d){
        if(v.size()==0){
            v.push_back(d);
        }
        else{
            int i=0;
            while( i<v.size() && v[i]<d ){
            i++;
            }
            if(i==v.size()){
                v.push_back(d);
            }
            else if( v[i]>d){
                int ch=d;
                int j=i;
                while(j<v.size()){
                    int temp=v[j];
                    v[j]=ch;
                    ch=temp;
                    j++;
                }
                v.push_back(ch);
            }
        }
    }
    void delete1(int d){
     int i=0;
     while(i<v.size() && v[i]<d){
        i++;
     }
     if(i<v.size() && v[i]==d){
        v.erase(v.begin()+i);
     }
    }
    bool belong(int d){
        int i=0;
        while(i<v.size()){
            if(v[i]==d){
                return 1;
            }
            i++;
        }
       
            return 0;
        
    }
    void union1(vector<int> &b){
      vector<int> c;
      int i=0;
      int j=0;
      if(v.size()==0){
        cout<<b.size()<<endl;
        return;
    }
    if(b.size()==0){
        b=v;
        cout<<b.size()<<endl;
        return;
    }
      while(i<b.size() && j<v.size()){
        if(b[i]==v[j]){
            c.push_back(b[i]);
            i++;
            j++;
        }
        else if(b[i]<v[j]){
            c.push_back(b[i]);
            i++;
        }
        else {
            c.push_back(v[j]);
            j++;
        }
      }
      while(i<b.size()){
        c.push_back(b[i]);
            i++;
      }
      while(j<v.size()){
        c.push_back(v[j]);
            j++;
      }
      b=c;
      cout<<b.size()<<endl;
    }
    void intersection1(vector<int> &b){
        vector<int> c;
      int i=0;
      int j=0;
      if(b.size()==0 || v.size()==0){
        b=c;
        cout<<b.size()<<endl;
        return;
      }
      while(i<b.size() && j<v.size()){
        if(b[i]==v[j]){
            c.push_back(b[i]);
            i++;
            j++;
        }
        else if(b[i]>v[j]){
            j++;
        }
        else {
            i++;
        }
    }
    b=c;
    cout<<b.size()<<endl;
    }
    void size(){
        cout<<v.size()<<endl;
    }
    void difference(vector<int> &b){
      int i=0;
      int j=0;
      if(b==v){
        b.clear();
        cout<<b.size()<<endl;
        return;
      }
      if(b.size()==0 || v.size()==0){
        cout<<b.size()<<endl;
        return;
      }
      while(i<b.size() && j<v.size()){
      if(b[i]==v[j]){
        b.erase(b.begin()+i);
        j++;
      }
      else if(b[i]<v[j]){
        i++;
      }
      else{
        j++;
      }
      }
      cout<<b.size()<<endl;

    }
    void symmetricdifference(vector<int> &b){
        vector<int> c;
        int i=0;
        int j=0;
        if(b==v){
            b=c;
            cout<<b.size()<<endl;
            return;
        }
        if(b.size()==0 && v.size()!=0){
            b=v;
            cout<<b.size()<<endl;
            return;
        }
        if(b.size()!=0 && v.size()==0){
            cout<<b.size()<<endl;
            return;
        }
        while(i<b.size() && j<v.size()){
            if(b[i]<v[j]){
                c.push_back(b[i]);
                i++;
            }
            else if(b[i]==v[j]){
                i++;
                j++;
            }
            else{
                c.push_back(v[j]);
                j++;
            }
        }
        while(i<b.size()){
            c.push_back(b[i]);
            i++;
        }
        while(j<v.size()){
            c.push_back(v[j]);
            j++;
        }
        b=c;
      cout<<b.size()<<endl;
    }
    void print(){
        for(int i=0;i<v.size()-1;i++){
             cout<<v[i]<<",";
            }
            cout<<v[v.size()-1]<<endl;
    }
};
int main(){
     vector<SET> s;
    int a;
    int b;
    int c;
    while (1) {
        cin>>a;
        cin>>b;
        if(!cin){
            break;
        }
        switch (a){    
      case 1:
        if(b>=s.size()){
            s.push_back(SET());
            cin>>c;
            s[b].insert(c);
        }
        else{
            cin>>c;
            s[b].insert(c);
        }
        cout<<s[b].v.size()<<endl;
    break;
    case 2:
        if(b>=s.size()){
            cin>>c;
            cout<<"-1"<<endl;
        }
        else{
            cin>>c;
            s[b].delete1(c);
            cout<<s[b].v.size()<<endl;
        }
    break;
    case 3:
        if(b>=s.size()){
            cin>>c;
            cout<<"-1"<<endl;
        }
        else{
            cin>>c;
            cout<<s[b].belong(c)<<endl;
        }
    break;
    case 4:
        cin>>c;
        if(b>=s.size() && c>=s.size()){
            s.push_back(SET());
            s.push_back(SET());
        }
        else if((b<s.size() && c>=s.size()) || (b>=s.size() && c<s.size())){
            s.push_back(SET());
            s[c].union1(s[b].v);
        }
        else{
            s[c].union1(s[b].v);
        }
        break;
    case 5:
        cin>>c;
        if(b>=s.size() && c>=s.size()){
            s.push_back(SET());
            s.push_back(SET());
        }
        else if((b<s.size() && c>=s.size()) || (b>=s.size() && c<s.size())){
            s.push_back(SET());
            s[c].intersection1(s[b].v);
        }
        else{
            s[c].intersection1(s[b].v);
        }
        break;
    case 6:
        if(b>=s.size()){
            s.push_back(SET());
            cout<<"0"<<endl;
        }
        else{
            s[b].size();
        }
    break;
    case 7:
    cin>>c;
    if(b>=s.size() && c>=s.size()){
            s.push_back(SET());
            s.push_back(SET());
        }
        else if((b<s.size() && c>=s.size()) || (b>=s.size() && c<s.size())){
            s.push_back(SET());
            s[c].difference(s[b].v);
        }
        else{
            s[c].difference(s[b].v);
        }
        break;
        case 8:
        cin>>c;
        if(b>=s.size() && c>=s.size()){
            s.push_back(SET());
            s.push_back(SET());
        }
        else if((b<s.size() && c>=s.size()) || (b>=s.size() && c<s.size())){
            s.push_back(SET());
            s[c].symmetricdifference(s[b].v);
        }
        else{
            s[c].symmetricdifference(s[b].v);
        }
        break;
    case 9:
        if(b>=s.size()){
            cout<<endl;
        }
        else if(s[b].v.empty()){
            cout<<endl;
        }
        else{
            s[b].print();
        }
        break;
        }
    }
    return 0;
}