#include<iostream>
#include<vector>
using namespace std;

class gymMember
{
    private:
    string memName;
    int memberId=0;
    bool feePaid;
    bool enteredGym;

public:   
    gymMember(const string& name)
    {

        memName= name;
        feePaid = false;
        enteredGym= false;
        static int nextMemberId = 1;
        memberId = nextMemberId++;
    }

    string getMemName()
    {
        return memName;
    }

    int getMemId()
    {
        return memberId;
    }

    bool isFeePaid()
    {
        return feePaid;
    }
    void payfee()
    {
        feePaid= true;
        cout<<"Fee successfully paid. Thank you! "<<endl;
    }

    void enterGym() {
        if (feePaid) {
            enteredGym = true;
            cout << "Welcome, " << memName << "! You have entered the gym.";
        } else {
            cout << "Sorry, " << memName << ". You need to pay the fee first.";
        }
    }

    void leaveGym() {
        if (enteredGym) {
            enteredGym = false;
            std::cout << "Goodbye, " << memName << "! You have left the gym.";
        } else {
            std::cout << "You are not currently in the gym.";
        }
    }

   
    

    void display()
    {
        cout<<endl<<"Member Id :- "<<memberId<<endl<<"Name :- "<<memName<<endl;
        if (feePaid) {
            cout << "Fee Status: Paid"<<endl;
        } else {
            cout << "Fee Status: Not Paid"<<endl;
        }
        if (enteredGym) {
            cout << "Entry Status: Entered";
        } else {
            cout << "Entry Status: Not Entered";
        }
        cout<<endl;
    }

};

class Gym
{
    vector<gymMember> members;

    public:
    void registerMember(string& memname)
    {
        members.push_back(gymMember(memname));
        cout<<"Member successfully registered."<<endl;
    }

    void dipalyMembers()
    {
        if(members.empty())
        {
            cout<<"Member Not registerd";
        }
        else{
        cout<<"Registered Members"<<endl;
        for(auto& member : members)
        {
            member.display();
        }
    }
    }

    gymMember* findMemberByItsName(string& name )
    {
        for (auto& member : members) {
            if (member.getMemName() == name) {
                return &member;
            }
        }
        return nullptr;



    }
};

int main()
{
    Gym gym ;
    char choice ;

    do{
        cout<<"\nMenu:-"<<endl<<"1.Register"<<endl<<"2.Display"<<endl<<"3.Pay Fee"<<endl<<"4.Enter Gym"<<endl<<"5.Leave Gym"<<endl<<"6.Exit";
        
        cout<<"\nEnter Your Chioce :- ";
        cin>>choice;

        switch (choice)
        {
        case '1':{
            string MemberName ;
            cout<<"\nEnter Member Name :- ";
            cin>>MemberName;
            gym.registerMember(MemberName);
            break;
        }
        case '2':{
            gym.dipalyMembers();
            break;
        }
        case '3':
        {
            cout << "Enter member name to pay fee: ";
            string memberName;
            cin>>memberName;
            gymMember* member = gym.findMemberByItsName(memberName);
                if (member != nullptr) {
                    member->payfee();
                } else {
                    cout << "Member not found.\n";
                }

                break;


        }
        case '4':
        {
            cout << "Enter member name to Enter the gyme: ";
            string memberName;
            cin>>memberName;
            gymMember* member = gym.findMemberByItsName(memberName);
                if (member != nullptr) {
                    member->enterGym();
                } else {
                    cout << "Member not found.\n";
                }

                break;
        }
        

        case '5':
        {
            cout << "Enter member name to leave the gym: ";
            string memberName;
            cin>>memberName;
            gymMember* member = gym.findMemberByItsName(memberName);
                if (member != nullptr) {
                    member->leaveGym();
                } else {
                    cout << "Member not found.\n";
                }

                break;
        }

        case '6':{
            cout<<"Exiting Program";
            break;
        }
        
        

        default:
        {
            cout<<"Invalid choice. Please try again.";
            break;
        }

        }
    
}while(choice!='6');
    return 0;
}