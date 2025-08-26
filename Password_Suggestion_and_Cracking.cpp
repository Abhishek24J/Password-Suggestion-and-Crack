#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int max_char = 26;

void passwordCrack(char str[], int len)
{
    int entropy = 0;
    long int crack_speed = 2800000000;
    int i;

    int p_UppercaseCharacters = 0, p_LowercaseCharacters = 0, p_SpecialCharacters = 0, p_Numbers = 0;
    int e_UppercaseCharacters = 26, e_LowercaseCharacters = 26, e_SpecialCharacters = 33, e_Numbers = 10;

    //counting the specific type (Uppercase, Lowercase, Digits, Special Characters)
    for(i=0; i<len; i++)
        {
            if(islower(str[i]))
                p_LowercaseCharacters += 1;

            if(isupper(str[i]))
                p_UppercaseCharacters += 1;

            if(isdigit(str[i]))
                p_Numbers += 1;

            if(!isalpha(str[i]) && !isdigit(str[i]))
                p_SpecialCharacters += 1;
        }

    //displaying the specific type (Uppercase, Lowercase, Digits, Special Characters)
    cout<<"The Password contains the following :- ";
    if(p_UppercaseCharacters > 0)
    {
        cout<<"\n  -> Uppercase Letters :- "<<p_UppercaseCharacters;
        entropy += e_UppercaseCharacters;
    }


    if(p_LowercaseCharacters > 0)
    {
        cout<<"\n  -> Lowercase Letters :- "<<p_LowercaseCharacters;
        entropy += e_LowercaseCharacters;
    }

    if(p_SpecialCharacters > 0)
    {
        cout<<"\n  -> Special Letters :- "<<p_SpecialCharacters;
        entropy += e_SpecialCharacters;
    }

    if(p_Numbers > 0)
    {
        cout<<"\n  -> Digits :- "<<p_Numbers;
        entropy += e_Numbers;
    }

    
    double cracked = ((pow(entropy,len)) / crack_speed);
    
    
    //breaking the time into centuires, decades, years, months, days, minutes, seconds
    double decimalCenturies = cracked/(3600.0*24*365*10*100);
    int centuries = floor(decimalCenturies);
    
    double decimalDecades = (decimalCenturies-centuries)*100;
    int decades = floor(decimalDecades);
    
    double decimalYears = (decimalDecades-decades)*10;
    int years = floor(decimalYears);
    
	double decimalMonths =(decimalYears-years)*12;
	int months = floor(decimalMonths);
					
	double decimalDays = (decimalMonths-months)*30;
	int days = floor(decimalDays);
					
	double decimalHours = (decimalDays-days)*24;
	int hours = floor(decimalHours);
					
	double decimalMinutes = (decimalHours-hours)*60;
	int minutes = floor(decimalMinutes);
					
	double decimalSeconds = (decimalMinutes-minutes)*60;
	int seconds = floor(decimalSeconds);
    
    std::stack<int> timeStack;
    
    //checking and displaying the respective time
    cout<<"\nCracking time of the Password :- ";
    if(centuries > 0)
    {
		if(centuries == 1)
		{
			cout<<"1 century ";
			timeStack.push(1);
		}
		else
		{
			cout<<centuries<<" centuries ";
			timeStack.push(centuries);
		}
	}
	
	if(decades > 0)
	{
		if(decades == 1)
		{
			cout<<"1decade ";
			timeStack.push(1);
		}
		else
		{
			cout<<decades<<" decades ";
			timeStack.push(decades);
		}
	}

    if(years > 0)
    {
		if(years == 1)
		{
			cout<<"1 year ";
			timeStack.push(1);
		}
		else
		{
			cout<<years<<" years ";
			timeStack.push(decades);
		}
	}

	if(months > 0)
	{
		if(months == 1)
		{
			cout<<"1 month ";
			timeStack.push(1);
		}
		else
		{
			cout<<months<<" months ";
			timeStack.push(decades);
		}
	}

	if(days > 0)
	{
		if(days == 1)
		{
			cout<<"1 day ";
			timeStack.push(1);
		}
			else
			{
			cout<<days<<" days ";
			timeStack.push(decades);
		}
	}
	
    if(hours > 0)
	{
		if(hours == 1)
		{
			cout<<"1 hour ";
			timeStack.push(1);
		}
		else
		{
		    cout<<hours<<" hours ";
		    timeStack.push(decades);
		}
	}

	if(minutes > 0)
	{
		if(minutes == 1)
		{
			cout<<"1 minute ";
			timeStack.push(1);
		}
		else
		{
		    cout<<minutes<<" minutes ";
		    timeStack.push(decades);
		}
	}

	if(seconds > 0)
	{
		if(seconds == 1)
		{
			cout<<"1 second ";
			timeStack.push(1);
		}
		else
		{
		    cout<<seconds<<" seconds ";
		    timeStack.push(decades);
		}
	}

	if(timeStack.size()==0)
	    cout<<"Less than 1 second";
}



//Function to count no.of ways the password can be re-written into
int factorial(int n)
{
	int fact = 1;
	for(int i=2; i<=n; i++)
		fact=fact*i;
	return fact;
}

int countWays(char str[], int len)
{
    int freq[max_char];
	memset(freq, 0, sizeof(freq));

	for(int i=0; i<len; i++)
		if(str[i] >= 'a')
			freq[str[i] - 'a']++;

	int fact = 1;
	for(int i=0; i<max_char; i++)
		fact=fact*factorial(freq[i]);

	// finding factorial of size of string and dividing it by factorial found after multiplying
	return factorial(len)/fact;
}



//Function to check strength of the password
const char *passwordStrength(char str[], int len)
{
    int l_case=0, u_case=0, digit=0, special=0;
    int i;

    //displaying the specific type (Uppercase, Lowercase, Digits, Special Characters)
    for(i=0; i<len; i++)
        {
            if(islower(str[i]))
                l_case=1;
            if(isupper(str[i]))
                u_case=1;
            if(isdigit(str[i]))
                digit=1;
            if(!isalpha(str[i]) && !isdigit(str[i]))
                special=1;
        }
    if(l_case && u_case && digit && special && len>=8)
        return "Strong Password";
    else if((l_case+u_case+digit+special>=3) && len>=6)
        return "Moderate Password";
    else
        return "Weak Password";
}



//function to generate password
int selectArray()
{
    srand(time(NULL));
    int i = rand() % 5;
    if(i == 0)
        i++;
    return i;
}

int getKey()
{
    srand(time(NULL));
    int key = rand() % 26;
    return key;
}

string generate_password(int length)
{

    string pass = "";

    //Strings whose characters will be used to build password
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s_symbol = "!@#$%&";
    string number = "0123456789";
    int key, count_alphabet = 0, count_ALPHABET = 0, count_number = 0, count_s_symbol = 0;

    int count = 0;
    while(count < length)
    {
        int k = selectArray();
        if(count == 0)
        {
            k = k % 3;
            if(k == 0)
                k++;
        }
        switch (k) 
        {
            case 1:
            if((count_alphabet == 2) && (count_number == 0 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_s_symbol == 0))
                break;

            key = getKey();
            pass = pass + alphabet[key];
            count_alphabet++;
            count++;
            break;

            case 2:
            if((count_ALPHABET == 2) && (count_number == 0 || count_alphabet == 0 || count_alphabet == 1 || count_s_symbol == 0))
                break;

            key = getKey();
            pass = pass + ALPHABET[key];
            count_ALPHABET++;
            count++;
            break;

            case 3:
            if((count_number == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 1 || count_ALPHABET == 0 || count_s_symbol == 0))
                break;

            key = getKey();
            key = key % 10;
            pass = pass + number[key];
            count_number++;
            count++;
            break;

            case 4:
            if((count_s_symbol == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_number == 0))
                break;

            key = getKey();
            key = key % 6;
            pass = pass + s_symbol[key];
            count_s_symbol++;
            count++;
            break;
        }
    }
    return pass;
}



// adding more characters to suggest strong password
string add_more_char(string st, int need)
{
    int pos = 0;
 
    // all 26 letters
    string combi = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%&";
 
    for(int i=0; i <need; i++)
    {
        pos = rand() % st.length();
        st.insert(pos, 1, combi[rand() % 26]);
    }
    return st;
}
 
// make powerfull string
string suggester(int l, int u, int d, int s, string st)
{
    string num = "0123456789";
    string low_case = "abcdefghijklmnopqrstuvwxyz";
    string up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string spl_char = "!@#$%&";
 
    // position at which place a character
    int pos = 0;
 
    // if there is no lowercase char in input string, add it
    if(l == 0)
    {
        // generate random integer under string length
        pos = rand() % st.length();
 
        // generate random integer under 26 for indexing of a to z
        st.insert(pos, 1, low_case[rand() % 26]);
    }
 
    // if there is no upper case char in input string, add it
    if(u == 0)
    {
        pos = rand() % st.length();
        st.insert(pos, 1, up_case[rand() % 26]);
    }
 
    // if there is no digit in input string, add it
    if(d == 0)
    {
        pos = rand() % st.length();
        st.insert(pos, 1, num[rand() % 10]);
    }
 
    // if there is no special character in input string, add it
    if(s == 0)
    {
        pos = rand() % st.length();
        st.insert(pos, 1, spl_char[rand() % 6]);
    }
 
    return st;
}
 
//suggest password in similar to the original password
void generate(int n, string p)
{
	int l = 0, u = 0, d = 0, s = 0, need = 0;
	string suggest;

	for(int i=0; i<n; i++)
	{
		if(p[i] >= 97 && p[i] <= 122)
			l = 1;
		else if(p[i] >= 65 && p[i] <= 90)
			u = 1;
		else if(p[i] >= 48 && p[i] <= 57)
			d = 1;
		else
			s = 1;
	}
    
    cout<<"\nSuggested password :- "<<endl;
 
    //suggest 5 strong strings
    for(int i=0; i<5; i++)
    {
        suggest=suggester(l, u, d, s, p);
        need = 8 - suggest.length();
        if(need > 0)
            suggest=add_more_char(suggest, need);
        cout<<suggest<<"\t";
    }
}



//function to give suggestions
void passwordSuggestion(char str[], string input_string)
{
    if(strcmp(str,"Weak Password") == 0)
    {
        cout<<"Suggestions :- ";
        cout<<"\n  -> Password is Weak meaning that you should change your password immediately";
        cout<<"\n  -> Password must be 8-16 chars long";
        cout<<"\n  -> Password must have a combination of atleast one of all Uppercase Letters, Lowercase Letters, Digits & Special Charcters";
        cout<<"\n  -> Password must begin with a letter (Uppercase/Lowercase Letters)";
        generate(input_string.length(), input_string);
    }
    else if(strcmp(str,"Moderate Password") == 0)
    {
        cout<<"Suggestions :- ";
        cout<<"\n  -> Password is Moderate meaning that you can work with this but you should try keeping Strong Password";
        cout<<"\n  -> Password must be 8-16 chars long";
        cout<<"\n  -> Password must have a combination of atleast one of all Uppercase Letters, Lowercase Letters, Digits & Special Charcters";
    }
}



//function for Choice 1
void choice1()
{
    char password[16], strength[10];
    int length, ways, crack_time;
    
    string input_string;

    cout<<"\nEnter your Password :- ";
    cin>>input_string;
    
    strcpy(password, input_string.c_str());

    cout<<"\nYour Password is :- "<<password<<endl;

    length = strlen(password);
    cout<<"Length of the Password is :- "<<length<<endl;

    ways = countWays(password, length);
    cout<<"No.of ways the Password can be re-written into :- "<<ways<<" ways"<<endl;

    passwordCrack(password, length);
    
    strcpy(strength,passwordStrength(password, length));
    cout<<"\nStrength of the Password :- "<<strength<<endl;
    passwordSuggestion(strength, input_string);
}



//function for Choice 2
void choice2()
{
    char password[16], strength[10];
    int length, ways, crack_time;

    cout<<"\nEnter the length of Password you want :- ";
    cin>>length;

    if((length>=8) && (length<=16))
    {
        string arr = "";
        arr = generate_password(length);
        strcpy(password, arr.c_str());
        cout<<"\nYour Password is :- "<<password<<endl;

        ways = countWays(password, length);
        cout<<"No.of ways your password can be re-written into :- "<<ways<<" ways"<<endl;

        passwordCrack(password, length);

        strcpy(strength,passwordStrength(password, length));
        cout<<"\nStrength of your Password :- "<<strength<<endl;
    }
    else
    {
        cout<<"Password must be 8-16 characters long";
    }

}



//function for Result
void result(int choice)
{
    switch(choice){
        case 1:{
            choice1();
            cout<<endl;
            break;
        }

        case 2:{
            choice2();
            cout<<endl;
            break;
        }

        case 3:{
            cout<<"Thank you\n";
            exit(0);
        }

        default:
            cout<<"Wrong Input\n";
    }
}



//function for Menu
void menu()
{
    int choice;
    char ch = 'y';
    do{
        cout<<"Press 1 to Know insights of your Password\n";
        cout<<"Press 2 to Customize a Password\n";
        cout<<"Press 3 to Exit\n";

        cout<<"Enter your choice :- ";
        cin>>choice;
        cout<<"You choice is :- "<<choice<<endl;

        result(choice);
        cout<<"\nWant to continue further(y/n)? :- ";
        cin>>ch;
        cout<<endl;
    }while(ch=='y');
}


int main()
{
    menu();
    return 0;
}
