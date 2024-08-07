#include <bits/stdc++.h>
using namespace std;
class User;
class Icard;
class System;
class transfer;
vector<User> Users_List;
vector<Icard *> card_list;
vector<transfer> transfer_list;

class transfer
{
public:
    int from_user_id, to_id;
    string from_card_id, to_card_id;
    double amount;
    transfer() {}
    transfer(int from, int to, string fro, string too, double Amount)
    {
        from_user_id = from;
        to_id = to;
        from_card_id = fro;
        to_card_id = too;
        amount = Amount;
    }
};

class Icard
{
public:
    double amount_money;
    int card_type, owner_id;
    string card_id;
    virtual transfer send_money(string Card_id, int Amount) = 0;
    virtual transfer send_money(int user_id, int Amount) = 0;
};

Icard *check(string Card_ID);
Icard *check(int user_id);

class Alnmr_card : public Icard
{
public:
    Alnmr_card() {};
    Alnmr_card(double Amount_money, string Card_id, int Owner_id)
    {
        amount_money = Amount_money;
        card_id = Card_id;
        owner_id = Owner_id;
        card_type = 1;
    }

    transfer send_money(string Card_id, int Amount)
    {
        double all = Amount + (Amount * (0 / 100));
        if (all > amount_money)
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        Icard *card_send = check(Card_id);
        if (card_send == new Alnmr_card(-1, "-1", -1))
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        else
        {

            for (int i = 0; i < card_list.size(); i++)
            {
                if (card_list[i]->card_id == card_send->card_id)
                {
                    card_list[i]->amount_money = amount_money + Amount;
                }
                if (card_list[i]->card_id == card_id)
                {
                    card_list[i]->amount_money = amount_money - all;
                }
            }
            return transfer(owner_id, card_send->owner_id, card_id, card_send->card_id, (double)Amount);
        }
    }

    transfer send_money(int user_id, int Amount)
    {
        double all = Amount + (Amount * (0 / 100));
        if (all > amount_money)
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        Icard *card_send = check(user_id);
        if (card_send == new Alnmr_card(-1, "-1", -1))
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        else
        {
            for (int i = 0; i < card_list.size(); i++)
            {
                if (card_list[i]->card_id == card_send->card_id)
                {
                    card_list[i]->amount_money = amount_money + Amount;
                }
                if (card_list[i]->card_id == card_id)
                {
                    card_list[i]->amount_money -= all;
                }
            }
            return transfer(owner_id, card_send->owner_id, card_id, card_send->card_id, (double)Amount);
        }
    }
};

class Master_card : public Icard
{
public:
    Master_card() {};
    Master_card(double Amount_money, string Card_id, int Owner_id)
    {
        amount_money = Amount_money;
        card_id = Card_id;
        owner_id = Owner_id;
        card_type = 2;
    }

    transfer send_money(string Card_id, int Amount)
    {
        double all = Amount + (Amount * (12.5 / 100));
        if (all > amount_money)
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        Icard *card_send = check(Card_id);
        if (card_send == new Alnmr_card(-1, "-1", -1))
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        else
        {

            for (int i = 0; i < card_list.size(); i++)
            {
                if (card_list[i]->card_id == card_send->card_id)
                {
                    card_list[i]->amount_money = amount_money + Amount;
                }
                if (card_list[i]->card_id == card_id)
                {
                    card_list[i]->amount_money -= all;
                }
            }
            return transfer(owner_id, card_send->owner_id, card_id, card_send->card_id, (double)Amount);
        }
    }

    transfer send_money(int user_id, int Amount)
    {
        double all = Amount + (Amount * (12.5 / 100));
        if (all > amount_money)
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        Icard *card_send = check(user_id);
        if (card_send == new Alnmr_card(-1, "-1", -1))
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        else
        {
            for (int i = 0; i < card_list.size(); i++)
            {
                if (card_list[i]->card_id == card_send->card_id)
                {
                    card_list[i]->amount_money = amount_money + Amount;
                }
                if (card_list[i]->card_id == card_id)
                {
                    card_list[i]->amount_money -= all;
                }
            }
            return transfer(owner_id, card_send->owner_id, card_id, card_send->card_id, (double)Amount);
        }
    }
};

class visa_card : public Icard
{
public:
    visa_card() {};
    visa_card(double Amount_money, string Card_id, int Owner_id)
    {
        amount_money = Amount_money;
        card_id = Card_id;
        owner_id = Owner_id;
        card_type = 3;
    }
    transfer send_money(string Card_id, int Amount)
    {
        double all = Amount + (Amount * (11.5 / 100));
        if (all > amount_money)
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        Icard *card_send = check(Card_id);
        if (card_send == new Alnmr_card(-1, "-1", -1))
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        else
        {

            for (int i = 0; i < card_list.size(); i++)
            {
                if (card_list[i]->card_id == card_send->card_id)
                {
                    card_list[i]->amount_money = amount_money + Amount;
                }
                if (card_list[i]->card_id == card_id)
                {
                    card_list[i]->amount_money -= all;
                }
            }
            return transfer(owner_id, card_send->owner_id, card_id, card_send->card_id, (double)Amount);
        }
    }

    transfer send_money(int user_id, int Amount)
    {
        double all = Amount + (Amount * (11.5 / 100));
        if (all > amount_money)
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        Icard *card_send = check(user_id);
        if (card_send == new Alnmr_card(-1, "-1", -1))
        {
            return transfer(-1, -1, "-1", "-1", -1);
        }
        else
        {
            for (int i = 0; i < card_list.size(); i++)
            {
                if (card_list[i]->card_id == card_send->card_id)
                {
                    card_list[i]->amount_money = amount_money + Amount;
                }
                if (card_list[i]->card_id == card_id)
                {
                    card_list[i]->amount_money -= all;
                }
            }
            return transfer(owner_id, card_send->owner_id, card_id, card_send->card_id, (double)Amount);
        }
    }
};

class User
{
public:
    string User_Name, password, default_Card;
    int User_ID;
    User() {};
    User(string user_Name, string Password, int User_id, string card_id)
    {
        User_Name = user_Name;
        password = Password;
        User_ID = User_id;
        default_Card = card_id;
    }
};

Icard *check(string Card_ID)
{
    for (int i = 0; i < card_list.size(); i++)
    {
        if (card_list[i]->card_id == Card_ID)
        {
            return card_list[i];
        }
    }
    return new Alnmr_card(-1, "-1", -1);
}

Icard *check(int owner_ID)
{
    User user = {"-1", "-1", -1, "-1"};
    for (int i = 0; i < Users_List.size(); i++)
    {
        if (Users_List[i].User_ID == owner_ID)
        {
            user = Users_List[i];
        }
    }
    if (user.User_ID == -1)
    {
        return new Alnmr_card(-1, "-1", -1);
    }
    for (int i = 0; i < card_list.size(); i++)
    {
        if (card_list[i]->card_id == user.default_Card)
        {
            return card_list[i];
        }
    }
    return new Alnmr_card(-1, "-1", -1);
}

class System
{
public:
    friend class User;
    System()
    {
        Users_List.clear();
        ifstream User_file("users.dat", ios::binary | ios::in);
        if (User_file.is_open())
        {
            while (User_file.peek() != EOF)
            {
                User user;
                getline(User_file, user.User_Name, '\0');
                getline(User_file, user.password, '\0');
                getline(User_file, user.default_Card, '\0');
                User_file.read(reinterpret_cast<char *>(&user.User_ID), sizeof(user.User_ID));

                Users_List.push_back(user);
            }
            User_file.close();
        }

        card_list.clear();
        ifstream card_file("cards.dat", ios::binary | ios::in);
        if (card_file.is_open())
        {
            while (card_file.peek() != EOF)
            {
                Icard *card;
                string card_id;
                double amount;
                int card_type;
                int owner_id;
                getline(card_file, card_id, '\0');
                card_file.read(reinterpret_cast<char *>(&amount), sizeof(amount));
                card_file.read(reinterpret_cast<char *>(&card_type), sizeof(card_type));
                card_file.read(reinterpret_cast<char *>(&owner_id), sizeof(owner_id));
                if (card_type == 1)
                {
                    card = new Alnmr_card(amount, card_id, owner_id);
                }
                else if (card_type == 2)
                {
                    card = new Master_card(amount, card_id, owner_id);
                }
                else
                {
                    card = new visa_card(amount, card_id, owner_id);
                }
                card_list.push_back(card);
            }
            card_file.close();
        }

        transfer_list.clear();
        ifstream trans_file("trans.dat", ios::binary | ios::in);
        if (trans_file.is_open())
        {
            while (trans_file.peek() != EOF)
            {
                transfer trans;
                getline(trans_file, trans.from_card_id, '\0');
                getline(trans_file, trans.to_card_id, '\0');
                trans_file.read(reinterpret_cast<char *>(&trans.from_user_id), sizeof(trans.from_user_id));
                trans_file.read(reinterpret_cast<char *>(&trans.to_id), sizeof(trans.to_id));
                trans_file.read(reinterpret_cast<char *>(&trans.amount), sizeof(trans.amount));
                transfer_list.push_back(trans);
            }
            trans_file.close();
        }
    }

    int Start_Menu()
    {
        int option;
        cout << "Menu:" << endl;
        cout << "\t" << "1:Login" << endl;
        cout << "\t" << "2:Sign Up" << endl;
        cout << "Enter number in range 1 - 2: ";
        cin >> option;
        if (option != 1 && option != 2)
        {
            cout << "ERROR: " << option << " is an invalid value" << '\n';
            cout << "Enter number: " << endl;
            cout << "\t" << "1: Try again" << endl;
            cout << "\t" << "Any button: Exit" << endl;
            char Error_option;
            cin >> Error_option;
            if (Error_option == '1')
            {
                return Start_Menu();
            }
            return 0;
        }
        return option;
    }

    User Sign_Up_Menu()
    {
        string User_Name, Password;
        cout << "Enter user name: ";
        cin >> User_Name;
        cout << "Enter password: ";
        cin >> Password;
        cin.exceptions(cin.failbit);
        try
        {
            for (int i = 0; i < Users_List.size(); i++)
            {
                if (Users_List[i].User_Name == User_Name)
                {
                    string error = User_Name;
                    throw error;
                }
            }
        }
        catch (string error)
        {
            cerr << "ERROR: " << error << " is already used" << '\n';
            cerr << "Enter number:" << endl;
            cerr << "\t" << "1: Try again" << endl;
            cerr << "\t" << "Any button: Exit" << endl;
            char Error_option;
            cin >> Error_option;
            if (Error_option == '1')
            {
                Sign_Up_Menu();
            }
            else
            {

                User invalid_user = {"error", "error", -1, "-1"};
                return invalid_user;
            }
        }
    Try:
        cout << "Choose card: " << endl;
        cout << "\t 1: Alnmr card" << endl;
        cout << "\t 2: Master card" << endl;
        cout << "\t 3: Visa card" << endl;
        int option;
        cin >> option;
        if (option > 3 || option < 1)
        {
            goto Try;
        }
        Icard *default_Card = NULL;
        if (option == 1)
        {
            default_Card = new Alnmr_card;
        }
        else if (option == 2)
        {
            default_Card = new Master_card;
        }
        else
        {
            default_Card = new visa_card;
        }
        string card_id;
        double amount_Money;
    try_again:
        cout << "Card ID :" << endl;
        cin >> card_id;
        for (int i = 0; i < card_id.size(); i++)
        {
            if (card_id[i] < '0' || card_id[i] > '9' || card_id.size() < 16 || card_id.size() > 16)
            {
                cout << "Card ID must have 16 digits " << endl;
                cout << "Plase try again" << endl;
                goto try_again;
            }
        }
        for (int i = 0; i < card_list.size(); i++)
        {
            if (card_list[i]->card_id == card_id)
            {
                cout << "Card ID is used " << endl;
                cout << "Plase try again" << endl;
                goto try_again;
            }
        }
        cout << "Please enter the amount of money in the card:" << endl;
        cin >> amount_Money;
        default_Card->amount_money = amount_Money;
        default_Card->card_id = card_id;
        default_Card->card_type = option;
        int New_User_ID;
        if (Users_List.empty())
        {
            New_User_ID = 1;
        }
        else
        {
            New_User_ID = (Users_List.back().User_ID) + 1;
        }
        default_Card->owner_id = New_User_ID;
        User New_User = {User_Name, Password, New_User_ID, card_id};
        Add_User_To_System(New_User);
        Add_Card_To_System(default_Card);
        return New_User;
    }

    User Login_Menu()
    {
        string User_Name, Password;
        cout << "Enter user name: ";
        cin >> User_Name;
        cout << "Enter password: ";
        cin >> Password;
        cin.exceptions(cin.failbit);
        try
        {
            for (int i = 0; i < Users_List.size(); i++)
            {
                if (Users_List[i].User_Name == User_Name)
                {
                    if (Users_List[i].password == Password)
                    {
                        return Users_List[i];
                    }
                    else
                    {
                        string error = "Password";
                        throw error;
                    }
                }
            }
            string error = "User name";
            throw error;
        }
        catch (string error)
        {
            cerr << "ERROR: " << error << " is incorrect" << '\n';
            cerr << "Enter number:" << endl;
            cerr << "\t" << "1: Sign Up" << endl;
            cerr << "\t" << "2: Try again" << endl;
            cerr << "\t" << "Any button: Exit" << endl;
            char Error_option;
            cin >> Error_option;
            if (Error_option == '1')
            {
                return Sign_Up_Menu();
            }
            else if (Error_option == '2')
            {
                return Login_Menu();
            }
            else
            {

                User invalid_user = {"error", "error", -1, "-1"};
                return invalid_user;
            }
        }

        User invalid_user = {"error", "error", -1, "-1"};
        return invalid_user;
    }

    void Add_User_To_System(User New_User)
    {
        New_User.User_Name.push_back('\0');
        New_User.password.push_back('\0');
        New_User.default_Card.push_back('\0');
        ofstream User_file;
        User_file.open("users.dat", ios::app | ios::out | ios::binary);
        User_file.write(New_User.User_Name.c_str(), New_User.User_Name.size());
        User_file.write(New_User.password.c_str(), New_User.password.size());
        User_file.write(New_User.default_Card.c_str(), New_User.default_Card.size());
        User_file.write(reinterpret_cast<char *>(&New_User.User_ID), sizeof(New_User.User_ID));
        User_file.close();
        Users_List.push_back(New_User);
    }

    void update_users(User New_User)
    {
        New_User.User_Name.push_back('\0');
        New_User.password.push_back('\0');
        New_User.default_Card.push_back('\0');
        ofstream User_file;
        User_file.open("users.dat", ios::app | ios::out | ios::binary);
        User_file.write(New_User.User_Name.c_str(), New_User.User_Name.size());
        User_file.write(New_User.password.c_str(), New_User.password.size());
        User_file.write(New_User.default_Card.c_str(), New_User.default_Card.size());
        User_file.write(reinterpret_cast<char *>(&New_User.User_ID), sizeof(New_User.User_ID));
        User_file.close();
    }

    vector<Icard *> Show_user_cards(User user)
    {
        int count = 1;
        vector<Icard *> my_cards;
        for (int i = 0; i < card_list.size(); i++)
        {
            if (card_list[i]->owner_id == user.User_ID)
            {
                cout << count++ << ":" << endl;
                cout << "Card name: ";
                if (card_list[i]->card_type == 1)
                {
                    cout << "Alnmr card" << endl;
                }
                else if (card_list[i]->card_type == 2)
                {
                    cout << "Master card" << endl;
                }
                else
                {
                    cout << "Visa card" << endl;
                }
                cout << "Card ID: " << card_list[i]->card_id << endl;
                cout << "Amount money: " << card_list[i]->amount_money << endl;
                my_cards.push_back(card_list[i]);
            }
        }
        return my_cards;
    }

    void Add_New_Card(User user)
    {
    Try:
        cout << "Choose card: " << endl;
        cout << "\t 1: Alnmr card" << endl;
        cout << "\t 2: Master card" << endl;
        cout << "\t 3: Visa card" << endl;
        int option;
        cin >> option;
        if (option > 3 || option < 1)
        {
            goto Try;
        }
        Icard *default_Card = NULL;
        if (option == 1)
        {
            default_Card = new Alnmr_card;
        }
        else if (option == 2)
        {
            default_Card = new Master_card;
        }
        else
        {
            default_Card = new visa_card;
        }
        string card_id;
        double amount_Money;
    try_again:
        cout << "Card ID :" << endl;
        cin >> card_id;
        for (int i = 0; i < card_id.size(); i++)
        {
            if (card_id[i] < '0' || card_id[i] > '9' || card_id.size() < 16 || card_id.size() > 16)
            {
                cout << "Card ID must have 16 digits " << endl;
                cout << "Plase try again" << endl;
                goto try_again;
            }
        }
        for (int i = 0; i < card_list.size(); i++)
        {
            if (card_list[i]->card_id == card_id)
            {
                cout << "Card ID is used " << endl;
                cout << "Plase try again" << endl;
                goto try_again;
            }
        }
        cout << "Please enter the amount of money in the card:" << endl;
        cin >> amount_Money;
        default_Card->amount_money = amount_Money;
        default_Card->card_id = card_id;
        default_Card->card_type = option;
        default_Card->owner_id = user.User_ID;
        Add_Card_To_System(default_Card);
    }

    void Add_Card_To_System(Icard *New_card)
    {
        New_card->card_id.push_back('\0');
        ofstream Card_file;
        Card_file.open("cards.dat", ios::app | ios::out | ios::binary);
        Card_file.write(New_card->card_id.c_str(), New_card->card_id.size());
        Card_file.write(reinterpret_cast<char *>(&New_card->amount_money), sizeof(New_card->amount_money));
        Card_file.write(reinterpret_cast<char *>(&New_card->card_type), sizeof(New_card->card_type));
        Card_file.write(reinterpret_cast<char *>(&New_card->owner_id), sizeof(New_card->owner_id));
        Card_file.close();
        card_list.push_back(New_card);
    }

    void update_card()
    {
        remove("cards.dat");
        for (int i = 0; i < card_list.size(); i++)
        {
            Icard *New_card = card_list[i];
            New_card->card_id.push_back('\0');
            ofstream Card_file;
            Card_file.open("cards.dat", ios::app | ios::out | ios::binary);
            Card_file.write(New_card->card_id.c_str(), New_card->card_id.size());
            Card_file.write(reinterpret_cast<char *>(&New_card->amount_money), sizeof(New_card->amount_money));
            Card_file.write(reinterpret_cast<char *>(&New_card->card_type), sizeof(New_card->card_type));
            Card_file.write(reinterpret_cast<char *>(&New_card->owner_id), sizeof(New_card->owner_id));
            Card_file.close();
        }
    }

    int Main_Menu()
    {
        int option;
        cout << "Menu:" << endl;
        cout << "\t" << "1: Show My Cards" << endl;
        cout << "\t" << "2: Add New Card" << endl;
        cout << "\t" << "3: Show transaction history" << endl;
        cout << "\t" << "4: Select default card" << endl;
        cout << "\t" << "5: Send Money" << endl;
        cout << "\t" << "6: Logout" << endl;
        cout << "\t" << "7: Exit" << endl;
        cout << "Enter number in range 1 - 7: ";
        cin.exceptions(cin.failbit);
        try
        {
            cin >> option;
            if (option < 1 || option > 7)
                throw option;
        }
        catch (int error)
        {
            cerr << "ERROR: " << error << " is an invalid value" << '\n';
            cerr << "Enter number: " << endl;
            cerr << "\t" << "1: Try again" << endl;
            cerr << "\t" << "Any button: Exit" << endl;
            char Error_option;
            cin >> Error_option;
            if (Error_option == '1')
            {
                return Main_Menu();
            }
            return 7;
        }
        return option;
    }

    void Set_def_card(User &user, Icard *card)
    {
        ofstream User_file;
        User_file.open("users.dat", ios::app | ios::out | ios::binary);
        User_file.clear();
        User_file.close();
        for (int i = 0; i < Users_List.size(); i++)
        {
            if (Users_List[i].User_ID == user.User_ID)
            {
                Users_List[i].default_Card = card->card_id;
                user.default_Card = card->card_id;
            }
            Users_List[i].User_Name.pop_back();
            Users_List[i].password.pop_back();
            update_users(Users_List[i]);
        }
    }

    void Add_trans_to_System(transfer trans)
    {
        trans.from_card_id.push_back('\0');
        trans.to_card_id.push_back('\0');
        ofstream trans_file;
        trans_file.open("trans.dat", ios::app | ios::out | ios::binary);
        trans_file.write(trans.from_card_id.c_str(), trans.from_card_id.size());
        trans_file.write(trans.to_card_id.c_str(), trans.to_card_id.size());
        trans_file.write(reinterpret_cast<char *>(&trans.from_user_id), sizeof(trans.from_user_id));
        trans_file.write(reinterpret_cast<char *>(&trans.to_id), sizeof(trans.to_id));
        trans_file.write(reinterpret_cast<char *>(&trans.amount), sizeof(trans.amount));
        trans_file.close();
        transfer_list.push_back(trans);
    }

    int trans_menu()
    {
    retry:
        cout << "\t 1: Use username to send money" << endl;
        cout << "\t 2: Use card ID to send money" << endl
             << "-> ";
        int op;
        cin >> op;
        if (op != 1 && op != 2)
        {
            cout << "Invaild option try again" << endl;
            goto retry;
        }
        return op;
    }

    pair<int, double> transfer_process()
    {
        string User_Name;
        double amount;
        int user_id = -1;
        cout << "Enter user name: ";
        cin >> User_Name;
        cin.exceptions(cin.failbit);
        try
        {
            for (int i = 0; i < Users_List.size(); i++)
            {
                if (Users_List[i].User_Name == User_Name)
                {
                    user_id = Users_List[i].User_ID;
                }
            }
            if (user_id == -1)
            {
                string error = "User name";
                throw error;
            }
        }
        catch (string error)
        {
            cerr << "ERROR: " << error << " is incorrect" << '\n';
            cerr << "Try again" << endl;
            return transfer_process();
        }
    re:
        cout << "Enter Amount of Money: ";
        cin >> amount;
        if (amount < 1)
        {
            cout << "ERROR: " << "amount of money" << " is incorrect" << '\n';
            cerr << "Try again" << endl;
            goto re;
        }
        return {user_id, amount};
    }

    pair<string, double> transfer_process(int)
    {
        string card_id;
        double amount;
        cout << "Enter card ID: ";
        cin >> card_id;
    try_again:
        cin >> card_id;
        for (int i = 0; i < card_id.size(); i++)
        {
            if (card_id[i] < '0' || card_id[i] > '9' || card_id.size() < 16 || card_id.size() > 16)
            {
                cout << "Card ID must have 16 digits " << endl;
                cout << "Plase try again" << endl;
                goto try_again;
            }
        }
        bool ok = 0;
        for (int i = 0; i < card_list.size(); i++)
        {
            if (card_list[i]->card_id == card_id)
            {
                ok = 1;
            }
        }
        if (!ok)
        {
            cout << "Invaild Card ID" << endl;
            cout << "Plase try again" << endl;
            goto try_again;
        }
    re:
        cout << "Enter Amount of Money: ";
        cin >> amount;
        if (amount < 1)
        {
            cout << "ERROR: " << "amount of money" << " is incorrect" << '\n';
            cerr << "Try again" << endl;
            goto re;
        }
        return {card_id, amount};
    }

    void Show_trans_his(User user)
    {
        int count = 1;
        for (int i = 0; i < transfer_list.size(); i++)
        {
            if (user.User_ID == transfer_list[i].from_user_id || user.User_ID == transfer_list[i].to_id)
            {
                cout << count++ << " :" << endl;
                cout << "From User : " << Users_List[transfer_list[i].from_user_id - 1].User_Name << endl;
                cout << "To User : " << Users_List[transfer_list[i].to_id - 1].User_Name << endl;
                cout << "Amount of Money : " << transfer_list[i].amount << endl;
                cout << endl;
            }
        }
    }
};

int main()
{
Mstart:

    System sys;
    User user;
    vector<Icard *> my_cards;
    if (sys.Start_Menu() == 1)
    {
        user = sys.Login_Menu();
    }
    else
    {
        user = sys.Sign_Up_Menu();
    }
    if (user.User_ID == -1)
    {
        return 0;
    }
    cout << "Welcome, " << user.User_Name << endl;
start:
    int op = sys.Main_Menu();
    if (op == 1)
    { // show cards

        cout << endl
             << endl
             << "***" << endl;
        vector<Icard *> my_cards = sys.Show_user_cards(user);
        cout << endl
             << "***" << endl
             << endl;
        goto start;
    }
    else if (op == 2)
    { // add card

        cout << endl
             << endl
             << "***" << endl;
        sys.Add_New_Card(user);
        cout << endl
             << "***" << endl
             << endl;
        goto start;
    }
    else if (op == 3)
    { // Show transaction history

        cout << endl
             << endl
             << "***" << endl;
        sys.Show_trans_his(user);
        cout << endl
             << "***" << endl
             << endl;
        goto start;
    }
    else if (op == 4)
    { // Select default card

        cout << endl
             << endl
             << "***" << endl;
        cout << "Your current Default card ID is < " << user.default_Card << " >" << endl;
    retry:
        vector<Icard *> my_cards = sys.Show_user_cards(user);
        int card_num;
        cout << "Enter Card Number " << endl;
        cin >> card_num;
        if (card_num < 1 || card_num > my_cards.size())
        {
            cout << "Invalid Number Try again " << endl;
            goto retry;
        }
        else
        {
            sys.Set_def_card(user, my_cards[card_num - 1]);
            cout << "Default card has been updated" << endl;
            cout << endl
                 << "***" << endl
                 << endl;
            goto start;
        }
    }
    else if (op == 5)
    { // Send Money

        cout << endl
             << endl
             << "***" << endl;
    re_try:
        vector<Icard *> my_cards = sys.Show_user_cards(user);
        Icard *card;
        transfer trans;
        int card_num;
        cout << "Enter Card Number To send Money or 0 to use default" << endl
             << "-> ";
        cin >> card_num;
        if (card_num == 0)
        {
            for (int i = 0; i < my_cards.size(); i++)
            {
                if (my_cards[i]->card_id == user.default_Card)
                {
                    card = my_cards[i];
                    break;
                }
            }
        }
        else if (card_num < 1 || card_num > my_cards.size())
        {
            cout << "Invalid Number Try again " << endl;
            goto re_try;
        }
        else
        {
            card = my_cards[card_num - 1];
        }

        if (sys.trans_menu() == 1)
        {
            pair<int, double> tra = sys.transfer_process();
            trans = card->send_money(tra.first, tra.second);
        }
        else
        {
            pair<string, double> tra = sys.transfer_process(0);
            trans = card->send_money(tra.first, tra.second);
        }
        if (trans.amount == -1)
        {
            cout << "Transfer did not complete" << endl;
            cout << "\t 1 : Try again" << endl;
            cout << "\t Any : Exit" << endl
                 << "-> ";
            int er;
            cin >> er;
            if (er == 1)
            {
                goto re_try;
            }
            else
            {
                goto start;
            }
        }
        sys.Add_trans_to_System(trans);
        sys.update_card();
        cout << "Transfer Complete" << endl;
        cout << endl
             << "***" << endl
             << endl;
        goto start;
    }
    else if (op == 6)
    { // log out
        cout << endl
             << endl;
        goto Mstart;
    }
    else
    {
        return 0;
    }
}