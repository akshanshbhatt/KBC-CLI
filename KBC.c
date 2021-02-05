/*********************
 *                                                      KBC Game [CSF111 Assignment (Q.1)]
 * This is the orignial C-Language Code of the KBC Program compiled by AKSHANSH BHATT (2019B5PS0754P) for the CSF111 assignment (Take Home).
 * This complete assignment is made possible by the efforts and contribution of every single one in the team.
 * Our team includes - SAKSHAM JAIN (2019B3PS0160P), AKSHANSH BHATT (2019B5PS0754P) and HITANSHU (2019A2PS0687P).
 * We also ensure that this complete project is our own work and we have not plagiarised any line of code from any online source / colleague.
 * Although we haven't licensed our project, Using it for commercial purpose without citing the author(s) will be deemed illegal.
 * The code is well documented and every function or data variable is explained properly. There might be some grammatical mistakes in the docs.
 * For further information refer to the README.txt file.
*********************/
#include<stdio.h> // Standard I/O header file
#include<ctype.h> // Standard libray for character datatype methods such as toupper()
#include<stdlib.h> // Standard C Language Library consisting of functions such as srand() to generate random numbers
#include<string.h> // C header for predefined string methods
#include<time.h> // Header file for time related operations in a C program.

int a = 0; // Variable to depict the page index, it ensures that unless a single function is executed completely, next page should not be shown
char name[20]; // Variable to store the name of the Player playing the game
int flip = 1; // Variable for number of FLIP THE QUESTIONS lifeline left
int ques = 0; // Variable for the Question Array indexing
char option = ' '; // This global variable stores the option entered by the user in the terminal
char current[] = {'>',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}; // Array for chevron status on the money dashboard
int randomizer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32}; // Global array consisting of the question arrays index for randomising the questions
long money_now[] = {5000, 10000, 20000, 40000, 80000, 160000, 320000, 640000, 1250000, 2500000, 5000000, 10000000, 30000000, 50000000, 70000000};// Global array to store the money slabs in long int format
int random_po; //initialization of a variable that stores a randomly generated integer between 0 and 9 (inclusive)
int fifi = 1; // Variable for number of FIFTY-FIFTY lifeline left
int temp_ques = 17; // variable storing the temporary Question index for FLIP THE QUESTION lifeline

void swap (int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void randomize() 
{ 
    int n = sizeof(randomizer)/ sizeof(randomizer[0]);
    
    // Use a different seed value so that we don't get same 
    // result each time we run this program 
    srand ( time(NULL) ); 
  
    // Start from the last element and swap one by one. We don't 
    // need to run for the first element that's why i > 0 
    for (int i = n-1; i > 0; i--) 
    { 
        // Pick a random index from 0 to i 
        int j = rand() % (i+1); 
  
        // Swap arr[i] with the element at random index 
        swap(&randomizer[i], &randomizer[j]); 
    } 
} 

struct data_var // This structure acts as an template to our Questions and Answers
{
    char question[100];
    char a[35];
    char b[35];
    char c[35];
    char d[35];
    char solution;
} set[33]; //Array of 33 questions, options and answers

void Initialize() //Saving all the questions and answers in a user-defined structure type array
{
    strcpy(set[0].question, "Lake Lucerne has complicated shape with several sharp bends and four arms,it is located in");
    strcpy(set[0].a, "Egypt");
    strcpy(set[0].b, "Switzerland");
    strcpy(set[0].c, "Kenya");
    strcpy(set[0].d, "Belarus");
    set[0].solution = 'B';
    
    strcpy(set[1].question, "Who was the first woman to head public sector bank?");
    strcpy(set[1].a, "Arundhati Bhattacharya");
    strcpy(set[1].b, "Shikha Sharma");
    strcpy(set[1].c, "Chanda Kochar");
    strcpy(set[1].d, "Usha Ananthasubramanyan");
    set[1].solution = 'A';

    strcpy(set[2].question, "Where is Bose Institute?");
    strcpy(set[2].a, "Dispur");
    strcpy(set[2].b, "Kolkata");
    strcpy(set[2].c, "New Delhi");
    strcpy(set[2].d, "Mumbai");
    set[2].solution = 'B';

    strcpy(set[3].question, "When is the International Yoga Day celebrated?");
    strcpy(set[3].a, "June 21");
    strcpy(set[3].b, "March 21");
    strcpy(set[3].c, "April 22");
    strcpy(set[3].d, "May 31");
    set[3].solution = 'A';

    strcpy(set[4].question, "The motif of \'Hampi with Chariot\' is printed on the reverse of which currency note?");
    strcpy(set[4].a, "One Rupee note");
    strcpy(set[4].b, "500 Rupee note");
    strcpy(set[4].c, "50 Rupee note");
    strcpy(set[4].d, "1000 Rupee note");
    set[4].solution = 'C';

    strcpy(set[5].question, "Which of the following metals forms an amalgam with other metals?");
    strcpy(set[5].a, "Mercury (Hg)");
    strcpy(set[5].b, "Tin (Sn)");
    strcpy(set[5].c, "Lead (Pb)");
    strcpy(set[5].d, "Zinc (Zn)");
    set[5].solution = 'A';

    strcpy(set[6].question, "Which is the first country to commence competitive examination in civil services?");
    strcpy(set[6].a, "Turkmenistan");
    strcpy(set[6].b, "India");
    strcpy(set[6].c, "United Kingdom");
    strcpy(set[6].d, "China");
    set[6].solution = 'D';

    strcpy(set[7].question, "Who among the following got two Nobel prizes of which one was in Peace?");
    strcpy(set[7].a, "Albert Einstein");
    strcpy(set[7].b, "H.G. Khorana");
    strcpy(set[7].c, "Linus Pauling");
    strcpy(set[7].d, "Paul Berg");
    set[7].solution = 'C';

    strcpy(set[8].question, "The first Indian State to go wholly organic is -");
    strcpy(set[8].a, "Meghalaya");
    strcpy(set[8].b, "Sikkim");
    strcpy(set[8].c, "Manipur");
    strcpy(set[8].d, "Kerala");
    set[8].solution = 'B';

    strcpy(set[9].question, "\'Line of Blood\' is a book written by whom?");
    strcpy(set[9].a, "Diksha Basu");
    strcpy(set[9].b, "Ursula Vernon");
    strcpy(set[9].c, "Amal EI-Mohtar");
    strcpy(set[9].d, "Bairaj Khanna");
    set[9].solution = 'D';

    strcpy(set[10].question, "What is the name of Indira Gandhi's samadhi?");
    strcpy(set[10].a, "Shanti Ghat");
    strcpy(set[10].b, "Shakti Sthal");
    strcpy(set[10].c, "Shanti Van");
    strcpy(set[10].d, "Shanti Sthal");
    set[10].solution = 'B';

    strcpy(set[11].question, "Who was the first batsman to score three test century in three successive tests on debut?");
    strcpy(set[11].a, "Chris Gayle");
    strcpy(set[11].b, "Sachin Tendulkar");
    strcpy(set[11].c, "Virat Kohali");
    strcpy(set[11].d, "Mohd. Azharuddin");
    set[11].solution = 'D';

    strcpy(set[12].question, "Madhya Pradesh State was constituted on -");
    strcpy(set[12].a, "01/11/1959");
    strcpy(set[12].b, "01/09/1956");
    strcpy(set[12].c, "01/11/1956");
    strcpy(set[12].d, "01/09/1951");
    set[12].solution = 'C';

    strcpy(set[13].question, "Who introduced \'Green Army\' for environment conservation?");
    strcpy(set[13].a, "Japan");
    strcpy(set[13].b, "China");
    strcpy(set[13].c, "Australia");
    strcpy(set[13].d, "Egypt");
    set[13].solution = 'C';

    strcpy(set[14].question, "According to WHO, the most affected country by Ebola was -");
    strcpy(set[14].a, "Nigeria");
    strcpy(set[14].b, "Mali");
    strcpy(set[14].c, "Liberia");
    strcpy(set[14].d, "Senegal");
    set[14].solution = 'C';

    strcpy(set[15].question, "\'Kyoto Protocol\' is related to -");
    strcpy(set[15].a, "Air Pollution");
    strcpy(set[15].b, "Green House gases");
    strcpy(set[15].c, "Climate change");
    strcpy(set[15].d, "Water pollution");
    set[15].solution = 'C';

    strcpy(set[16].question, "Prime Ministed Narendra Modi launched \'Swachha Bharat Mission\' officially on -");
    strcpy(set[16].a, "Independance Day");
    strcpy(set[16].b, "Republic Day");
    strcpy(set[16].c, "Gandhi Jayanti");
    strcpy(set[16].d, "Environment Day");
    set[16].solution = 'C';

    strcpy(set[17].question, "\'Ozone Layer Preservation Day\' is celebrated on -");
    strcpy(set[17].a, "September 16");
    strcpy(set[17].b, "June 5");
    strcpy(set[17].c, "March 23");
    strcpy(set[17].d, "April 21");
    set[17].solution = 'A';

    strcpy(set[18].question, "Who among the following is regarded as the leader of \'Chipko Movement\'?");
    strcpy(set[18].a, "Medha Patkar");
    strcpy(set[18].b, "Baba Amte");
    strcpy(set[18].c, "Sundarlal Bahuguna");
    strcpy(set[18].d, "Kiran Bedi");
    set[18].solution = 'C';

    strcpy(set[19].question, "What is the rank of India in silk production in the world?");
    strcpy(set[19].a, "First");
    strcpy(set[19].b, "Second");
    strcpy(set[19].c, "Third");
    strcpy(set[19].d, "Fourth");
    set[19].solution = 'B';
    
    strcpy(set[20].question, "Which of the following is NOT a Permanent Member of the UN Security Council?");
    strcpy(set[20].a, "China");
    strcpy(set[20].b, "USA");
    strcpy(set[20].c, "India");
    strcpy(set[20].d, "Russia");
    set[20].solution = 'C';
    
    strcpy(set[21].question, "Doklam Standoff is a border shared between India and __________.");
    strcpy(set[21].a, "Bhutan");
    strcpy(set[21].b, "Nepal");
    strcpy(set[21].c, "Burma");
    strcpy(set[21].d, "China");
    set[21].solution = 'D';
    
    strcpy(set[22].question, "Berlin Wall which once used to separate East and West Germany, was demolished in _____.");
    strcpy(set[22].a, "1982");
    strcpy(set[22].b, "1987");
    strcpy(set[22].c, "1989");
    strcpy(set[22].d, "1990");
    set[22].solution = 'C';
    
    strcpy(set[23].question, "Which of the following countries is NOT a part of Allied Power Nations during WW2?");
    strcpy(set[23].a, "Italy");
    strcpy(set[23].b, "USSR");
    strcpy(set[23].c, "USA");
    strcpy(set[23].d, "Great Britain");
    set[23].solution = 'A';
    
    strcpy(set[24].question, "The first commercially available Computer Language with a compiler was _________.");
    strcpy(set[24].a, "COBOL");
    strcpy(set[24].b, "FORTRAN");
    strcpy(set[24].c, "C Language");
    strcpy(set[24].d, "Simula");
    set[24].solution = 'B';
    
    strcpy(set[25].question, "When did the First World War End?");
    strcpy(set[25].a, "1917");
    strcpy(set[25].b, "1918");
    strcpy(set[25].c, "1919");
    strcpy(set[25].d, "1921");
    set[25].solution = 'B';
    
    strcpy(set[26].question, "When were the first Modern Olympic Games held?");
    strcpy(set[26].a, "1876");
    strcpy(set[26].b, "1886");
    strcpy(set[26].c, "1896");
    strcpy(set[26].d, "1906");
    set[26].solution = 'C';
    
    strcpy(set[27].question, "Which Mughal Emperor propounded the concept of Din-i-Ilahi or Divine faith?");
    strcpy(set[27].a, "Emperor Shah Jahan");
    strcpy(set[27].b, "Emperor Humayun");
    strcpy(set[27].c, "Emperor Jahangir");
    strcpy(set[27].d, "Emperor Akbar");
    set[27].solution = 'D';
    
    strcpy(set[28].question, "In which of the following Yugas did the events mentioned in Ramayana took place?");
    strcpy(set[28].a, "Satya Yuga");
    strcpy(set[28].b, "Treta Yuga");
    strcpy(set[28].c, "Dwapar Yuga");
    strcpy(set[28].d, "Kali Yuga");
    set[28].solution = 'B';
    
    strcpy(set[29].question, "What is the capital of Vietnam?");
    strcpy(set[29].a, "Hanoi");
    strcpy(set[29].b, "Ho Chi Minh");
    strcpy(set[29].c, "Da Nang");
    strcpy(set[29].d, "Hue");
    set[29].solution = 'A';
    
    strcpy(set[30].question, "Who is known as the \'Father of Greek Philosophy\'?");
    strcpy(set[30].a, "Plato");
    strcpy(set[30].b, "Aristotle");
    strcpy(set[30].c, "Socrates");
    strcpy(set[30].d, "Theano");
    set[30].solution = 'C';
    
    strcpy(set[31].question, "Largest Country in the world (area-wise) is :");
    strcpy(set[31].a, "Russia");
    strcpy(set[31].b, "Canada");
    strcpy(set[31].c, "Brazil");
    strcpy(set[31].d, "India");
    set[31].solution = 'A';
    
    strcpy(set[32].question, "Who is the President of Syria?");
    strcpy(set[32].a, "Hafez Al-Assad");
    strcpy(set[32].b, "Basan Al-Assad");
    strcpy(set[32].c, "Bashar Al-Assad");
    strcpy(set[32].d, "Majd Al-Assad");
    set[32].solution = 'C';
}

void start() // This function is basically our starting screen when the program runs
{
    system("clear");
    randomize(); // Calling randomize to randomize the serial number array to display different question everytime
    printf("\n\n");
    printf("\t\t\t\t\t\t\t   ██╗  ██╗   ██████╗     ██████╗TM\n");
    printf("\t\t\t\t\t\t\t   ██║ ██╔╝   ██╔══██╗   ██╔════╝\n");
    printf("\t\t\t\t\t\t\t   █████╔╝    ██████╔╝   ██║     \n");
    printf("\t\t\t\t\t\t\t   ██╔═██╗    ██╔══██╗   ██║     \n");
    printf("\t\t\t\t\t\t\t   ██║  ██╗██╗██████╔╝██╗╚██████╗\n");
    printf("\t\t\t\t\t\t\t   ╚═╝  ╚═╝╚═╝╚═════╝ ╚═╝ ╚═════╝\n");
    printf("\t\t\t\t\t\t\t       Kaun Banega Crorepati\n");
    printf("\t\t\t\t\t\t\t      ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
    printf("\n\n");
    printf("\t\t\t\b\bWelcome to Kaun Banega Crorepati(K.B.C)! A game show where you can win 7 crore rupees by answering simple\n");
    printf("\t\t\t\b\bGeneral Knowledge and Current Affairs Questions. So are you ready to Win?\n\n\t\t\t\b\bNOTE: This game is best enjoyed in FULL-SCREEN mode (If you are not already, then RESTART).\n");
    printf("\t\t\t\b\bIf you are in the linux terminal and the characters are overflowing, please zoom out or make the font size small.\n\n\n");
    printf("\t\t\t\b\bEnter Y to CONTINUE or N (or any other key) to QUIT. YOUR CHOICE -> ");
    char ch = getchar();
    if(toupper(ch) == 'Y') // If the user enters Y, he will proceed forward otherwise he can quit from the home screen itself
    {
        a=1;
    }
    else
    exit(0);
}

void name_data() // This function is basically the second screen just after the first screen facilitating the user to type his/her name
{
    system("clear"); // clearing the screen first, so that the previous screen is cleared
    printf("\t\t\t\t\t\t\tEnter name: ");
    scanf("%s", name);
    printf("\n\n\t\t\t\t\t\t\t\b\b%s, welcome to KBC.\n\n", name);
    a=2; // This variable is updated to 2 breaking the while loop in the main function and moving to next screen
}

void rules() // This function shows the Rules and Instruction just before the questions starts appearing on the screen
{
    printf("\t\t\t\t\tSo here are some rules and tips for the game for you.\n\n");
    printf("\t\t\t\t\t\t\tRULES & INSTRUCTIONS\n");
    printf("\t\t\t\t\t\t\t\b______________________\n\n");
    printf("\t1.) In order to WIN THE FINAL PRIZE of Rs.7,00,00,000, you need to answer ALL the 15 questions CORRECTLY.\n");
    printf("\t2.) The time you answer a question INCORRECTLY (Meaning choosing the wrong option), your game will be OVER.\n");
    printf("\t3.) There are 4 CHECKPOINTS in the game (indicated by [C*] sign in the money dashboard (present on the left side) of the game). The\n");
    printf("\t     checkpoint questions are Question 4 (40,000), Question 8 (6,40,000), Question 12 (1 Crore) and Question 15 (7 Crore).\n");
    printf("\t4.) Each of these 4 CHECKPOINTS (which is mentioned in the last point), when reached, ensure that amount to be won even if you are \n");
    printf("\t    not able to reach the next checkpoint.\n");
    printf("\t5.) Your CURRENT POSITION in the money dashboard is indicated by the CHEVRON(>>) symbol on the LEFT SIDE of the slab.\n");
    printf("\t6.) You get TWO LIFELINES in the game, namely FIFTY-FIFTY and FLIP THE QUESTON. Both of these are explained in the next two points.\n");
    printf("\t7.) FIFTY-FIFTY, as the name suggests, ERASES TWO WRONG OPTIONS (RANDOMLY) from the screen. To use FIFTY-FIFTY, ENTER F on the console.\n");
    printf("\t8.) FLIP THE QUESTION can be used when YOU DONT KNOW THE ANSWER TO THE QUESTION ON THE SCREEN, you can use this oprtion to change \n");
    printf("\t    it for an ALTERNATIVE QUESTION. ENTER P to use.\n");
    printf("\t9.) You can QUIT the game whenever you want, by ENTERING Q in the console. When you quit, the amount that you will take with you is \n");
    printf("\t    the amount mentioned in the LAST CHECKPOINT.\n");
    printf("\t10.) Also remember, if you ENTER any KEY other than the keys mentioned in the POINTS ABOVE (For example W,K,J...), there will be NO EFFECT.\n");
    printf("\t11.) You can ENTER ANY OPTION in either of the two cases, that is both lowercase and UPPERCASE. BOTH WILL BE EVALUATED AS SAME.\n");
    printf("\t11.) Though this point is not any instruction, we just wanted to tell you that this is NOT a STATIC GAME. By STATIC GAME, we mean that\n");
    printf("\t     a game that displays the same question at a particular question number. In our game, though our question bank is limited (40 Ques), but\n");
    printf("\t     BUT everytime you start the game, 15 Random Questions will be chosen from our question bank and presented on your screen. This concept \n");
    printf("\t     is also applied in the LIFELINE part too, this makes our game unique. For more information please refer to the README.txt file provided.\n");
    printf("\t12.) If you ENTER multiple charcters as input in the terminal, ONLY THE FIRST CHARACTER of the string will be taken as the input.\n");
    printf("\t     BEST OF LUCK!!!!\n\n");
    printf("\t\t\t\t\tPress ANY KEY followed by ENTER to Continue.... ");
    char ch = getchar();
    getchar();
    a=3;
}

long check_money() // This function returns the money which the user can take home with him, at any particular moment in the game
{
    long pass; // This function returns value according to the slabs mentioned below
    if(ques >= 4 && ques <= 7)
    pass = money_now[3];
    else if(ques >= 8 && ques <= 11)
    pass = money_now[7];
    else if(ques >= 12 && ques <= 14)
    pass = money_now[11];
    else
    pass = 0;
    
    return pass;
}

void questionnaire() // This function displays the question on the screen by looping technique
{
    int ques_Quest; // This variable is the index of the question displayed on the screen
    if(flip == -1)
    {
        ques_Quest = temp_ques;
    }
    else
    {
        ques_Quest = ques;
    }
    system("clear"); // Clers the screen for next questions
    Initialize();
    int l;
    char ch = ' ';
    char quest[100] ; // Local Variable to display the question on the screen by copying the value of set[n].question from the stucture
    char opA[35] ; // Local Variable to display option A on the screen by copying the value of set[n].a from the stucture
    char opB[35] ; // Local Variable to display option B on the screen by copying the value of set[n].b from the stucture
    char opC[35] ; // Local Variable to display option C on the screen by copying the value of set[n].c from the stucture
    char opD[35] ; // Local Variable to display option D on the screen by copying the value of set[n].d from the stucture
    if(option == 'F' && fifi == -1)
    {
        fifi = 0;
        srand(time(NULL)); // generates randon integer by taking seed as the time
        int random_ten = rand()%10; // Generates a random number between 0 and 9
        // printf("%d", random_ten); /// Uncomment this line to print the random number on the top of the screen when fifty fifty is opted
        strcpy(quest, set[randomizer[ques_Quest]].question); // Copies the value of set[randomizer[ques_Quest]].question to the variable quest
        /*                  FIFTY-FIFTY LOGIC
        This is the logic of eliminating two wrong options (RANDOMLY) from the the screen when fifty fifty lifeline is chosen
        >Firstly, we generate a random integer between 0 and 9 (stored in the variable random_ten).
        >Next step, we make if else ladder for slabs corresponding to all the four possible options.
        >Let's say that the solution to a particular question is 'A', then opA will not be eliminated (as it is the right option).
        >So, keeping that in mind, opA will be copied as usual from the structure containing the option.
        >This will leave us with opB, opC and opD. Any two of which need to be eliminated and the one left should be filled as usual,like opA.
        >We hence make some more slabs inside if statement corresponding to the value of the variable random_ten.
        >Having probability of 0.333.. of falling in any particular slab, it makes it evenly possible for any two wrong options to disappear randomly, without any bias.
        >Same procedure is done for all the four options.
        */
        if(set[randomizer[ques_Quest]].solution == 'A') // I will be explaining the logic only for this slab, i.e. if option is 'A'. It is similar for other opt(s) too.
        {
            strcpy(opA, set[randomizer[ques_Quest]].a); // As correct answer is 'A', copy the value of option A as it is to opA.
            
                if(random_ten>=0 && random_ten<3) // If the random integer lies b/w 0 to 3, this slab will be activated.
                {
                    strcpy(opB, ""); // Here B and C will be emptied but D will be copied as it is
                    strcpy(opC, "");
                    strcpy(opD, set[randomizer[ques_Quest]].d);
                }
                if(random_ten>=3 && random_ten<6)
                {
                    strcpy(opB, ""); // Similarly, here B and D will be emptied and C will be copied to opC as it is
                    strcpy(opC, set[randomizer[ques_Quest]].c);
                    strcpy(opD, "");
                }
                if(random_ten>=6 && random_ten<=9)
                {
                    strcpy(opB, set[randomizer[ques_Quest]].b); // And if the value of random_ten lies between 6 and 9, then C and D will be emptied.
                    strcpy(opC, "");
                    strcpy(opD, "");
                }
        }
        
        else if(set[randomizer[ques_Quest]].solution == 'B')
        {
            strcpy(opB, set[randomizer[ques_Quest]].b);
            
                if(random_ten>=0 && random_ten<3)
                {
                    strcpy(opA, "");
                    strcpy(opC, "");
                    strcpy(opD, set[randomizer[ques_Quest]].d);
                }
                if(random_ten>=3 && random_ten<6)
                {
                    strcpy(opA, "");
                    strcpy(opC, set[randomizer[ques_Quest]].c);
                    strcpy(opD, "");
                }
                if(random_ten>=6 && random_ten<=9)
                {
                    strcpy(opA, set[randomizer[ques_Quest]].a);
                    strcpy(opC, "");
                    strcpy(opD, "");
                }
        }
        
        else if(set[randomizer[ques_Quest]].solution == 'C')
        {
            strcpy(opC, set[randomizer[ques_Quest]].c);
            
                if(random_ten>=0 && random_ten<3)
                {
                    strcpy(opB, "");
                    strcpy(opA, "");
                    strcpy(opD, set[randomizer[ques_Quest]].d);
                }
                if(random_ten>=3 && random_ten<6)
                {
                    strcpy(opB, "");
                    strcpy(opA, set[randomizer[ques_Quest]].a);
                    strcpy(opD, "");
                }
                if(random_ten>=6 && random_ten<=9)
                {
                    strcpy(opB, set[randomizer[ques_Quest]].b);
                    strcpy(opA, "");
                    strcpy(opD, "");
                }
        }
        
        else if(set[randomizer[ques_Quest]].solution == 'D')
        {
            strcpy(opD, set[randomizer[ques_Quest]].d);
            
                if(random_ten>=0 && random_ten<3)
                {
                    strcpy(opB, "");
                    strcpy(opC, "");
                    strcpy(opA, set[randomizer[ques_Quest]].a);
                }
                if(random_ten>=3 && random_ten<6)
                {
                    strcpy(opB, "");
                    strcpy(opC, set[randomizer[ques_Quest]].c);
                    strcpy(opA, "");
                }
                if(random_ten>=6 && random_ten<=9)
                {
                    strcpy(opB, set[randomizer[ques_Quest]].b);
                    strcpy(opC, "");
                    strcpy(opA, "");
                }
        }
        
    }
    else //This is executed when fifty fifty option is not selected
    {
        strcpy(quest, set[randomizer[ques_Quest]].question);
        strcpy(opA, set[randomizer[ques_Quest]].a);
        strcpy(opB, set[randomizer[ques_Quest]].b);
        strcpy(opC, set[randomizer[ques_Quest]].c);
        strcpy(opD, set[randomizer[ques_Quest]].d);
    }
    l = strlen(quest); // This gives the length of the string containing question
    if(ques>=9)
    { // This case is for the time when Question is less than or equal to 9, as they are single digit nos. and require one character space
        for(int i=1; i<(91-l); i++)
        {
           strncat(quest, &ch, 1);
        }
    }
    else
    { // This case is for the time when Question is greater than 9 (double digit), as they are two digit numbers and require two character space
        for(int i=1; i<(92-l); i++)
        {
           strncat(quest, &ch, 1); // Here we concatenate ' ' (space) character after the the string to fit the question slab properly.
        }
    }
    l = strlen(opA);
    for(int i=1; i<(28-l); i++)
    {
       strncat(opA, &ch, 1); // Here we concatenate ' ' (space) character after the the string to fit the question slab properly.
    }
    l = strlen(opB);
    for(int i=1; i<(28-l); i++)
    {
       strncat(opB, &ch, 1); // Here we concatenate ' ' (space) character after the the string to fit the question slab properly.
    }
    l = strlen(opC);
    for(int i=1; i<(28-l); i++)
    {
       strncat(opC, &ch, 1); // Here we concatenate ' ' (space) character after the the string to fit the question slab properly.
    }
    l = strlen(opD);
    for(int i=1; i<(28-l); i++)
    {
       strncat(opD, &ch, 1); // Here we concatenate ' ' (space) character after the the string to fit the question slab properly.
    }
    
    printf(" \n\n");
    printf(" \t\t\t\t\t\t\t\t'||'  |'  '||''|.     ..|'''.| \n");
    printf(" \t\t\t\t\t\t\t\t || .'     ||   ||  .|'     '  \n");
    printf(" \t\t\t\t\t\t\t\t ||'|.     ||'''|.  ||         \n");
    printf(" \t\t\t\t\t\t\t\t ||  ||    ||    || '|.      . \n");
    printf(" \t\t\t\t\t\t\t\t.||.  ||. .||...|'   ''|....'  \n");
    printf(" \n");
    printf(" \t\t\t\t\t    %s, Question for Rupees %lu is now on your computer Screen:\n", name, money_now[ques]);
    printf("   _______________\n");
    printf("%c%c│    7 CRORE    │[C*]\t\t  /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\ \n", current[14], current[14]);
    printf("%c%c│    5 CRORE    │    \t\t-( Q.%d> %s)-\n",current[13],current[13],(ques+1),quest);
    printf("%c%c│    3 CRORE    │    \t\t  \\_______________________________________________________________________________________________/\n",current[12], current[12]);
    printf("%c%c│    1 CRORE    │[C*]\n",current[11], current[11]);
    printf("%c%c│  50,00,000    │\n",current[10], current[10]);
    printf("%c%c│  25,00,000    │\n",current[9], current[9]);
    printf("%c%c│  12,50,000    │    \t\t  /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\                                 /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\ \n", current[8], current[8]);
    printf("%c%c│   6,40,000    │[C*]\t\t-( A.> %s)-------------------------------( B.> %s)-\n",current[7],current[7],opA,opB);
    printf("%c%c│   3,20,000    │    \t\t  \\______________________________/                                 \\______________________________/\n", current[6], current[6]);
    printf("%c%c│   1,60,000    │\n",current[5], current[5]);
    printf("%c%c│     80,000    │    \t\t  /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\                                 /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\ \n", current[4], current[4]);
    printf("%c%c│     40,000    │[C*]\t\t-( C.> %s)-------------------------------( D.> %s)-\n",current[3],current[3],opC,opD);
    printf("%c%c│     20,000    │    \t\t  \\______________________________/                                 \\______________________________/\n", current[2], current[2]);
    printf("%c%c│     10,000    │\n",current[1], current[1]);
    printf("%c%c│      5,000    │       ENTER A,B,C,D to select options, F for FIFTY-FIFTY (%d left) and P to FLIP THE QUESTION (%d left).\n", current[0], current[0], fifi, (flip != 1? 0:1));
    printf("   ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾        ENTER Q if you want to QUIT. If you QUIT now, you can take INR %lu with you.\n\n", check_money());
    printf(" \t\t\t  ENTER your CHOICE : ");
    char str[25];
    scanf("%s", str);
    option = str[0];
    
    a = 4; // a is updated for breaking the loop in the main function.
}

void checkpoint() // basic void function to show stats after reaching each checkpoint
{
    system("clear"); // screen is cleared
    int Ch_No = (ques == 3) ? 1 : ((ques == 7) ? 2 : 3); // ternary operator to decide the data of the variable (Ch_No => Checkpoint Number)
    int Nex_Ch = (ques == 3) ? 8 : ((ques == 7) ? 12 : 15); // same as above (Nex_Ch => Next Checkpoint)
    int af_ch = (ques == 3) ? 4 : ((ques == 7) ? 4 : 3); // same as above (af_ch => Next Checkpoint after how many questions)
    long conf_amt = (ques == 3) ? 40000 : ((ques == 7) ? 640000 : 10000000); // confirm minimum amount that the player will win after reaching the checkpoint
    printf("\n\n\n");
    printf("\t\t\t\t\t   ██████  ██████  ███    ██  ██████  ██████   █████  ████████ ███████ ██\n");
    printf("\t\t\t\t\t  ██      ██    ██ ████   ██ ██       ██   ██ ██   ██    ██    ██      ██\n");
    printf("\t\t\t\t\t  ██      ██    ██ ██ ██  ██ ██   ███ ██████  ███████    ██    ███████ ██\n");
    printf("\t\t\t\t\t  ██      ██    ██ ██  ██ ██ ██    ██ ██   ██ ██   ██    ██         ██   \n");
    printf("\t\t\t\t\t   ██████  ██████  ██   ████  ██████  ██   ██ ██   ██    ██    ███████ ██\n");
    printf("\t\t\t\t\t    __________________________________________________________________\n");
    printf("\t\t\t\t\t   /_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/_____/\n\n\n");
    printf("\t\t\t\t\t\t\t\t   CHECKPOINT ACHIEVED\n\n\n");
    printf("\t\t\t\t\t  CHECKPOINT NUMBER : %d\n\n", Ch_No);
    printf("\t\t\t\t\t  CONFIRMED AMOUNT TO BE WON : INR %lu\n\n", conf_amt);
    printf("\t\t\t\t\t  NEXT CHECKPOINT AT : Ques %d\n\n", Nex_Ch);
    printf("\t\t\t\t\t  NEXT CHECKPOINT AFTER IS AFTER %d QUESTIONS\n\n\n", af_ch);
    printf("\t\t\t\t\t  Press ENTER to CONTINUE THE GAME");
    char ch = getchar();
}

void won() // function called when player answers all the questions correctly and wins 7 crore amount
{
    system("clear");
    printf("\n\n\n");
    printf("\t\t\t\t\t  ██    ██  ██████  ██    ██     ██     ██  ██████  ███    ██ ██\n"); 
    printf("\t\t\t\t\t   ██  ██  ██    ██ ██    ██     ██     ██ ██    ██ ████   ██ ██\n"); 
    printf("\t\t\t\t\t    ████   ██    ██ ██    ██     ██  █  ██ ██    ██ ██ ██  ██ ██\n"); 
    printf("\t\t\t\t\t     ██    ██    ██ ██    ██     ██ ███ ██ ██    ██ ██  ██ ██  \n");
    printf("\t\t\t\t\t     ██     ██████   ██████       ███ ███   ██████  ██   ████ ██\n\n\n"); 
    printf("\t\t\t\t\t  ALL OF THE 7 CRORE PRIZE MONEY NOW BELONGS TO YOU!!\n");
    printf("\t\t\t\t\t  %s, YOU ARE NOW A CROREPATI!!\n\n\n\n", name);
    printf("\t\t\t\t\t  PRESS ENTER / ANY KEY FOLLOWED BY ENTER TO QUIT ");
    char ch = getchar();
    exit(0);
}


void game_over() // Function called when player gives any wrong answer and game gets over or when he quits manually
{
    if(flip == -1){flip =0;}
    if(fifi == -1){fifi =0;}
    system("clear");
    printf("\n\n\n");
    printf("\t\t\t\t\t   ██████   █████  ███    ███ ███████      ██████  ██    ██ ███████ ██████  \n");
    printf("\t\t\t\t\t  ██       ██   ██ ████  ████ ██          ██    ██ ██    ██ ██      ██   ██ \n");
    printf("\t\t\t\t\t  ██   ███ ███████ ██ ████ ██ █████       ██    ██ ██    ██ █████   ██████  \n");
    printf("\t\t\t\t\t  ██    ██ ██   ██ ██  ██  ██ ██          ██    ██  ██  ██  ██      ██   ██ \n");
    printf("\t\t\t\t\t   ██████  ██   ██ ██      ██ ███████      ██████    ████   ███████ ██   ██ \n\n\n");
    printf("\t\t\t\t\t\t\t\t\t GAME STATS\n\n");
    printf("\t\t\t\t\t  FINAL AMOUNT WON (WHICH YOU CAN TAKE HOME): INR %lu\n", check_money());
    printf("\t\t\t\t\t  LAST QUESTION REACHED: %d\n", (ques+1));
    printf("\t\t\t\t\t  AMOUNT IN LAST QUESTION: INR %lu\n", money_now[ques]);
    printf("\t\t\t\t\t  LIFELINE(S) LEFT: %d FIFTY-FIFTY AND %d FLIP THE QUESTION\n\n\n\n", fifi, flip);
    printf("\t\t\t\t\t  PRESS ENTER TO QUIT ");
    char ch = getchar();
    exit(0);
}

void sorry() // This function is called when user is not able to reach even the first checkpoints and wins no money
{
    system("clear");
    printf("\n\n\n");
    printf("\t\t\t\t\t  ███████  ██████  ██████  ██████  ██    ██ ██ \n");
    printf("\t\t\t\t\t  ██      ██    ██ ██   ██ ██   ██  ██  ██  ██ \n");
    printf("\t\t\t\t\t  ███████ ██    ██ ██████  ██████    ████   ██ \n");
    printf("\t\t\t\t\t       ██ ██    ██ ██   ██ ██   ██    ██       \n");
    printf("\t\t\t\t\t  ███████  ██████  ██   ██ ██   ██    ██    ██ \n\n\n");
    printf("\t\t\t\t\t\t\t    ██\n");
    printf("\t\t\t\t\t\t\t██ ██ \n");
    printf("\t\t\t\t\t\t\t   ██ \n");
    printf("\t\t\t\t\t\t\t██ ██ \n");
    printf("\t\t\t\t\t\t\t    ██\n\n\n");
    printf("\t\t\t\t%s, You didn't won any money this time, bad luck maybe. We all know that you deserve better.\n",name);
    printf("\t\t\t\tTry again next time. Best of LUCK!!\n");
    printf("\t\t\t\tPRESS any KEY followed by ENTER OR only the ENTER key to QUIT ");
    char ch = getchar();
    exit(0);
}

int main() // The main function which controls the working of the program from start to finish
{
    while(a!=1){start();} // This shows that the start() function is called at the beginning of the program. the program will not proceed forwards until a becomes 1.
    while(a!=2){name_data();} // After the start() function, name_data() function is called to store the name of the user in a global variable.
    while(a!=3){rules();} // Next comes the rule pagge for all the important rules and instructions
    while(a!=4){ // This loop is responsible for displaying questions until player answers it correctly
        while(ques!=15){
            questionnaire(); // calling the questionnaire() function after every loop
            option = toupper(option); // converting the option enterd by the user to UPPERCASE for convenience. 
            if(option == 'A' ||option == 'B' ||option == 'C' ||option == 'D') // Answer is checked that the user has entered it right or not.
            {
                if(set[randomizer[(flip == -1?temp_ques : ques)]].solution == option){ // For correct answer
                    printf("\t\t\t  CORRECT ANSWER!!!! (MONEY WON: %lu)\n\t\t\t  Press ENTER to CONTINUE..", money_now[ques]);
                    char ch = getchar();
                    getchar();
                    if(ques == 14) // if last question is answered correctly by the player, won() function is called before closing the program.
                    {
                        won();
                    }
                    if(ques == 3 || ques == 7 || ques == 11) // If checkpoint is reached, checkpoint function is called
                    {
                        checkpoint();
                    }
                }
                else // If user enters wrong answer, the game gets over 
                {
                    printf("\t\t\t  WRONG ANSWER (Correct Option: %c)\n\t\t\t  Press ENTER to CONTINUE..", set[randomizer[ques]].solution);
                    char ch = getchar();
                    getchar();
                    if(check_money() == 0) // if no money is won by the user, then sorry() function is called
                    {
                        sorry();
                    }
                    else // otherwise the usual game_over() function is called
                    {
                        game_over();
                    }
                }
                if(flip == -1) // the -1 state of flip variable indicates that it is used by the user and cannot be used again but option variable is not 'P'
                flip = 0; // it simply assigns a value 0 to flip when flip = -1
            }
            else if(option == 'P' && flip == 1) // This slab basically activated when option chosen by the user is FLIP THE QUES. and it is available too. 
            {
                flip = -1;
                continue; // Continue to skip the current iteration. this makes sure that the value of ques is not incremented, nor does the chevron moves up.
            }
            else if(option == 'F' && fifi == 1) // This slab is activated when user wants to use his fifty fifty lifeline.
            {
                fifi = -1;
                continue; // similar function as in the above mentioned slab
            }
            else if(option == 'Q') // This slab is activated when user wants to manually quit the game.
            {
                char ch;
                printf("\t\t\t  Are you sure? [Y/N] "); // This is for the confirmation that whether the user really wants to quit or it was by mistake
                scanf(" %c", &ch);
                ch = toupper(ch);
                if(ch == 'Y')
                {game_over();}
                else
                {continue;}
            }
            else // Any other key will have no effect on the screen
            {
                continue;
            }
            if(flip == -1) {flip = 0;}
            current[ques+1]='>'; // for monitoring the Money Slab in the game
            ques++; // Next Question
        }
    }
}













