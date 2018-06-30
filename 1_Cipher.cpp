#include <iostream>
#include <vector>
#include <list>
#include <string> 
using namespace std;

int static personIdGenerator = 0;
int static msgIdGenerator = 0;

class Message; class Person; class Cipher;

class Cipher{
private:
    int shift;
public:
    Cipher(int key){
        this->shift = key;
    }
    
    char encodeChar(char ch){
        if (!isalpha(ch))
            return ch;
        // checking for upper case
        if (isupper(ch)){
            ch = (char) ('A' + (ch - 'A' + shift) % 26);
        }
        //else check for lower case
        else{
            ch = (char) ('a' + (ch - 'a' + shift) % 26);
        }
        return ch;
    }
    
    char decodeChar(char ch){
        if (!isalpha(ch))
            return ch;
        // checking for upper case
        if(isupper(ch))
            ch=(char) (((ch-'A') + (26-shift)) % 26 + 'A');
        else
            //checking for lower case
            if(islower(ch))
                ch=(char) (((ch-'a') + (26-shift)) % 26 + 'a');
        return ch;
    }
    //Complete the Cipher Class Here
    string reverse(string message){
        char hold;
        for (int i = 0; i < (message.size()/2); i++){
            hold = message[i];
            message[i] = message[message.size()-(i+1)];
            message[message.size()-(i+1)] = hold;
        }
        return message;
    }
    
    string encodeMessage(string &message){
        for (int i = 0; i < message.size(); i++){
            message[i] = encodeChar(message[i]);
        }
        message = reverse(message);
        return message;
    }
    
    string decodeMessage(string &message){
        for (int i = 0; i < message.size(); i++){
            message[i] = decodeChar(message[i]);
        }
        message = reverse(message);
        return message;
    }
};

class Person{
    
    //Complete the Person Class Here
private:
    //int static personIdGenerator;
    string fname, lname;
public:
    int personId = ++personIdGenerator;
    
    void setName(string first, string last){
        fname = first;
        lname = last;
    }
    
    Person getPerson(){
        return *this;
    }
    string getFullName(){
        return fname + " " + lname;
    }
    
    bool operator==(const Person& right)
        const{
            return(personId == right.personId);
        }
    
    bool operator!=(const Person& right)
        const{
            return(personId != right.personId);
        }
    
    bool operator<(const Person& right)
        const{
            return((personId!= right.personId && fname < right.fname)
                    || (personId!= right.personId
                        && fname == right.fname
                        && lname < right.lname));
        }
    
    bool operator<=(const Person& right)
        const{
            return(*this < right || *this == right);
        }
    
    bool operator>(const Person& right)
        const{ return((personId!= right.personId
                       && fname > right.fname)
                       || (personId!= right.personId
                           && fname == right.fname
                           && lname > right.lname));
        }
    
    bool operator>=(const Person& right)
        const{
            return(*this > right || *this == right);
        }
};

//Place anything you need after the Person Class here

class Message{
private:
    //int static msgIdGenerator;
    Person sender;
    vector <Person> recipients;
    int key;
    string text;
public:
    int msgId = ++msgIdGenerator;
    
    string encrypt(){
        Cipher c(key);
        return c.encodeMessage(text);
    }
    
    string decrypt(){
        Cipher c(key);
        return c.decodeMessage(text);
    }
    
    string getMessage(){
        return decrypt();
    }
    
    Person getSender(){
        return sender;
    }
    
    vector <Person> getReceivers(){
        return recipients;
    }
    
    string retreiveMessage(){
        cout << "From: " << getSender().getFullName() << "\n\nTo: ";
        for (int i = 0; i < getReceivers().size(); i++){
            if (i == (getReceivers().size() - 1)){
                cout << getReceivers()[i].getFullName();
            }
            else{
                cout << getReceivers()[i].getFullName() << ", ";
            }
        }
        cout << "\nMessage: " + getMessage();
        return " ";
    }
    
    Message(Person s, vector <Person> r, string m, int k){
        this -> sender = s;
        for (int i = 0; i < r.size(); i++){
            this -> recipients.push_back(r[i]);
        }
        this -> text = m;
        this -> key = k;
        this->encrypt();
    }
};

//Place anything you need after the Message class here


//Write the printInbox and printSentItems functions here
void printInbox(Person recipient, vector <Message> received){
    cout << "Inbox for " << recipient.getFullName() << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < received.size(); i++){
        for (int j = 0; j < (received.size()+1); j++){
            if(recipient.getFullName() == received[i].getReceivers()[j].getFullName()){
                cout << received[i].retreiveMessage()[j] << endl << endl;
            }
        }
    }
}

void printSentItems(Person sender, vector <Message> sent){
    cout << "Sent Items for " << sender.getFullName() << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < sent.size(); i++){
        if(sender.getFullName() == sent[i].getSender().getFullName()){
            cout << sent[i].retreiveMessage() << endl << endl;
        }
    }
}
    
int main(){
    //Declare your message store here
    string m1 = "Hello";
    string m2 = "are you coming to the party tomorrow?";
    //Instantiate p1-p4 here
    Person p1;
    Person p2;
    Person p3;
    Person p4;
    p1.setName("John", "Smith");
    p2.setName("Michelle", "Cooper");
    p3.setName("David", "Herman");
    p4.setName("Joseph", "Bokara");
    //make any type of list or vector  of Persons who would
    //be recipients of message m1 and instantiate the message
    //(make sure you use the same one for message m2)
    vector <Person> recievers;
    recievers.push_back(p2);
    recievers.push_back(p3);
    Message message1(p1, recievers, m1, 3);
    recievers[0] = p1;
    recievers[1] = p2;
    recievers.push_back(p4);
    Message message2(p3, recievers, m2, 3);
    vector <Message> messageStore;
    messageStore.push_back(message1);
    messageStore.push_back(message2);

    /* Call getInbox,getSentItems for p1 and then for p3 passing the messageStore along with the person in each case (4statements) */
    
    printInbox(p1, messageStore);
    printSentItems(p1, messageStore);
    printInbox(p2, messageStore);
    printSentItems(p2, messageStore);
    printInbox(p3, messageStore);
    printSentItems(p3, messageStore);
    printInbox(p4, messageStore);
    printSentItems(p4, messageStore);
    
    return 0;
}
