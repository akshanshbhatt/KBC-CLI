# KBC-Game-in-C
A basic C-lang CLI game which I made during my freshman year at college. 

**********README**********

############################################################

README for assignment submitted by 2019B5PS0754P
Practical section number: P09
Assignment question attempted: 1 (KBC GAME)

############################################################

TEAM:
1. 2019B5PS0754P  Akshansh Bhatt
2. 2019B3PS0160P  Saksham Jain
3. 2019A2PS0687P  Hitanshu Choudhary

############################################################

ACKNOWLEDGEMENT:-
This complete assignment is made possible by the efforts and contribution of everyone in the team. It is ensured that this project is our own work and that no part of this program is plagiarised in any way. Although our project is not licensed, it is recommended that it should not be used without citing all the authors of the same.
This code is well documented and every part is explained properly using comments.

############################################################

SALIENT FEATURES AND WORK DONE ON EACH POINT:-

WE HAVE TRIED TO IMPROVISE ON EVERY POSSIBLE PART OF THE PROGRAM, WHICH DIFFERENTIATES OURS FROM ANY OTHER TEAM.

***POINTS THAT SET OUR PROGRAM APART:-

1. Random questions are picked one by one every time from a set of 33 questions.
2. Another question is randomly selected during FLIP THE QUESTION lifeline.
3. Any two options are erased randomly when using the FIFTY-FIFTY lifeline.
4. We have included specific "message pages" for when you win, lose, reach a checkpoint, and quit.
5. All the questions are saved in a structure-type array.
6. No question will be repeated in the same program.
7. We have made our program as modular as possible, with a total 13 functions in the source file.

***QUESTION ATTEMPTED WITH WORK ON EVERY POINT:-

We have attempted the First Question of the Assignment which stated to build a KBC game. In order to show that we have worked on every point that was stated in the question, here are the points with the work which we did on each of them.   

1. First of all, primary information, such as the total number of questions, prize money with respect to each question, available life lines and intermediate question levels (described in point no. 4 below) should be displayed on the screen, asking the user to press any key to start the game.

*Our Work -> Corresponding to point 1, We not only did create the Welcome Page (which asks the user to PRESS and ENTER ‘Y’ KEY to proceed further) but also created a DETAILED RULES PAGE (which shows all the rules before starting the game).

2. When notified by the user, the game should start by displaying one question at a time along with its four options on the screen, prompting the user to select the correct option. 

*Our Work -> After the RULES PAGE, as soon as the user PRESSES and ENTERS any key on the keyboard, the questions start to appear on the screen, one at a time. Also there are four options as asked in the question.

3. When the user selects his/her option, the program should show a message whether the selected option is correct or wrong. 

*Our Work -> When the user selects his/her option, apart from showing whether the option is correct or not- If the option is correct, the amount won is shown on the screen and if it is wrong then the correct option is displayed before showing the STATS of  the final amount that the user has won and questions he answered correctly and finally exiting the program. Also, on Checkpoints, special messages as displayed on the console screen regarding the confirmed amount that the user will win and also a sorry message if the user wins nothing. If the User wins the game, YOU WON! message is also displayed. We have also added the provision to QUIT the game in between like the actual KBC game. If the user finds the question difficult, he/she can quit anytime with the amount won in the last checkpoint.

4. If the selected option is correct, the corresponding prize money should be displayed. Otherwise, the prize money counter should be reduced to zero or to the intermediate level (e.g., after question number 3, 8 and 12, as set by you), and displayed on the screen. 

*Our Work -> We have done exactly like this. Our checkpoints are at Questions 4, 8, 12 and 15 (Mentioning 15 is redundant as it is the last Question so it is obvious). So, whenever the user answers the question wrong, he/she will get the amount equivalent to the amount mentioned in the last reached CHECKPOINT. 

5. The user can opt for two life lines, such as “50-50”, upon selection of which two wrong options should be removed from the screen, or “flip the question” that should replace the entire question with a new one on the screen. These life lines can be availed by the user only once (even at the same time as well). Therefore, the program should take care of this provision. 

*Our Work -> Our FIFTY-FIFTY is designed especially in a way that it eliminates the wrong answers RANDOMLY. If you will go through the documentation of our code, you will find out how cleverly we have used the srand() and rand() functions of the stdlib.h header to implement this. Everytime, random wrong options will be eliminated from the screen even if you use it in the same question in the next game. The two wrong options removed will be different from the last time for that particular question (GO TRY!).
Coming to our FLIP THE QUESTION lifeline, it displays a DIFFERENT and RANDOM question every time when used. We have also used the rand() and srand() functions in this lifeline. 
As mentioned in this point, we have also tested both the lifelines to work AT THE SAME TIME and it has worked properly every time.
The Questions are also shuffled every time the user starts the game. We have a collection of 33 Questions from which 15 questions are randomly selected before each game.

6. The maximum number of questions a user can play should not exceed 15. 

*Our Work  -> Our game contains 15 questions only!

############################################################

DESCRIPTION OF HOW TO RUN THE CODE AND OBSERVE THE OUTPUT:-

1. The exe is called 2019B5PS0754P_P09.exe. It is an emulated version of the popular quiz show, Kaun Banega Crorepati (popularly known as KBC). This program is basically a game with basically all the features of the actual quiz show.

2. There are no input files; just the executable file which can be opened in the terminal by typing and entering the command ./2019B5PS0754P_P09.exe in the directory where the zip file is extracted. ALSO, WE ENSURE THAT THE USER WILL NOT REQUIRE TO INSTALL ANY OTHER THIRD PARTY PACKAGE/HEADER/FRAMEWORK TO RUN OUR EXE.

3. This point is redundant if the terminal setting is default, otherwise the character encoding in the terminal should be UTF-8 (which is the default encoding). Please ignore this point if you haven't changed it from the default encoding.

4. When you run the exe, there will be a KBC logo on the screen along with some basic instructions to ensure that the user is not facing bad experience due to overflowing or badly rendered text on the screen. We also ask you to read the NOTE bullet provided just after these points. After these instructions, there will be an input field requiring the user to ENTER the character 'Y' in order to continue further. If the user ENTERS any other character, the game will finish and he/she will be prompted out of the exe.

5. The next screen will ask for the user's name. When you ENTER your name, a detailed rules and tip page will open.

6. After the rules page, the game will start, the first question will prompt on user's screen along with a marker pointing at the 5000 rupees mark and some basic instruction for using the lifelines and quitting the game.

7. Note that in every game, the order of the question is shuffled (We have a list of 33 Different Questions, which are shuffled and chosen randomly for each game). This gives the user a different and diverse experience rather that having the same order which can make the game monotonus and boring.

8. If the user reaches a checkpoint, he/she is prompted with an information page telling him/her about his winnings, lifelines left and number of questions left to reach the next checkpoint.

9. If the user ENTERS the wrong option, screen is prompted with a WRONG ANSWER message and the correct option is also displayed along with it. After pressing ENTER on this screen, if the user has won something, that amount is shown along with some other information and if he hasn't won anything, a SORRY messgae is shown and the game gets over in both of these cases. 

10. If the user ENTERS 'P' at any question, FLIP THE QUESTION lifeline is activated and if the user ENTERS 'F' at any question, FIFTY-FIFTY lifeline is activated (More information about these lifelines and their working are discussed in the above sections of the README.txt file and also in the code's documentation).

11. Finally, if the user answers all the 15 questions correctly, YOU WON message is prompted on the screen before exiting.

***NOTE:-
We have prepared this code to be comfortable while running in the terminal, use of any IDE may affect the final look on the screen. If the characters are not aligned properly, adjust the font-size of the terminal and RESTART. To change the font size-

>>If you are using the CLion Terminal -
 File -> Settings -> Editor -> Colors & Fonts -> Console Font.
 	Apply the size you want, quit the Terminal and re-open it.

>>If you are using the Linux Terminal (any Distro even Ubuntu)-
	Open Terminal -> Right Click -> Profiles -> Profile Preferences -> General Tab -> Font.

>>If you are using Ubuntu Terminal (shortcut)-
	Open Terminal -> Click on the Button having three parallel lines near the find Button on the top ribbon of the terminal -> Magnifying option

>>If you are using CodeBlocks IDE-
	Settings -> Environment -> View -> Message logs' font size"

>>If you are using Windows Command Prompt/PowerShell-
	Open the terminal -> Right Click on the Title Bar of the terminal window -> Properties -> Font section -> Font size
