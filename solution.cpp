#include<iostream>
//#include<string>

using namespace std;

struct deviceManager{
    double measurement[3]={0.0, 0.0, 0.0};
    int ping[4]={0, 0, 0};

};


bool checkPacket(string s);
double updateMeasurenment(string s, int n);


int main(void){
    struct deviceManager dm;
    struct deviceManager *ptr = &dm;
    string s;
    char u;
    int n;
    
    
    while (1)
    {
        cout<<"Enter the packet: ";
        getline(cin, s);
        if(s.at(0)!='#') break;
        u = s.at(1);
        if(checkPacket(s)){
            switch(u){
            case 'A':
                ptr->ping[0]+=1;
                ptr->measurement[0] = updateMeasurenment(s, s.size());
                break;

            case 'B':
                ptr->ping[1]+=1;
                ptr->measurement[1] = updateMeasurenment(s, s.size());
                break;

            case 'C':
                ptr->ping[2]+=1;
                ptr->measurement[2] = updateMeasurenment(s, s.size());
                break;
            default:
                cout<<"Invalid Device\n";
                ptr->ping[3]+=1;    
            }
        }else{
            cout<<"Packet structure is missing...\n";
        }
        s.clear();
        cout<<"Measurements Device/frequency-Device 1: "<<ptr->measurement[0]<<'/'<< ptr->ping[0]<<" || Device2: "<<ptr->measurement[1]<<'/'<< ptr->ping[1]<<" || Device3: "<<ptr->measurement[2]<<'/'<< ptr->ping[2]<<" || Invalid Entry: "<<ptr->ping[3]<<'\n';
    }
    return 0;
}

bool checkPacket(string s) {
    int n = s.find(' ');
    if((s.size()<4) || (s.size()!= 3 + (s.at(2)-'0')) || (n == 0)){
        return false;
    }else{
        return true;
    }
}
    

double updateMeasurenment(string s, int n){
    string temp;
    for(int i = 3;i<n;i++){
        temp +=s.at(i);
    }
    return stod(temp);
}
