#include<bits/stdc++.h>
#include<iostream>
#include<time.h>
#include<math.h>
#include<cstring>
#include<cstdlib>
#include<exception>
#include<vector>

using namespace std;

# define INF 0x3f3f3f3f

int number=0;
int gethno(string);

class Appexception
{
    int enumb;
    string ename;
public:
    Appexception(string n,int e)
    {
        ename=n;
        enumb=e;
    }
    void show()
    {
        cout<<"\nError Number"<<enumb<<"\n Error: "<<ename;
    }
    void show1()
    {
        cout<<endl<<ename<<endl;
    }
};

class adhaar
{
    int num;
public:
    adhaar()
    {
        num=0;
    }
    adhaar(int num)
    {
        this->num=num;
    }
    void get()
    {
        cout<<"Enter your adhaar no\n";
        cin>>num;
    }
    void put()
    {
        cout<<num;
    }
};

class address
{
    string name;
    int location;
    static int pincode;
public:
    address()
    {
        name=" ";
        location=0;
    }

    address(string name,int location,int pincode)
    {
        this->name=name;
        this->location=location;
    }

    void getadd()
    {
        cout<<"Enter Name\n";
        cin>>name;
        location=gethno(name);
    }
    void getaddme(string n,int h)
    {
        name=n;
        location=h;

    }
    void putadd()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Location:"<<location<<endl;
        cout<<"Pincode:"<<pincode<<endl;
    }
    string getname()
    {
        return name;
    }
    int add()
    {
        return location;
    }
};
int address::pincode=580031;//address class

class person;
person getpub(string);
class message
    {
        string content;
public:
        message()
        {
            content=" ";
        }

        message(string content)
        {
            this->content=content;
        }

        void get()
        {
            cout<<"Enter Message:"<<endl<<"\"Press ; to terminate the message\""<<endl;
            getline(cin,content,';');
        }
        void get(string m)
        {
            content.erase();
            content=m;
        }
        void put()
        {
            cout<<"Message:"<<content<<endl;
        }
        string getmsg()
        {
            return content;
        }
    };

class letter
{
    address from;
    address to;
    message msg;
public:
    letter()
    {

    }

    void getlet(string n,int h)
    {
        try
        {
            from.getaddme(n,h);

            cout<<endl<<"To address : "<<endl;
            to.getadd();
            msg.get();
        }
        catch(...)
        {
            cout<<endl<<"Cannot create letter"<<endl;
        }
    }

    void putlet()
    {
        cout<<"\n\nFrom:"<<endl;
        from.putadd();
        cout<<"\nTo:"<<endl;
        to.putadd();
        cout<<"\n\nContent:"<<endl;
        msg.put();
    }
    string postto()
    {
        return to.getname();
    }
    string postfrom()
    {
        return from.getname();
    }
    string toencrypt()
    {
        return msg.getmsg();
    }
    void encrypted(string m)
    {
        msg.get(m);
    }
    int getto()
    {
        return to.add();
    }
};

class mailbox
{
    vector<letter> let;
    int counts=-1;
public:
    void mail(letter le)
    {
        counts++;
        let.push_back(le);
    }
    vector<letter> collect()
    {
        return let;
    }
    int counter()
    {
        return counts;
    }
};

mailbox m[3];


class person
{
    string fname;
    string lname;
    adhaar id;
public:
    int hno;
    int pubkey;

    person()
    {
        fname="";
        lname="";
        pubkey=0;
        hno=0;
    }

    person(string fname,string lname,int pid,int hno)
    {
        this->fname=fname;
        this->lname=lname;
        pubkey=rand()%100;
        adhaar id1(pid);
        id=id1;
        number++;
        this->hno=hno;
    }

    void get()
    {
        cout<<"Enter First name:";
        cin>>fname;
        cout<<"Enter Last name:";
        cin>>lname;
        id.get();
        pubkey=rand()%100;
        number++;
        cout<<"Enter your house number: ";cin>>hno;
    }

    void put()
    {
        cout<<endl<<"First Name:"<<fname<<endl;
        cout<<"Last Name:"<<lname<<endl;
        cout<<"Adhaar Number:";id.put();cout<<endl;
        cout<<"Public key:"<<pubkey<<endl;
        cout<<"House number: "<<hno<<endl;
    }
    string getname()
    {
        return fname;
    }
};


class Sender:public person
{
    letter slet;
    int pkey=pubkey;
public:
    Sender():person()
    {   }
    Sender(string f,string l,int p,int h):person(f,l,p,h)
    {   }
    void encryption()
    {
        try
        {
                char key = pkey; //Any char will work
                string con = slet.toencrypt();
                for (int i = 0; i < int(con.size()); i++)
                    con[i] = con[i] ^ key;
                slet.encrypted(con);
                if(con.length()<0)
                    throw Appexception("Cannot Encrypt illegal string size",1);
        }
        catch(Appexception& e)
        {
            e.show();
        }
        catch(...)
        {
            cout<<endl<<"Cannot encrypt the letter"<<endl;
        }
    }
    void send(letter let)
    {
        try
        {
            int ch;
            cout<<endl<<"\n 1.Post Box 1 \n 2.Post Box 2 \n 3.Post Box 3"<<endl<<endl;
            cout<<"Enter which mail box you want to send letter:"; cin>>ch;
            switch(ch)
            {
                case 1: if(m[0].counter()==1)
                        {
                            throw Appexception("Post box 1 is full",5);
                        }
                        else
                        {
                            m[0].mail(let);
                            cout<<endl<<"\n Letter sent\n"<<endl;
                        }
                        break;
                case 2: if(m[1].counter()==1)
                        {
                            throw Appexception("Post box 2 is full",6);
                            ch=0;
                        }
                        else
                        {
                            m[1].mail(let);
                            cout<<endl<<"\n Letter sent\n"<<endl;
                        }
                        break;
                case 3: if(m[2].counter()==3)
                        {
                            throw Appexception("Post box 3 is full",5);
                        }
                        else
                        {
                            m[2].mail(let);
                            cout<<endl<<"\n Letter sent\n"<<endl;
                        }
                        break;
                default: cout<<endl<<"\n Letter entry \n"<<endl;
                        break;
            }
        }
        catch(Appexception& e)
        {
            e.show();
        }
    }
    void writes(string n,int hno)
    {
        cout<<endl<<n<<" is writing letter"<<endl;
        slet.getlet(n,hno);
        encryption();
        send(slet);
    }
    void pukey(int l)
    {
        pkey=l;
    }
};
vector<Sender> s;

class Receiver:public person
{
    vector<letter> rlet;
    int key;
    int rcount=-1;
public:
    Receiver():person()
    {   }
    Receiver(string f,string l,int p,int h):person(f,l,p,h)
    {   }
    void decryption()
    {
        try
        {
            person pe= getpub(rlet[rcount].postfrom());
            char key = pe.pubkey;
            string con = rlet[rcount].toencrypt();
            for (int i = 0; i < int(con.size()); i++)
                con[i] = con[i] ^ key;
            rlet[rcount].encrypted(con);
        }
        catch(...)
        {
            cout<<endl<<"Decryption not possible"<<endl;
        }
    }

    void receives(letter le)
    {
        rcount=rcount+1;
        rlet.push_back(le);
        decryption();
    }
    void read(string nam)
    {
        try
        {
            cout<<"\n\nReceive box of "<<nam<<"\n"<<endl;
            for(int i=0;i<=rcount;i++)
                rlet[i].putlet();
            if(rcount==-1)
                throw Appexception("You didn't receive any Letters\n",2);
        }
        catch(Appexception& e)
        {
            e.show1();
        }
        catch(...)
        {
            cout<<endl<<"Cannot read received letters"<<endl;
        }
    }
};
void gives(letter);

class Graph
{
    int V;
    list< pair<int, int> > *adj;
    int d[12];
public:
    Graph()
    {   }
    Graph(int V)
    {
        this->V = V;
        adj = new list< pair<int, int> >[V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int* shortestPath(int src)
    {
        try
        {
            if(V==-1 || V==0)
                throw Appexception("Illegal vertices",3);
            set< pair<int, int> > setds;
            vector<int> dist(V, INF);
            setds.insert(make_pair(0, src));
            dist[src] = 0;
            while (!setds.empty())
            {
                pair<int, int> tmp = *(setds.begin());
                setds.erase(setds.begin());

                int u = tmp.second;

                list< pair<int, int> >::iterator i;
                for (i = adj[u].begin(); i != adj[u].end(); ++i)
                {
                    int v = (*i).first;
                    int weight = (*i).second;
                    if (dist[v] > dist[u] + weight)
                    {
                        if (dist[v] != INF)
                            setds.erase(setds.find(make_pair(dist[v], v)));

                        dist[v] = dist[u] + weight;
                        setds.insert(make_pair(dist[v], v));
                    }
                }
            }
            for(int i=1;i<V;i++)
            {
                d[i]=i;
            }
            for(int i=1;i<V;i++)
            {
                for(int j=i+1;j<V;j++)
                {
                    if(dist[i]>dist[j])
                    {
                        int temp=dist[i];
                        dist[i]=dist[j];;
                        dist[j]=temp;
                        temp=d[i];
                        d[i]=d[j];
                        d[j]=temp;
                    }
                }
            }
        }
        catch(Appexception& e)
        {
            e.show();
        }
        catch(...)
        {
            cout<<"\n\nCannot create shortest path\n\n";
        }

        return d;
    }
    int retV()
    {
        return V;
    }
};
vector<Receiver> r;

class PostMan:public person
{
    letter let[5];
    int Eid,n;
    int pcounts=-1;
    int dis[5];
    int sd[10];
public:
    void gets()
    {
        person::get();
        cout<<endl<<"Enter the number Letters he can carry :";cin>>n;
        cout<<"\nEnter postman id\n";
        cin>>Eid;
        number--;
    }

    PostMan()
    {
        Eid=0;
        n=0;
    }
    PostMan(string fname,string lname,int num,int e,int hno):person(fname,lname,num,hno)
    {
        n=2;
        number--;
    }
    void distributes(Graph g)
    {
            shpath(g);
            for(int i=0;i<=pcounts;i++)
            {
                for(int j=0;j<number;j++)
                {
                    if(let[i].getto()==sd[j])
                    {
                        gives(let[i]);
                        break;
                    }
                }
            }
    }

    void shpath(Graph g)
    {
        int *d;
        int h[number];
        for(int i=0;i<number;i++)
            h[i]=r[i].hno;

        d=g.shortestPath(5);
        int k=0;
        for(int i=1;i<g.retV();i++)
        {
            for(int j=0;j<number;j++)
                if(d[i]==h[j])
                    sd[k++]=d[i];
        }
    }
    int rserves()
    {
        return pcounts;
    }
    void collects(letter l)
    {
        pcounts++;
        let[pcounts]=l;
    }
};

class PostOffice
{
    PostMan postm[5];
    vector<letter> l;
    int n,mb;
    Graph g;
public:
    PostOffice()
    {   }
    void get()
    {
        cout<<"\n Enter number of postman:";cin>>n;
        cout<<endl<<"Enter there details:"<<endl;
        for(int i=0;i<n;i++)
            postm[i].gets();
    }

    void get(PostMan po[],int n1,Graph g)
    {
        n=n1;
        for(int i=0;i<n;i++)
            postm[i]=po[i];
        this->g=g;
    }
    void allocate()
    {
        try
        {
                for(int i=0,j=0;i<=2 && j<=2;i++)
                {
                    int h=m[i].counter();
                    if(h!=-1)
                    {
                        l=m[i].collect();
                        for(int k=0;k<=h && j<=2;k++)
                        {
                            if(postm[j].rserves()>2)
                            {
                                j++;
                            }
                            postm[j].collects(l[k]);
                        }
                    }
                }
                for(int i=0;i<3;i++)
                    postm[i].distributes(g);
        }
        catch(...)
        {
            cout<<endl<<"Cannot Allocated to Postman"<<endl;
        }
    }
};
string per[20];
int main()
{
    srand(time(0));
    try
    {
        mailbox m1,m2,m3;
        m[0]=m1;
        m[1]=m2;
        m[2]=m3;

        Sender s1("A","AA",1,4);
        Receiver r1("B","BB",2,7);
        Sender s2("C","CC",3,8);
        Receiver r2("D","DD",4,1);
        Sender s3("E","EE",5,3);
        Receiver r3("F","FF",6,2);
        Sender s4("G","GG",7,6);
        Receiver r4("H","HH",8,9);
        Sender s5("I","II",9,10);
        Receiver r5("J","JJ",10,11);


        s.push_back(s1);
        s[0].put();

        r.push_back(r1);
        r[0].put();


        s.push_back(s2);
        s[1].put();

        r.push_back(r2);
        r[1].put();

        s.push_back(s3);
        s[2].put();

        r.push_back(r3);
        r[2].put();

        s.push_back(s4);
        s[3].put();

        r.push_back(r4);
        r[3].put();

        s.push_back(s5);
        s[4].put();

        r.push_back(r5);
        r[4].put();

        int V = 12;
        Graph g(V);

        g.addEdge(10, 1,rand()%10);
        g.addEdge(10, 7,rand()%10);
        g.addEdge(1, 2,rand()%10);
        g.addEdge(1, 7,rand()%10);
        g.addEdge(2, 3,rand()%10);
        g.addEdge(2, 8,rand()%10);
        g.addEdge(2, 5,rand()%10);
        g.addEdge(3, 4,rand()%10);
        g.addEdge(3, 5,rand()%10);
        g.addEdge(4, 5,rand()%10);
        g.addEdge(5, 6,rand()%10);
        g.addEdge(6, 7,rand()%10);
        g.addEdge(6, 8,rand()%10);
        g.addEdge(7, 9,rand()%10);
        g.addEdge(11, 1,rand()%10);
        g.addEdge(11, 9,rand()%10);

        for(int pi=0;pi<5;pi++)
            s[pi].writes(s[pi].getname(),s[pi].hno);

        PostMan pom[3];
        PostMan pom1("Postman","1",11,1,5);
        PostMan pom2("Postman","2",12,2,5);
        PostMan pom3("Postman","3",13,3,5);
        pom[0]=pom1;
        pom[1]=pom2;
        pom[2]=pom3;

        PostOffice po;
        po.get(pom,3,g);
        po.allocate();


        r1=r[0];
        r2=r[1];
        r3=r[2];
        r4=r[3];
        r5=r[4];

        r1.read(r1.getname());
        r2.read(r2.getname());
        r3.read(r3.getname());
        r4.read(r4.getname());
        r5.read(r5.getname());
    }
    catch(...)
    {
        cout<<"\nError in main\n";
    }
    return 0;
}

person getpub(string name)
{
    int i;
    for(i=0;i<int(s.size());i++)
    {
        if(name==s[i].getname())
        {
            return s[i];
        }

    }
    return person();
}

void gives(letter l)
{
    try
    {
        string name=l.postto();
        int i;
        if(name.length()!=1)
            throw Appexception("Cannot retrieve name of receiver\n",4);
        for(i=0;i<int(r.size());i++)
        {
            if(name==r[i].getname())
            {
                r[i].receives(l);
            }
        }
    }

    catch(Appexception& e)
    {
        e.show();
    }
}

int gethno(string name)
{
    int i;
    for(i=0;i<int(s.size());i++)
    {
        string n4=s[i].getname();

        if(name==n4)
            return s[i].hno;
    }
    for(i=0;i<int(r.size());i++)
    {
        string n4=r[i].getname();

        if(name==n4)
            return r[i].hno;
    }
    return 0;
}
