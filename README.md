# KBC Game in C
A basic C-lang CLI quiz game (Indian version of 'Who wants to be a millionaire?' known as KBC) which I made during my freshman year at college as the submission for our assignment. This documentation of the code was my very first attempt so there might me naïve mistakes in it. This program can be executed in the command line without any need of additional libraries/files. Feel free to fork it and give it your own touch.

## **README**

README for assignment submitted by 2019B5PS0754P
Practical section number: P09
Assignment question attempted: 1 (KBC GAME)

### TEAM
1. 2019B5PS0754P  Akshansh Bhatt
2. 2019B3PS0160P  Saksham Jain
3. 2019A2PS0687P  Hitanshu Choudhary

>#### ACKNOWLEDGEMENT:
>This complete assignment is made possible by the efforts and contribution of everyone in the team. It is ensured that this project is our own work and that no part of this program is plagiarized in any way. Although our project is not licensed, it is recommended that it should not be used without citing all the authors of the same.
This code is well documented and every part is explained properly using comments.

### POINTS THAT SET OUR PROGRAM APART

1. Random questions are picked one by one every time from a set of 33 questions.
2. Another question is randomly selected during FLIP THE QUESTION lifeline.
3. Any two options are erased randomly when using the FIFTY-FIFTY lifeline.
4. We have included specific "message pages" for when you win, lose, reach a checkpoint, and quit.
5. All the questions are saved in a structure-type array.
6. No question will be repeated in the same program.
7. We have made our program as modular as possible, with a total 13 functions in the source file.

### DESCRIPTION OF HOW TO RUN THE CODE AND OBSERVE THE OUTPUT

1. The exe is called 2019B5PS0754P_P09.exe. It is an emulated version of the popular quiz show, Kaun Banega Crorepati (popularly known as KBC). This program is basically a game with basically all the features of the actual quiz show.

2. There are no input files; just the executable file which can be opened in the terminal by typing and entering the command ./2019B5PS0754P_P09.exe in the directory where the zip file is extracted. ALSO, WE ENSURE THAT THE USER WILL NOT REQUIRE TO INSTALL ANY OTHER THIRD PARTY PACKAGE/HEADER/FRAMEWORK TO RUN OUR EXE.

3. This point is redundant if the terminal setting is default, otherwise the character encoding in the terminal should be UTF-8 (which is the default encoding). Please ignore this point if you haven't changed it from the default encoding.

4. When you run the exe, there will be a KBC logo on the screen along with some basic instructions to ensure that the user is not facing bad experience due to overflowing or badly rendered text on the screen. We also ask you to read the NOTE bullet provided just after these points. After these instructions, there will be an input field requiring the user to ENTER the character 'Y' in order to continue further. If the user ENTERS any other character, the game will finish and he/she will be prompted out of the exe.

5. The next screen will ask for the user's name. When you ENTER your name, a detailed rules and tip page will open.

6. After the rules page, the game will start, the first question will prompt on user's screen along with a marker pointing at the 5000 rupees mark and some basic instruction for using the lifelines and quitting the game.

7. Note that in every game, the order of the question is shuffled (We have a list of 33 Different Questions, which are shuffled and chosen randomly for each game). This gives the user a different and diverse experience rather that having the same order which can make the game monotonous and boring.

8. If the user reaches a checkpoint, he/she is prompted with an information page telling him/her about his winnings, lifelines left and number of questions left to reach the next checkpoint.

9. If the user ENTERS the wrong option, screen is prompted with a WRONG ANSWER message and the correct option is also displayed along with it. After pressing ENTER on this screen, if the user has won something, that amount is shown along with some other information and if he hasn't won anything, a SORRY message is shown and the game gets over in both of these cases. 

10. If the user ENTERS 'P' at any question, FLIP THE QUESTION lifeline is activated and if the user ENTERS 'F' at any question, FIFTY-FIFTY lifeline is activated (More information about these lifelines and their working are discussed in the above sections of the README.txt file and also in the code's documentation).

11. Finally, if the user answers all the 15 questions correctly, YOU WON message is prompted on the screen before exiting.

>### NOTE:
>We have prepared this code to be comfortable while running in the terminal, use of any IDE may affect the final look on the screen. If the characters are not aligned properly, adjust the font-size of the terminal and RESTART. To change the font size-

>* If you are using the CLion Terminal -
 File → Settings → Editor → Colors & Fonts → Console Font.
 	Apply the size you want, quit the Terminal and re-open it.

>* If you are using the Linux Terminal (any Distro even Ubuntu)-
	Open Terminal → Right Click → Profiles → Profile Preferences → General Tab → Font.

>* If you are using Ubuntu Terminal (shortcut)-
	Open Terminal → Click on the Button having three parallel lines near the find Button on the top ribbon of the terminal → Magnifying option

>* If you are using CodeBlocks IDE-
	Settings → Environment → View → Message logs' font size"

>* If you are using Windows Command Prompt/PowerShell-
	Open the terminal → Right Click on the Title Bar of the terminal window → Properties → Font section → Font size
	
### TODOs
* Reading the questions from a text file in which there can any number of Questions/Answers.
* Randomly shuffling the option Sequence.
