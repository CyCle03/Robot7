#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

using namespace std;

class Person
{
private:
    int id;
    string name;
    string pnumber;
public:
    Person(int id, string name, string pnumber)
    {
        this->id = id;
        this->name = name;
        this->pnumber = pnumber;
    }
    int getId() const
    {
        return this->id;
    }
    string getName() const
    {
        return this->name;
    }
    string getPnumber() const
    {
        return this->pnumber;
    }
    void setId(const int id)
    {
        this->id = id;
    }
    void setName(const string name)
    {
        this->name = name;
    }
    void setPnumber(const string pnumber)
    {
        this-> pnumber = pnumber;
    }
};

void sortAddressbook(vector<Person>& addressbook)
{
    sort(addressbook.begin(), addressbook.end()
    , [](const Person& a, const Person& b) { return a.getId() < b.getId();});
}

int main()
{
    vector<Person> addressbook;
    unique_ptr<Person> p = make_unique<Person>(1, "홍길동", "010-1111-1111");
    addressbook.push_back(*p);
    p = make_unique<Person>(2, "이순신", "010-2222-2222");
    addressbook.push_back(*p);

    int select = -1;

    do
    {
        cout << "--------------------------------------------------" << endl;
        cout << "1. 주소록 조회" << endl;
        cout << "2. 주소록 추가" << endl;
        cout << "3. 주소록 수정" << endl;
        cout << "4. 주소록 삭제" << endl;
        cout << "5. 종료" << endl;
        cout << "메뉴 : ";
        cin >> select;

        switch (select)
        {
            case 1:
            {
                for(Person p : addressbook)
                {
                    cout << "ID : " << p.getId() << " | ";
                    cout << "이름 : " << p.getName() << " | ";
                    cout << "전화번호 : " << p.getPnumber() << endl;
                }
                break;
            }
            case 2:
            {
                int id;
                string name;
                string pnumber;
                cout << "추가하실 id를 입력하세요. : ";
                cin >> id;
                cout << "추가하실 이름을 입력하세요. : ";
                cin >> name;
                cout << "추가하실 전화번호를 입력하세요 : ";
                cin >> pnumber;

                auto p = make_unique<Person>(id, name, pnumber);
                addressbook.push_back(*p);

                sortAddressbook(addressbook);

                break;
            }
            case 3:
            {
                int targetNum;
                cout << "수정하실 ID를 입력하세요 : ";
                cin >> targetNum;

                auto it = find_if(addressbook.begin(), addressbook.end(),
                [targetNum](Person& p){ return p.getId() == targetNum; });

                if(it != addressbook.end())
                {
                    string newName, newPnumber;
                    cout << "새로운 이름을 입력하세요 : ";
                    cin >> newName;
                    cout << "새로운 전화번호를 입력하세요 : ";
                    cin >> newPnumber;

                    it->setName(newName);
                    it->setPnumber(newPnumber);

                    cout << targetNum << " 항목이 성공적으로 수정되었습니다." << endl;
                }
                else
                {
                    cout << "ID : " << targetNum << "를 찾을 수 없습니다. " << endl;
                }

                break;
            }
            case 4:
            {
                int targetNum;
                cout << "삭제하실 ID를 입력하세요. : ";
                cin >> targetNum;

                auto new_end = std::remove_if(addressbook.begin(), addressbook.end(),
                [targetNum](const Person& p){return (p.getId() == targetNum);});
                
                addressbook.erase(new_end, addressbook.end());

                cout << targetNum << " 번호에 해당하는 주소록 항목을 삭제했습니다." << endl;

                break;
            }
            case 5:
            {
                exit(1);
                break;
            }
        }

    } while (select != 0);
    

    return 0;
}
